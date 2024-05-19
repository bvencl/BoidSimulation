#pragma once
#include "rule.h"

class CohesionRule : public Rule<CohesionRule>
{

public:
    CohesionRule(double rule_strength = 1);

    template <typename Iterator>
    Vector calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &) const;

private:
    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    double calculateScalingFactor(const BasicBoid &, double, double) const override;
};

// Az egyes egyedekre ható Kohéziós összetevőt határozza meg a nyáj tömegközéppontja alapján
template <typename Iterator>
Vector CohesionRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector commonCenterOfMass;
    double sumOfMasses = 0.0;
    for (Iterator It = begin; It != end; It++) // Közös tömegközéppont kiszámítása
    {
        commonCenterOfMass = commonCenterOfMass + It->getPosition(); // Egyedek pozíciójának összeadása
        sumOfMasses += It->getMass();                                // Leosztás az egyedek össztömegével
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