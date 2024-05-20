#pragma once

/**
 * @file rule.h
 * @brief Az absztrakt sablon osztály definícióját, és metódusainak definícióit, illetve deklarációit tartalmazó header fájl.
 */

#include "basicboid.h"
#include <SFML/Graphics.hpp>

/**
 * @class Rule
 * @brief Absztrakt sablon osztály, CRTP (Curiously Recurring Template Pattern) alapján, a szabály-osztályok őse.
 *        Közös interfészt szolgáltat a szabály-osztályoknak.
 * 
 * @tparam Derived Az éppen megvalósított származtatott osztály.
 */
template <class Derived>
class Rule
{
private:
    double ruleStrength; ///< A szabály erősségét meghatározó változó.

public:
    /**
     * @brief A szabály-osztály konstruktora.
     * @param rule_strength A szabály erőssége.
     */
    Rule(double rule_strength) : ruleStrength(rule_strength) {}

    /**
     * @brief Getter függvény a szabály erősségének lekérdezéséhez.
     * @return A szabály erőssége.
     */
    double getRuleStrength() const { return ruleStrength; }

    /**
     * @brief Azon függvény, amely meghívja az utódosztályok implementált "calculateRuleForIndividualImpl" függvényét.
     * @tparam Iterator A boidok konténerének iterátora.
     * @param begin A boidok konténerének eleje.
     * @param end A boidok konténerének vége.
     * @param individual Az aktuális egyed.
     * @return A szabály által számolt gyorsulás komponens.
     */
    template <typename Iterator>
    Vector calculateRuleForIndividual(Iterator begin, Iterator end, const BasicBoid &individual) const
    {
        return static_cast<const Derived *>(this)->calculateRuleForIndividualImpl(begin, end, individual);
    }

    /**
     * @brief A két boid közötti szabályerősség számolására szolgáló virtuális függvény.
     * @param boid1 Az első boid.
     * @param boid2 A második boid.
     * @return A számolt szabályerősség az egyedek között.
     */
    virtual Vector calculateRuleStrengthBetweenBoids(const BasicBoid &boid1, const BasicBoid &boid2) const = 0;

    /**
     * @brief Az olyan szabályoknál használt virtuális függvény, ahol van értelme külön egyedek közötti erőt számolni.
     * @param boid Az aktuális boid.
     * @param factor1 Az első faktor.
     * @param factor2 A második faktor.
     * @return A számolt skálázó faktor.
     */
    virtual double calculateScalingFactor(const BasicBoid &boid, double factor1, double factor2) const = 0;
};
