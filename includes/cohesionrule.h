#pragma once

/**
 * @file cohesion.h
 * @brief A Cohesion ("Kohézió") szabály osztályának definíciója és metódusainak deklarációja.
 */

#include "rule.h"

/**
 * @class CohesionRule
 * @brief Az osztály, amely a Cohesion ("Kohézió") szabályt valósítja meg.
 *
 * A CohesionRule osztály a Rule absztrakt osztályból származik, és annak sablon paramétereként használja a CRTP (Curiously Recurring Template Pattern) mintát.
 */
class CohesionRule : public Rule<CohesionRule>
{
public:
    /**
     * @brief Az osztály konstruktora.
     * @param rule_strength A szabály erőssége (alapértelmezetten 1).
     */
    CohesionRule(double rule_strength = 1);

    /**
     * @brief Ezen osztály calculateRuleForIndividual sablon függvényének implementációja.
     * Az egyedekre ható kohéziós összetevő számolását elvégző függvény.
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
     * @brief A két boid közötti szabályerősség számolására szolgáló függvény.
     * @param boid1 Az első boid.
     * @param boid2 A második boid.
     * @return A számolt szabályerősség az egyedek között.
     */
    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &boid1, const BasicBoid &boid2) const override;

    /**
     * @brief Ez a függvény számolja ki a szabály adott pillanatbeli erősségének nagyságát (a szabály által szolgáltatott komponens-vektor hosszát).
     * @param boid Az aktuális boid.
     * @param distance Az egyed és a tömegközéppont távolsága.
     * @param sumOfMasses Az egyedek össztömege.
     * @return A számolt skálázó faktor.
     */
    double calculateScalingFactor(const BasicBoid &boid, double distance, double sumOfMasses) const override;
};

template <typename Iterator>
Vector CohesionRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector commonCenterOfMass;
    double sumOfMasses = 0.0;

    for (Iterator It = begin; It != end; ++It) // Közös tömegközéppont kiszámítása.
    {
        commonCenterOfMass = commonCenterOfMass + It->getPosition(); // Egyedek pozíciójának összeadása.
        sumOfMasses += It->getMass();                                // Leosztás az egyedek össztömegével.
    }

    Vector direction = (commonCenterOfMass - boid.getPosition()) * (1.0 / sumOfMasses); // Az irány meghatározása.

    double distance = direction.getLength(); // Az egyed és a tömegközéppont távolsága.

    try
    {
        direction.normaliastion(); // Az irányvektor normalizálása.
    }
    catch (std::runtime_error &rte)
    {
        std::cerr << rte.what() << '\n';
        return Vector::nullVector; // Ha hiba történik, visszatérünk egy nullvektorral.
    }

    return direction * calculateScalingFactor(boid, distance, sumOfMasses); // Visszaadjuk a számolt gyorsulást.
}
