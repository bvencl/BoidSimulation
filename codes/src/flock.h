#pragma once
#include "basicboid.h"

class Flock
{
    BasicBoid **flockMembers;
    size_t flockSize;
    double flockCohesion;
    double flockRepulsion;

public:
    Flock(double flock_cohesion = 1, double flock_repulsion = 1);
    ~Flock();
    void insert(BasicBoid *);
    void remove(BasicBoid *);
    void moveFlock();
    bool isMemberOfFlock(const BasicBoid *);
    BasicBoid &operator[](int);
};
