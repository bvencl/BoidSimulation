#pragma once

/**
 * @file separationrule.h
 * @brief A Separation ("Szeparáció") szabály osztályának definíciója, illetve egyes metódusainak deklarációja és definíciója.
 */

#include "rule.h"
#define DESIRED_MINIMAL_DISTANCE 150.0
#define EMPIRIC_SCALING_VALUE 500.0

/**
 * @class SeparationRule
 * @brief Az osztály, amely a Separation ("Szeparáció") szabályt valósítja meg.
 *
 * A SeparationRule osztály a Rule absztrakt osztályból származik, és annak sablon paramétereként használja a CRTP (Curiously Recurring Template Pattern) mintát.
 */
class SeparationRule : public Rule<SeparationRule>
{
public:
    /**
     * @brief Az osztály konstruktora.
     * @param rule_strength A szabály erőssége (alapértelmezetten 1).
     */
    SeparationRule(double rule_strength = 1);

    /**
     * @brief Ezen osztály calculateRuleForIndividual sablon függvényének implementációja.
     * Az egyedekre ható szeparációs összetevő számolását elvégző függvény.
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
     * @brief Ennek a függvénynek ennél az osztálynál nincsen szerepe.
     * @param boid Az aktuális boid.
     * @param factor1 Az első faktor.
     * @param factor2 A második faktor.
     * @return Mindig 0.
     */
    double calculateScalingFactor(const BasicBoid &boid, double factor1, double factor2) const override;
};

template <typename Iterator>
Vector SeparationRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector sumOfSeparationInFlock(0, 0); // Az egyedre ható szeparációs komponens.

    for (Iterator It = begin; It != end; ++It) // Iterátorok használatával végigmegyünk a tárolón.
    {
        if (!(*It == boid)) // Amennyiben ugyanaz az egyed, amit vizsgálunk, akkor átugorjuk, ugyanis magától nem tud távolodni.
        {
            sumOfSeparationInFlock += calculateRuleStrengthBetweenBoids(*It, boid); // Összegezzük a közvetlen szomszédok által az egyedre ható "erőket".
        }
    }
    return sumOfSeparationInFlock; // Visszaadjuk a számolt gyorsulást.
}
