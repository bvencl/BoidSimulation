#pragma once
#include "vector.h"
#include "point.h"
#include <iostream>
#define REPELLING_FORCE 1.0

class BasicBoid
{
private:
    Vector speed;
    Vector acceleration;
    Point currentPosition;
    double mass;

public:
    BasicBoid(double);
    Vector const &getSpeed() const;
    Vector const &getAcceleration() const;
    Point const &getPosition() const;
    double getMass() const;
};

std::ostream &operator<<(std::ostream &, const BasicBoid &);