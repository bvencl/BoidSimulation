#include "cohesionrule.h"

CohesionRule::CohesionRule(double rule_strength) : Rule(rule_strength) {}

// Az egyes egyedekre ható Kohéziós összetevőt határozza meg a nyáj tömegközéppontja alapján
Vector CohesionRule::calculateRuleForIndividual(std::vector<BasicBoid> &flockMembers, const BasicBoid &boid) const
{
    Vector commonCenterOfMass;
    double sumOfMasses = 0.0;
    for (size_t i = 0; i < flockMembers.size(); i++) // Közös tömegközéppont kiszámítása
    {
        commonCenterOfMass = commonCenterOfMass + flockMembers[i].getPosition(); // Egyedek pozíciójának összeadása
        sumOfMasses += flockMembers[i].getMass();                                // Leosztás az egyedek össztömegével
    }

    Vector direction = (commonCenterOfMass - boid.getPosition()) * (1.0 / sumOfMasses); // Az irányt úgy kapjuk, hogy a Boid pozícióját kivonjuk a   

    double distance = direction.getLength();

    try
    {
        direction.normaliastion();
    }
    catch (std::runtime_error &rte)
    {
        std::cerr << rte.what() << '\n';
        return Vector::nullVector;
    }

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