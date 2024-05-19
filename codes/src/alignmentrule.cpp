#include "alignmentrule.h"

#define DESIREDDISTANCE 300.0
#define CORRECTIONFACTOR 10000.0

AlignmentRule::AlignmentRule(double rule_strength) : Rule(rule_strength) {}

// Az egyedekre ható Alignment Összetevő számolását elvégző függvény
Vector AlignmentRule::calculateRuleForIndividual(std::vector<BasicBoid> &flockMembers, const BasicBoid &boid) const
{
    Vector commonSpeedOfFlock(0.0, 0.0);
    double sumOfSpeed = 0.0;
    size_t affectingMembers = 0;
    if (boid.getSpeed().isNull() || boid.getAcceleration().isNull()) // Ez a kezdeti pozícióban érvényes, ilyenkor értelmetlen eredményt adna, viszont máskor nem kell vele foglalkozni
    {
        return Vector::nullVector;
    }
    for (size_t i = 0; i < flockMembers.size(); i++)
    {
        Vector direction = boid.getPosition() - flockMembers[i].getPosition(); // Irány meghatározása két vektor kivonásával
        double distance = direction.getLength();                               // A két vizsgált egyed távolsága. A szabály szükségességének eldöntéséhez kell
        // Akkor van Alignment komponens, ha: (nem saját magához viszonyítjuk az egyedet) ÉS (A jelenlegi egyed "látószögében" van a nyáj éppen vizsgált másik tagja,
        // tehát látja azt) ÉS (megadott távon belül vannak)
        if (!(flockMembers[i] == boid) && (/*direction.angleWith(boid.getSpeed()) < M_PI / 3 &&*/ distance < DESIREDDISTANCE)) // a látószög it most PI/3, tehát +- 60fok
        {
            commonSpeedOfFlock += flockMembers[i].getSpeed();     // Közös sebesség meghatározásához először összeadjuk a sebességeket
            sumOfSpeed += flockMembers[i].getSpeed().getLength(); // Azok hosszát is nyílvántartjuk
            affectingMembers++;                                   // megnöveljük az ehhez hozzájáruló egyedek számát
        }
    }

    double scalingFactor = calculateScalingFactor(boid, (double)affectingMembers, sumOfSpeed); // scalingFactor számítása
    return commonSpeedOfFlock * scalingFactor * getRuleStrength();                             // Végeredmény visszaadása
}

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