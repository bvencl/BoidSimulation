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

    Vector acceleration = direction * distance;

    if (boid.getSpeed() * direction < 0)
    {
        double correctionFactor = 20;
        acceleration = acceleration * correctionFactor;
    }

    if (boid.getSpeed().getLength() / 5 > distance && direction * boid.getSpeed() > 0)
    {
        double timeEstamation = distance / boid.getSpeed().getLength();
        double correctionFactor = -30 * boid.getSpeed().getLength();
        if (!direction.projectionOnto(boid.getSpeed()).isNull() && abs(correctionFactor) > 1e-6)
            acceleration = direction.projectionOnto(boid.getSpeed()) * correctionFactor;
    }

    return acceleration * ruleStrength;
}