#pragma once
#include "vector.h"
#include "point.h"
#include <iostream>
#define REPELLING_FORCE 1.0
#ifndef dT
#define dT 1e-6
#endif

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
    void move();
};

std::ostream &operator<<(std::ostream &, const BasicBoid &);