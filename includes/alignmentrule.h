#pragma once

#include "rule.h"

/**
 * @file alignmentrule.h
 * @brief Az Alignment szabályt leíró osztályt és annak egy metódusának definícióját is tartalmazó header fájl.
 *
 */

#define DESIRED_DISTANCE 300.0
#define CORRECTION_FACTOR 10000.0

/**
 * @class AlignmentRule
 * @brief Az osztály, amely az Alignment ("Igazítás") szabályt valósítja meg.
 *
 * Az AlignmentRule osztály a Rule absztrakt osztályból származik, és annak sablon paramétereként használja a CRTP (Curiously Recurring Template Pattern) mintát.
 */
class AlignmentRule : public Rule<AlignmentRule>
{
public:
    /**
     * @brief Az osztály konstruktora.
     * @param rule_strength A szabály erőssége (alapértelmezetten 1).
     */
    AlignmentRule(double rule_strength = 1);

    /**
     * @brief Ezen osztály calculateRuleForIndividual sablon függvényének implementációja.
     * Az egyedekre ható Alignment összetevő számolását elvégző függvény.
     *
     * Azért lett a header fájlban implementálva, mert a CRTP minta megköveteli, hogy a származtatott osztály metódusai elérhetőek legyenek a fordítási időben.
     *
     * @tparam Iterator A boidok konténerének iterátora.
     * @param begin A boidok konténerének eleje.
     * @param end A boidok konténerének vége.
     * @param boid Az aktuális boid.
     * @return A szabály által számolt gyorsulás komponens.
     */
    template <typename Iterator>
    Vector calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const;

private:
    /**
     * @brief Privát metódusok, amelyeket a calculateRuleForIndividualImpl függvény hív.
     *
     * Ezek a metódusok a szabály különböző aspektusainak számításához szükségesek.
     */

    /**
     * @brief Erre a függvényre nincsen szükség, de mivel származtatott, így muszáj definíciót adni neki.
     * @param boid1 Az első boid.
     * @param boid2 A második boid.
     * @return  nullVector, mivel ennek a metódusnak nincs szerepe ebben az osztályban.
     */
    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &boid1, const BasicBoid &boid2) const override;

    /**
     * @brief Ez a függvény számolja ki a szabály adott pillanatbeli erősségének nagyságát (a szabály által szolgáltatott komponens-vektor hosszát).
     * @param boid Az aktuális boid.
     * @param affectingMembers A ható egyedek száma.
     * @param sumOfSpeed Az egyedek sebességeinek összege.
     * @return A számolt skálázó faktor.
     */
    double calculateScalingFactor(const BasicBoid &boid, double affectingMembers, double sumOfSpeed) const override;
};

template <typename Iterator>
Vector AlignmentRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector commonSpeedOfFlock(0.0, 0.0); // Az egyedek közös sebessége.
    double sumOfSpeed = 0.0;             // Az egyedek sebességeinek összege.
    size_t affectingMembers = 0;         // A ható egyedek száma.

    // a kezdeti pillanatot szűrj, akkor nincsen értelmezve ez a szabály
    if (boid.getSpeed().isNull() || boid.getAcceleration().isNull()) // Ha az egyed sebessége vagy gyorsulása nulla, nincs értelme számolni.
    {
        return Vector::nullVector;
    }

    for (Iterator It = begin; It != end; ++It)
    {
        Vector direction = boid.getPosition() - It->getPosition(); // Irány meghatározása két vektor kivonásával.
        double distance = direction.getLength();                   // A két vizsgált egyed távolsága. A szabály szükségességének eldöntéséhez kell.

        if (!(*It == boid) && distance < DESIRED_DISTANCE) // Ha az vizsgált potenciális szomszéd az egyedtől megadott távolságon belül van.
        {
            commonSpeedOfFlock += It->getSpeed();     // Közös sebesség meghatározásához először összeadjuk a sebességeket.
            sumOfSpeed += It->getSpeed().getLength(); // Azok hosszát is nyilvántartjuk.
            affectingMembers++;                       // Megnöveljük az ehhez hozzájáruló egyedek számát.
        }
    }

    double scalingFactor = calculateScalingFactor(boid, affectingMembers, sumOfSpeed); // Skálázó faktor számítása.
    return commonSpeedOfFlock * scalingFactor * getRuleStrength();                     // Végeredmény visszaadása.
}
