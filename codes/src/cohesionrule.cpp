#include "cohesionrule.h"

CohesionRule::CohesionRule(double rule_strength) : Rule(rule_strength) {}

Vector CohesionRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    return Vector::nullVector;
}

double CohesionRule::calculateScalingFactor(const BasicBoid &boid, double distance, double massOfTheFlack) const
{
    return getRuleStrength() * distance;
}