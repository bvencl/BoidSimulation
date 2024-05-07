#include "flock.h"

Flock::Flock(double flock_cohesion = 1, double flock_repulsion) : flockMembers(nullptr), flockSize(0), flockCohesion(flock_cohesion), flockRepulsion(flock_repulsion) {}

Flock::~Flock()
{
    delete[] flockMembers;
    flockSize = 0;
}

void Flock::insert(const BasicBoid &boid)
{
    BasicBoid *tmp = new BasicBoid[flockSize + 1];
    for (size_t i = 0; i < flockSize; i++)
    {
        tmp[i] = flockMembers[i];
    }
    tmp[flockSize] = boid;
    delete[] flockMembers;
    flockMembers = tmp;
    flockSize++;
}

void Flock::remove(const BasicBoid &boid)
{
    if (flockSize == 0 || !isMemberOfFlack(boid))
    {
        throw 69;
    }
    else if (flockSize == 1)
    {
        this->~Flock();
        return;
    }
    BasicBoid *tmp = new BasicBoid[flockSize - 1];
    for (size_t i = 0; i < flockSize - 1; i++)
    {
        if (&(flockMembers[i]) != &(boid))
            tmp[i] = flockMembers[i];
    }
    
}