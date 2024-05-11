#include "chasingrule.h"

ChasingRule::ChasingRule(double rule_strength) : ruleStrength(rule_strength) {}

double ChasingRule::getRuleStrength() const
{
    return ruleStrength;
}

Vector ChasingRule::calculateRuleForIndividual(const BasicBoid &boid, sf::Vector2i mousePosition)
{
    Point target(mousePosition.x, mousePosition.y);
    double distance = target.calculateDistance(boid.getPosition());
    Vector direction = target - boid.getPosition();
    direction.normaliastion();

    Vector acceleration = direction * distance;

    if (boid.getSpeed() * direction < 0)
    {
        double correctionFactor = log(distance);
        acceleration = acceleration * correctionFactor;
    }

    // VICCES FEATURE - Érdekes jelenség, érdemes kipróbálni
    // if (boid.getSpeed() * direction > 0 && boid.getSpeed().getLength() > boid.getAcceleration().getLength())
    // {
    //     double correctionFactor = -distance;
    //     acceleration = acceleration * correctionFactor;
    // }

    return acceleration * ruleStrength;
}