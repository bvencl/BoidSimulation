#include "alignmentrule.h"

AlignmentRule::AlignmentRule(double rule_strength) : Rule(rule_strength) {}

Vector AlignmentRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    return Vector::nullVector;
}

double AlignmentRule::calculateScalingFactor(const BasicBoid &boid, double affectingMembers, double sumOfSpeed) const
{
    if (affectingMembers == 0)
        return 0;
    // A sebsségek összes hossza / (A befolyásoló egyedek száma * empirikus correction factor)
    return sumOfSpeed / (affectingMembers * CORRECTIONFACTOR);
}