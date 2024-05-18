#include "flock.h"
#include "execution"

Flock::Flock(double flock_chasing_coefficient, double flock_repulsion, double flock_cohesion, double flock_alingment)
    : chase(flock_chasing_coefficient),
      separation(flock_repulsion),
      cohesion(flock_cohesion),
      alingment(flock_alingment)
{
}

void Flock::insert(BasicBoid boid)
{
    if (!isMemberOfFlock(boid))
    {
        flockMembers.push_back(boid);
    }
}

bool Flock::isMemberOfFlock(const BasicBoid &boid) const
{
    return std::find(flockMembers.begin(), flockMembers.end(), boid) != flockMembers.end();
}

void Flock::remove(const BasicBoid &boid)
{
    flockMembers.erase(std::remove(flockMembers.begin(), flockMembers.end(), boid), flockMembers.end());
}

void Flock::moveFlock(double dT, const sf::Vector2i &mousePosition)
{
    for (size_t i = 0; i < flockMembers.size(); i++)
    {
        Vector calculatedSumOfRules;
        calculatedSumOfRules += chase.calculateRuleForIndividual(flockMembers[i], mousePosition);
        calculatedSumOfRules += separation.calculateRuleForIndividual(flockMembers, flockMembers[i]);
        calculatedSumOfRules += cohesion.calculateRuleForIndividual(flockMembers, flockMembers[i]);
        calculatedSumOfRules += alingment.calculateRuleForIndividual(flockMembers, flockMembers[i]);

        flockMembers[i].MyTurn(calculatedSumOfRules, dT);
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

size_t Flock::flockSize() const
{
    return flockMembers.size();
}