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

    double scalingFactor = 0.0;

    if (distance < individual.getMass() / 2 + currentFlockMember.getMass() / 2 + 50) // Ha nagyon közel vannak egymáshoz- azért arányos a súlyukkal,
    {                                                                                // mert az ábrázolásnál a méretük (kör sugara) a súlyukkal egyezik meg
        scalingFactor = 500;
    }
    else if (distance > individual.getMass() / 2 + currentFlockMember.getMass() / 2 + 15 && distance < individual.getMass() / 2 + currentFlockMember.getMass() / 2 + 150) // Ha kicsit távolabb vannak azért
    {
        scalingFactor = 1.0 / (distance - (individual.getMass() + currentFlockMember.getMass()));
    }
    else if (distance > individual.getMass() / 2 + currentFlockMember.getMass() / 2 + 150 && direction.angleWith(individual.getSpeed()) > M_PI / 3)
    {
        scalingFactor = currentFlockMember.getMass() * individual.getMass() / (distance * distance);
    }

    return direction * getRuleStrength() * scalingFactor;
}

double SeparationRule::calculateScalingFactor(const BasicBoid &, double, double) const
{
    return 0;
}