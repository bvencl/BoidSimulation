#pragma once
#include "basicboid.h"

class Flock
{
    BasicBoid *flockMembers;
    size_t flockSize;
    double flockCohesion;
    double flockRepulsion;

public:
    Flock(double, double);
    ~Flock();
    void insert(const BasicBoid &);
    void remove(const BasicBoid &);
    void moveFlock();
    bool isMemberOfFlack(const BasicBoid&);
};
