#include "alingmentrule.h"

AlingmentRule::AlingmentRule(double rule_strength) : Rule(rule_strength) {}

Vector AlingmentRule::calculateRuleForIndividual(std::vector<BasicBoid *> flockMembers, const BasicBoid &boid) const
{
    Vector commonSpeedOfFlock(0, 0);
    double sumOfSpeed = 0.0;
    size_t affectingMembers = 0;
    if (boid.getSpeed().isNull() || boid.getAcceleration().isNull())
    {
        return Vector::nullVector;
    }
    for (size_t i = 0; i < flockMembers.size(); i++)
    {
        Vector direction = boid.getPosition() - flockMembers[i]->getPosition();
        double distance = direction.getLength();
        if (!(*flockMembers[i] == boid) && (direction.angleWith(boid.getSpeed()) < M_PI / 3 && distance < 300.0))
        {
            commonSpeedOfFlock += flockMembers[i]->getSpeed();
            sumOfSpeed += flockMembers[i]->getSpeed().getLength();
            affectingMembers++;
        }
    }

    double scalingFactor = calculateScalingFactor(boid, (double)affectingMembers, sumOfSpeed);

    return commonSpeedOfFlock * scalingFactor;
}

Vector AlingmentRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    return Vector::nullVector;
}

double AlingmentRule::calculateScalingFactor(const BasicBoid &boid, double affectingMembers, double sumOfSpeed) const
{
    if (affectingMembers == 0)
        return 0;
    return getRuleStrength() * sumOfSpeed / (affectingMembers * 10000);
}