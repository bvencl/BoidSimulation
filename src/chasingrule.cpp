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
        // ha nulla hosszal osztanánk le, akkor úgyis nulla körüli gyorsulást adnánk vissza
        std::cerr << rte.what() << '\n';
        return Vector::nullVector;
    }

    Vector speedOfBoid = boid.getSpeed();

    // Alapesetben a gyorsulás megfelel az irányvektor és a távolság szoratának
    Vector acceleration = direction * distance;

    // Amennyiben az irány és a Boid sebességének skaláris szorzata negatív
    if (speedOfBoid * direction < 0) // Emiatt érzékelhetjük azt a "megrántás" szerű fékezését a Boidoknak, amikor túllőnek
    {
        acceleration = acceleration * breakingForce;
    }

    // Amennyiben a sebesség harmada nagyobb, mint a céltól való távolság, és a sebesség és irány skaláris szorzata nagyobb mint nulla
    if (speedOfBoid.getLength() / 3 > distance && direction * speedOfBoid > 0)
    {
        double correctionFactor = -breakingForce * speedOfBoid.getLength();          // Erős fékezés a sebességgel ellentétes irányba
        acceleration = direction.projectionOnto(boid.getSpeed()) * correctionFactor; // Vesszük az irányvektor vetületét a sebességre, majd megszorozzuk a correctionFactorral,
        /**/                                                                         // ami negatív, így a sebességgel ellentétes irányba fog mutatni a gyorsulás, azaz lassulunk
    }

    return acceleration * ruleStrength;
}