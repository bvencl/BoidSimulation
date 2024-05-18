#pragma once

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
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
    BasicBoid(double mass, Point starting_position, Vector starting_speed, Vector starting_acceleration);
    // mass = 1, starting_position_x = 0, starting_position_y = 0, speed_x = 0, speed_y = 0, acceleration_x = 0, acceleration_y = 0
    BasicBoid(double mass = 1, double starting_position_x = 0, double starting_position_y = 0, double speed_x = 0, double speed_y = 0, double acceleration_x = 0, double acceleration_y = 0);
    ~BasicBoid();
    Vector const &getSpeed() const;
    Vector const &getAcceleration() const;
    Point const &getPosition() const;
    double getMass() const;

    void boidPrint(std::ostream &) const;

    void setSpeed(double, double);
    void setSpeed(const Vector &);
    void setAcceleration(double, double);
    void setAcceleration(const Vector &);

    void MyTurn(Vector, double);

    bool operator==(const BasicBoid &) const;
};

std::ostream &operator<<(std::ostream &, const BasicBoid &);