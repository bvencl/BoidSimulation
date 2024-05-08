#include "flock.h"

Flock::Flock(double flock_cohesion, double flock_repulsion) : flockMembers(nullptr), flockSize(0), flockCohesion(flock_cohesion), flockRepulsion(flock_repulsion) {}

Flock::~Flock()
{
    if (flockSize == 0)
        flockMembers = nullptr;
    delete[] flockMembers;
    flockSize = 0;
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

void Flock::moveFlock()
{
    for (size_t i = 0; i < flockSize; i++)
        (*flockMembers[i]).MyTurn();
}

BasicBoid &Flock::operator[](int i)
{
    return *flockMembers[i];
}