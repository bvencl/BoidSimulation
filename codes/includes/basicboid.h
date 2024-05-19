#pragma once

#include "vector.h"
#include <iostream>
#include <ostream>
class BasicBoid
{
private:
    Vector speed;
    Vector acceleration;
    Vector currentPosition;
    double mass;

public:
    BasicBoid(double mass, Vector starting_position, Vector starting_speed, Vector starting_acceleration);
    BasicBoid(double mass = 1, double starting_position_x = 0, double starting_position_y = 0, double speed_x = 0, double speed_y = 0, double acceleration_x = 0, double acceleration_y = 0);

    Vector const &getSpeed() const;
    Vector const &getAcceleration() const;
    Vector const &getPosition() const;
    double getMass() const;

    void boidPrint(std::ostream &) const;

    void MyTurn(Vector, double);

    bool operator==(const BasicBoid &) const;
};

std::ostream &operator<<(std::ostream &, const BasicBoid &);