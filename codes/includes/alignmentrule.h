#pragma once
#include "rule.h"

#define DESIREDDISTANCE 300.0
#define CORRECTIONFACTOR 10000.0
class AlignmentRule : public Rule<AlignmentRule>
{

public:
    AlignmentRule(double rule_strength = 1);

    template <typename Iterator>
    Vector calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &) const;

private:
    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    double calculateScalingFactor(const BasicBoid &, double, double) const override;
};

// Az egyedekre ható Alignment Összetevő számolását elvégző függvény
template <typename Iterator>
Vector AlignmentRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector commonSpeedOfFlock(0.0, 0.0);
    double sumOfSpeed = 0.0;
    size_t affectingMembers = 0;
    if (boid.getSpeed().isNull() || boid.getAcceleration().isNull()) // Ez a kezdeti pozícióban érvényes, ilyenkor értelmetlen eredményt adna, viszont máskor nem kell vele foglalkozni
    {
        return Vector::nullVector;
    }
    for (Iterator It = begin; It != end; It++)
    {
        Vector direction = boid.getPosition() - It->getPosition(); // Irány meghatározása két vektor kivonásával
        double distance = direction.getLength();                    // A két vizsgált egyed távolsága. A szabály szükségességének eldöntéséhez kell
        // Akkor van Alignment komponens, ha: (nem saját magához viszonyítjuk az egyedet) ÉS (A jelenlegi egyed "látószögében" van a nyáj éppen vizsgált másik tagja,
        // tehát látja azt) ÉS (megadott távon belül vannak)
        if (!(*It == boid) && (/*direction.angleWith(boid.getSpeed()) < M_PI / 3 &&*/ distance < DESIREDDISTANCE)) // a látószög it most PI/3, tehát +- 60fok
        {
            commonSpeedOfFlock += It->getSpeed();     // Közös sebesség meghatározásához először összeadjuk a sebességeket
            sumOfSpeed += It->getSpeed().getLength(); // Azok hosszát is nyílvántartjuk
            affectingMembers++;                        // megnöveljük az ehhez hozzájáruló egyedek számát
        }
    }

    double scalingFactor = calculateScalingFactor(boid, (double)affectingMembers, sumOfSpeed); // scalingFactor számítása
    return commonSpeedOfFlock * scalingFactor * getRuleStrength();                             // Végeredmény visszaadása
}