#include "chasingrule.h"

#define breakingForce 30.0

ChasingRule::ChasingRule(double rule_strength) : ruleStrength(rule_strength) {}

double ChasingRule::getRuleStrength() const
{
    return ruleStrength;
}

Vector ChasingRule::calculateRuleForIndividual(const BasicBoid &boid, const sf::Vector2i &mousePosition)
{
    Vector target(mousePosition.x, mousePosition.y);
    Vector direction = target - boid.getPosition();
    double distance = direction.getLength();

    try
    {
        direction.normaliastion();
    }
    catch (std::runtime_error &rte)
    {
        std::cerr << rte.what() << '\n';
        return Vector::nullVector;
    }

    Vector acceleration = direction * distance;

    // if (boid.getSpeed().getLength() > distance && distance < 300)
    // {

    //     double correctionFactor = -breakingForce * boid.getSpeed().getLength();                    // Erős fékezés a sebességgel ellentétes irányba
    //     if ((!direction.projectionOnto(boid.getSpeed()).isNull()) && abs(correctionFactor) > 1e-6) // Amennyiben a sebesség nem null, és a correctionFactor sem közel nulla:
    //         acceleration = direction.projectionOnto(boid.getSpeed()) * correctionFactor;           // Vesszük a gyorsulás vetületés a sebességre, majd megszorozzuk a correctionFactorral,
    // }

    // Amennyiben az irány és a Boid sebességének skaláris szorzata
    if (boid.getSpeed() * direction < 0) // Ezért van az a furcsa hirtelen fékezés hatás
    {
        double correctionFactor = breakingForce;
        acceleration = acceleration * correctionFactor;
    }

    // Amennyiben a sebesség ötöde nagyobb, mint a céltól való távolság, és a sebesség és irány skaláris szorzata kisebb mint nulla
    if (boid.getSpeed().getLength() / 5 > distance && direction * boid.getSpeed() > 0)
    {
        double correctionFactor = -breakingForce * boid.getSpeed().getLength();                    // Erős fékezés a sebességgel ellentétes irányba
        if ((!direction.projectionOnto(boid.getSpeed()).isNull()) && abs(correctionFactor) > 1e-6) // Amennyiben a sebesség nem null, és a correctionFactor sem közel nulla:
            acceleration = direction.projectionOnto(boid.getSpeed()) * correctionFactor;           // Vesszük a gyorsulás vetületés a sebességre, majd megszorozzuk a correctionFactorral,
                                                                                                   // ami negatív, így a sebességgel ellentétes irányba fog mutatni a gyorsulás
    }

    return acceleration * ruleStrength;
}