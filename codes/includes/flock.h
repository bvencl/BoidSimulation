#pragma once
#include "basicboid.h"
#include "rule.h"
#include "chasingrule.h"
#include "separationrule.h"
#include "cohesionrule.h"
// #include "alingmentrule.h"

class Flock
{
    BasicBoid **flockMembers;
    size_t flockSize;
    ChasingRule chase;
    SeparationRule separation;
    CohesionRule cohesion;
    // AlingmentRule alingment;

public:
    Flock(double flock_chasing_coefficient = 1, double flock_repulsion = 1, double flock_cohesion = 1, double flock_alingment = 1);
    ~Flock();
    void insert(BasicBoid *);
    void remove(BasicBoid *);
    void moveFlock(double, sf::Vector2i);
    bool isMemberOfFlock(const BasicBoid *);
    BasicBoid &operator[](int);
};
