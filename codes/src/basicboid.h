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
    BasicBoid(double, Point, Vector, Vector);
    // mass = 1, starting_position_x = 0, starting_position_y = 0, speed_x = 0, speed_y = 0, acceleration_x = 0, acceleration_y = 0
    BasicBoid(double mass = 1, double starting_position_x = 0, double starting_position_y = 0, double speed_x = 0, double speed_y = 0, double acceleration_x = 0, double acceleration_y = 0);

    Vector &getSpeed();
    Vector &getAcceleration();
    Point const &getPosition() const;
    double getMass() const;

    void setAcceleration(double, double);
    void setSpeed(double, double);
    void setSpeed(const Vector &);
    void setAcceleration(const Vector &);

    void accelerationToSpeed();

    void move();

    void MyTurn();
    bool operator==(const BasicBoid &) const;
};

std::ostream &operator<<(std::ostream &, const BasicBoid &);