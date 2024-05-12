#include "chasingrule.h"

ChasingRule::ChasingRule(double rule_strength) : ruleStrength(rule_strength) {}

double ChasingRule::getRuleStrength() const
{
    return ruleStrength;
}

Vector ChasingRule::calculateRuleForIndividual(const BasicBoid &boid, const sf::Vector2i &mousePosition)
{
    Point target(mousePosition.x, mousePosition.y);
    double distance = target.calculateDistance(boid.getPosition());
    Vector direction = target - boid.getPosition();
    direction.normaliastion();

    // Dinamikus gyorsulási skálázás a távolság függvényében
    double scalingFactor = distance;

    Vector acceleration = direction * distance;

    if (boid.getSpeed() * direction < 0)
    {
        double correctionFactor = 30;
        acceleration = acceleration * correctionFactor;
    }
    if (boid.getSpeed().getLength() > distance)
        ;
    // VICCES FEATURE - Érdekes jelenség, érdemes kipróbálni
    // if (boid.getSpeed() * direction > 0 && boid.getSpeed().getLength() > boid.getAcceleration().getLength())
    // {
    //     double correctionFactor = -distance;
    //     acceleration = acceleration * correctionFactor;
    // }

    return acceleration * ruleStrength;
}