#include "flock.h"

Flock::Flock(double flock_chasing_coefficient, double flock_repulsion, double flock_cohesion, double flock_alingment)
    : flockMembers(nullptr),
      flockSize(0),
      chase(flock_chasing_coefficient),
      separation(flock_repulsion),
      cohesion(flock_cohesion),
      alingment(flock_alingment)
{
}

Flock::~Flock()
{
    if (flockSize == 0)
        flockMembers = nullptr;
    delete[] flockMembers;
    flockSize = 0;
    if(DEBUG_IS_ON)
    {
        std::cout << "Flock deconstructed" << std::endl;
    }
}

void Flock::insert(BasicBoid *boid)
{
    if (!isMemberOfFlock(boid))
    {
        BasicBoid **tmp = new BasicBoid *[flockSize + 1];
        for (size_t i = 0; i < flockSize; i++)
        {
            tmp[i] = flockMembers[i];
        }
        tmp[flockSize] = boid;
        delete[] flockMembers;
        flockMembers = tmp;
        flockSize++;
    }
}

void Flock::remove(BasicBoid *boid)
{
    if (flockSize == 0 || !isMemberOfFlock(boid))
    {
        throw 69;
    }
    else if (flockSize == 1)
    {
        this->~Flock();
        return;
    }
    BasicBoid **tmp = new BasicBoid *[flockSize - 1];
    for (size_t i = 0; i < flockSize - 1; i++)
    {
        if (!(*flockMembers[i] == *boid))
            tmp[i] = flockMembers[i];
    }
}

bool Flock::isMemberOfFlock(const BasicBoid *boid)
{
    for (size_t i = 0; i < flockSize; i++)
    {
        if (*boid == *(flockMembers[i]))
            return true;
    }
    return false;
}

void Flock::moveFlock(double dT,const sf::Vector2i & mousePosition)
{
    for (size_t i = 0; i < flockSize; i++)
    {
        Vector calculatedSumOfRules;
        calculatedSumOfRules += chase.calculateRuleForIndividual(*flockMembers[i], mousePosition);
        calculatedSumOfRules += separation.calculateRuleForIndividual(flockMembers, *flockMembers[i], flockSize);
        calculatedSumOfRules += cohesion.calculateRuleForIndividual(flockMembers, *flockMembers[i], flockSize);
        calculatedSumOfRules += alingment.calculateRuleForIndividual(flockMembers, *flockMembers[i], flockSize);
        
        (*flockMembers[i]).MyTurn(calculatedSumOfRules, dT);
    }
}

BasicBoid &Flock::operator[](int i)
{
    return *flockMembers[i];
}