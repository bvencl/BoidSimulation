#pragma once

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif
#ifndef dT
#define dT 1e-2
#endif

#include <iostream>
#include <ostream>
#include "point.h"

class BasicBoid
{
private:
    Vector speed;
    Vector acceleration;
    Point currentPosition;
    double mass;

public:
    BasicBoid();
    BasicBoid(double, Vector, Vector, Point);

    Vector const &getSpeed() const;
    Vector const &getAcceleration() const;
    Point const &getPosition() const;
    double getMass() const;

    void setAcceleration(double, double);
    void setSpeed(double, double);
    void setSpeed(const Vector &);

    void accelerationToSpeed();

    void move();

    void MyTurn();
};

std::ostream &operator<<(std::ostream &, const BasicBoid &);