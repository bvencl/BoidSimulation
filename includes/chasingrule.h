#pragma once

/**
 * @file chasingrule.h
 * @brief Ez a header fájl tárolja a Chasing ("Üldözés") szabály definícióját és metódusainak deklarálását.
 */

#include "basicboid.h"
#include <SFML/Graphics.hpp>

/**
 * @class ChasingRule
 * @brief Az az osztály, amely a Chasing ("Üldözés") szabályt valósítja meg. 
 *        Erre a szabályra fektettem a legnagyobb hangsúlyt, ugyanis ez a leglátványosabb a szabályok közül.
 * 
 * Ez az osztály azért nem származik a Rule osztályból, mert ez nem az egyes Boidok között hat, így nagyon másak a metódusai, és nagyon nehezen lehetett volna abból származtatni.
 */
class ChasingRule
{
private:
    double ruleStrength; ///< A szabály erősségét befolyásoló változó.

public:
    /**
     * @brief A szabály konstruktora.
     * @param rule_strength A szabály erőssége (alapértelmezetten 1).
     */
    ChasingRule(double rule_strength = 1);

    /**
     * @brief Ez a függvény számolja a szabály által szolgáltatott gyorsulás komponenst a Boidok mozgásához.
     * @param individual Az egyed, amelyre éppen a komponenst számolni kell.
     * @param mousePosition Az egér pozíciója az ablakhoz képest.
     * @return A szabály által számolt gyorsulás komponens.
     */
    Vector calculateRuleForIndividual(const BasicBoid &individual, const sf::Vector2i &mousePosition);

    /**
     * @brief A szabály erősségét visszaadó függvény.
     * @return A szabály erőssége.
     */
    double getRuleStrength() const;
};
