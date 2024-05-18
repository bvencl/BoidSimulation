#pragma once
#include "basicboid.h"
#include "rule.h"
#include "chasingrule.h"
#include "separationrule.h"
#include "cohesionrule.h"
#include "alignmentrule.h"
#include <memory>
#include <vector>

class Flock
{
    std::vector<BasicBoid> flockMembers;
    ChasingRule chase;
    SeparationRule separation;
    CohesionRule cohesion;
    AlignmentRule alingment;

public:
    Flock(double flock_chasing_coefficient = 1, double flock_repulsion = 1, double flock_cohesion = 1, double flock_alingment = 1);
    void insert(BasicBoid);
    void remove(const BasicBoid &);
    void moveFlock(double, const sf::Vector2i &);
    bool isMemberOfFlock(const BasicBoid &) const;
    BasicBoid &operator[](size_t);
    size_t flockSize() const;
};
