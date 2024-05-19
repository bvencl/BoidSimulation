#include "flock.h"
#include "execution"

Flock::Flock(double flock_chasing_coefficient, double flock_repulsion, double flock_cohesion, double flock_alingment)
    : chase(flock_chasing_coefficient),
      separation(flock_repulsion),
      cohesion(flock_cohesion),
      alignment(flock_alingment)
{
}

/*
Csak akkor adjuk hozzá az új boidot a nyájhoz, amennyiben az nem tagja annak. Reálisan nehezen fordulhat elő olyan eshetőség,
hogy létezzen olyan boid, amely nem tagja a nyájnak jelenlegi kompozícióra alapozó implementáció szerint,
de talán kikerülhetünk vele egy pár hibát a jövőben
*/
void Flock::insert(BasicBoid boid)
{
    if (!isMemberOfFlock(boid))
    {
        flockMembers.push_back(boid);
    }
}
// Az std::find függvény végigmegy a vectoron, majd amennyiben megtalálja a keresett értéket azt adja vissza. Amennyiben a keresett érték nincsen a vectorban, az end iterátort adja vissza
bool Flock::isMemberOfFlock(const BasicBoid &boid) const
{
    return std::find(flockMembers.begin(), flockMembers.end(), boid) != flockMembers.end();
}

/*
Az std:: remove függvény először úgy rendezi a vectort, hogy az elejére kerüljenek a nem eltávolítandó elemek, és a végére kerüljenek az
eltávolítandóak. Ez után visszaad egy iterátort a vector új végére, és ezt használja fel az std::erase függvény, amely ténylegesen eltávolítja
az eltávolítandó Boidot a vectorból. Amennyiben olyat távolítanánk el, ami nincs is benne, azt csendesen kezelik a remove és erase függvények,
nem módosítják a vectort.
*/
void Flock::remove(const BasicBoid &boid)
{
    flockMembers.erase(std::remove(flockMembers.begin(), flockMembers.end(), boid), flockMembers.end());
}

void Flock::moveFlock(double dT, const sf::Vector2i &mousePosition)
{
    for (size_t i = 0; i < flockMembers.size(); i++)
    {
        Vector calculatedSumOfRules;                                                                  // Vektor, ami a szabályok ezen időlépés alatti hatását gyűjti
        calculatedSumOfRules += chase.calculateRuleForIndividual(flockMembers[i], mousePosition);     // Chase szabály egyedre vett számolása
        calculatedSumOfRules += separation.calculateRuleForIndividual(flockMembers, flockMembers[i]); // Separation szabály egyedre vett számolása
        calculatedSumOfRules += cohesion.calculateRuleForIndividual(flockMembers, flockMembers[i]);   // Cohesion szabály egyedre vett számolása
        calculatedSumOfRules += alignment.calculateRuleForIndividual(flockMembers, flockMembers[i]);  // Alignment szabály egyedre vett számolása

        flockMembers[i].MyTurn(calculatedSumOfRules, dT); // A Boid gyorsulását felülíró, sebességét és pozícióját ez alapján változtató függvény
    }
}

BasicBoid &Flock::operator[](size_t i)
{
    if (i >= flockMembers.size())
    {
        throw std::out_of_range("Index out of range in Flock::operator[]: " + std::to_string(i));
    }
    return flockMembers[i];
}

BasicBoid const &Flock::operator[](size_t i) const
{
    if (i >= flockMembers.size())
    {
        throw std::out_of_range("Index out of range in Flock::operator[] const: " + std::to_string(i));
    }
    return flockMembers[i];
}

size_t Flock::flockSize() const
{
    return flockMembers.size();
}