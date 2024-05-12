#include "separationrule.h"

SeparationRule::SeparationRule(double rule_strength) : Rule(rule_strength) {}

Vector SeparationRule::calculateRuleForIndividual(BasicBoid **flockMembers, const BasicBoid &boid, size_t flockSize) const
{
    Vector sumOfSeparationInFlock(0, 0);

    for (size_t i = 0; i < flockSize; i++)
    {
        if (!(*flockMembers[i] == boid))
        {
            sumOfSeparationInFlock += calculateRuleStrengthBetweenBoids(*flockMembers[i], boid);
        }
    }
    return sumOfSeparationInFlock;
}

Vector SeparationRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    Vector direction = individual.getPosition() - currentFlockMember.getPosition();
    double distance = direction.getLength();
    direction.normaliastion();
    double scalingFactor = currentFlockMember.getMass() * individual.getMass() / (distance);
    if (scalingFactor > 200)
        scalingFactor = 200;
    return direction * getRuleStrength() * scalingFactor;
}