#include "flock.h"

Flock::Flock(double flock_chasing_coefficient, double flock_repulsion, double flock_cohesion, double flock_alingment)
    : // flockMembers(nullptr),
      // flockSize(0),
      chase(flock_chasing_coefficient),
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
        // calculatedSumOfRules += separation.calculateRuleForIndividual(flockMembers, *boid);
        // calculatedSumOfRules += cohesion.calculateRuleForIndividual(flockMembers, *boid);
        // calculatedSumOfRules += alingment.calculateRuleForIndividual(flockMembers, *boid);

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

// void Flock::remove(BasicBoid *boid)
// {
//     if (flockSize == 0 || !isMemberOfFlock(boid))
//         throw std::runtime_error("Boid not found or flock is empty.");

//     if (flockSize == 1)
//     {
//         if (flockMembers != nullptr)
//         {
//             delete[] flockMembers;
//             flockMembers = nullptr;
//         }
//         flockMembers = nullptr;
//         flockSize = 0;
//         return;
//     }

//     BasicBoid **tmp = new BasicBoid *[flockSize - 1];
//     size_t index = 0;
//     for (size_t i = 0; i < flockSize; i++)
//     {
//         if (flockMembers[i] != boid)
//         {
//             tmp[index++] = flockMembers[i];
//         }
//     }
//     if (flockMembers != nullptr)
//     {
//         delete[] flockMembers;
//         flockMembers = nullptr;
//     }
//     flockMembers = tmp;
//     flockSize--;
// }

// bool Flock::isMemberOfFlock(const BasicBoid *boid)
// {
//     for (size_t i = 0; i < flockSize; i++)
//     {
//         if (*boid == *(flockMembers[i]))
//             return true;
//     }
//     return false;
// }

// void Flock::moveFlock(double dT, const sf::Vector2i &mousePosition)
// {
//     for (size_t i = 0; i < flockSize; i++)
//     {
//         Vector calculatedSumOfRules;
//         calculatedSumOfRules += chase.calculateRuleForIndividual(*flockMembers[i], mousePosition);
//         calculatedSumOfRules += separation.calculateRuleForIndividual(flockMembers, *flockMembers[i], flockSize);
//         calculatedSumOfRules += cohesion.calculateRuleForIndividual(flockMembers, *flockMembers[i], flockSize);
//         calculatedSumOfRules += alingment.calculateRuleForIndividual(flockMembers, *flockMembers[i], flockSize);

//         (*flockMembers[i]).MyTurn(calculatedSumOfRules, dT);
//     }
// }
