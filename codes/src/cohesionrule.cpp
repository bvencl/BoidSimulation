#include "cohesionrule.h"

CohesionRule::CohesionRule(double rule_strength) : Rule(rule_strength) {}

Vector CohesionRule::calculateRuleForIndividual(std::vector<BasicBoid *> flockMembers, const BasicBoid &boid) const
{
    Point commonCenterOfMass(0.0, 0.0);
    double sumOfMasses = 0.0;
    for (size_t i = 0; i < flockMembers.size(); i++)
    {
        commonCenterOfMass = commonCenterOfMass + flockMembers[i]->getPosition();
        sumOfMasses += flockMembers[i]->getMass();
    }
    Vector direction = (commonCenterOfMass - boid.getPosition()) * (1.0 / sumOfMasses);

    double distance = direction.getLength();
    direction.normaliastion();

    return direction * calculateScalingFactor(boid, distance, sumOfMasses);
}

Vector CohesionRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    return Vector::nullVector;
}

double CohesionRule::calculateScalingFactor(const BasicBoid &boid, double distance, double massOfTheFlack) const
{
    return getRuleStrength() * distance;
}