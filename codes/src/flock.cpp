#include "flock.h"

Flock::Flock(double flock_chasing_coefficient, double flock_repulsion, double flock_cohesion, double flock_alingment)
    : chase(flock_chasing_coefficient),
      separation(flock_repulsion),
      cohesion(flock_cohesion),
      alingment(flock_alingment)
{
}

void Flock::insert(BasicBoid *boid)
{
    if (!isMemberOfFlock(boid))
    {
        flockMembers.push_back(boid);
    }
}

bool Flock::isMemberOfFlock(const BasicBoid *boid) const
{
    return std::find(flockMembers.begin(), flockMembers.end(), boid) != flockMembers.end();
}

void Flock::remove(const BasicBoid *boid)
{
    flockMembers.erase(std::remove(flockMembers.begin(), flockMembers.end(), boid), flockMembers.end());
}

void Flock::moveFlock(double dT, const sf::Vector2i &mousePosition)
{
    for (BasicBoid *boid : flockMembers)
    {
        Vector calculatedSumOfRules;
        calculatedSumOfRules += chase.calculateRuleForIndividual(*boid, mousePosition);
        calculatedSumOfRules += separation.calculateRuleForIndividual(flockMembers, *boid);
        calculatedSumOfRules += cohesion.calculateRuleForIndividual(flockMembers, *boid);
        calculatedSumOfRules += alingment.calculateRuleForIndividual(flockMembers, *boid);

        boid->MyTurn(calculatedSumOfRules, dT);
    }
}

BasicBoid &Flock::operator[](size_t i)
{
    if (i >= flockMembers.size())
    {
        throw std::out_of_range("Mondj kisebbet");
    }
    return *flockMembers[i];
}