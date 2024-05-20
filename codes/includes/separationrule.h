#pragma once

// separationrule.h
// A Separation ("Szeparáció") szabály osztályának definíciója, illetve egyes metódusainak deklarációja, illetve definíciója.

#include "rule.h"
// Az osztály, amely a Separation ("Szeparáció") szabályt valósítja meg.
class SeparationRule : public Rule<SeparationRule>
{

public:
    // Az osztály konstruktora
    SeparationRule(double rule_strength = 1);

    // Ezen osztály calculateRuleForInividual sablon függvényének implementációja.
    // Az egyedekre ható Separation összetevő számolását elvégző függvény
    template <typename Iterator>
    Vector calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &) const;

private:
    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    // Ennek a függvénynek ennél az osztálynál nincsen szerepe
    double calculateScalingFactor(const BasicBoid &, double, double) const override;
};

// Ezen osztály calculateRuleForInividual sablon függvényének implementációja.
//  Az egyedekre ható Alignment összetevő számolását elvégző függvény
// Azért lett a header fájlban implementálva, mert a fordításkor elérhetőnek kell lennie a CRTP miatt
template <typename Iterator> // Azért lett sablonosítva a függvény, hogy működjön std::vectorban, illetve std::listben tárolt Boidokra is
Vector SeparationRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector sumOfSeparationInFlock(0, 0); // Az egyedre ható szeparációs komponens

    for (Iterator It = begin; It != end; It++) // Iterátorok használatával végigmegyünk a tárolón
    {
        if (!(*It == boid)) // Amennyiben ugyan az az egyed, amit vizsgálunk, akkor átugorjuk, ugyanis magától nem tud távolodni (vicces lenne)
        {
            sumOfSeparationInFlock += calculateRuleStrengthBetweenBoids(*It, boid); // összegezzük a közvetlen szomszédok által az egyedre ható "erőket"
        }
    }
    return sumOfSeparationInFlock; // Visszaadjuk a számolt gyorsulást
}