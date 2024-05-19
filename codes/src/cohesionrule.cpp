#include "cohesionrule.h"

CohesionRule::CohesionRule(double rule_strength) : Rule(rule_strength) {}

// Az egyes egyedekre ható Kohéziós összetevőt határozza meg a nyáj tömegközéppontja alapján
template <typename Iterator>
Vector CohesionRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector commonCenterOfMass;
    double sumOfMasses = 0.0;
    for (Iterator It = begin; It != end; It++) // Közös tömegközéppont kiszámítása
    {
        commonCenterOfMass = commonCenterOfMass + *It->getPosition(); // Egyedek pozíciójának összeadása
        sumOfMasses += *It->getMass();                                // Leosztás az egyedek össztömegével
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