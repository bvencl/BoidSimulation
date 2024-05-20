#pragma once

// chasingrule.h
// Ez a header file tárolja a Chasing ("Üldözés") szabály definícióját és metódusainak deklarálását

#include "basicboid.h"
// Az az osztály, amely a Chasing ("Üldözés") szabályt valósítja meg. Erre a szabályra fektettem a legnagyobb hangsújt, ugyanis ez a leg látványosabb a szabályook közül
// Ez az osztály azért nem származik a Rule osztályból, ugyanis ez nem az egyes Boidok között hat, így nagyon másak a metódusai, és nagyon nehezen lehetett volna abból származtatni
class ChasingRule
{
private:
    // A szabály erősségét befolyásoló változó
    double ruleStrength;

public:
    // A szabály konstruktora
    ChasingRule(double rule_strength = 1);

    // Ez a függvény számloja a szabály által szolgáltatott gyorsulás komponenst a Boidok mozgásához.
    // Megkapja az egyedet, amelyre éppen a komponenst számolni kell, és az egér pozícióját az ablakhoz képest
    Vector calculateRuleForIndividual(const BasicBoid &, const sf::Vector2i &);

    // A szabály erőősségét visszaadó függvény
    double getRuleStrength() const;
};