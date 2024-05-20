#include "cohesionrule.h"

CohesionRule::CohesionRule(double rule_strength) : Rule(rule_strength) {}

// Ezen szabály szempontjából nem lényeges ez a függvény, ugyanakkor a közös ősből való származtatás végett implementálni kellett.
Vector CohesionRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    return Vector::nullVector;
}

// Megintcsak nem lényeges ez a függvény az osztály szempontjából, de a közös ősből való származtatás végett implementálni kellett.
double CohesionRule::calculateScalingFactor(const BasicBoid &boid, double distance, double massOfTheFlack) const
{
    return getRuleStrength() * distance;
}