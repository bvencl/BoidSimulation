#include "basicboid.h"

BasicBoid::BasicBoid(double mass, double starting_position_x, double starting_position_y, double speed_x, double speed_y, double acceleration_x, double acceleration_y)
    : speed(speed_x, speed_y),
      acceleration(acceleration_x, acceleration_y),
      currentPosition(starting_position_x, starting_position_y),
      mass(mass)
{
}

BasicBoid::BasicBoid(double mass, Vector starting_position, Vector starting_speed, Vector starting_acceleration)
    : speed(starting_speed),
      acceleration(starting_acceleration),
      currentPosition(starting_position),
      mass(mass)
{
}

Vector const &BasicBoid::getSpeed() const
{
    return speed;
}

Vector const &BasicBoid::getAcceleration() const
{
    return acceleration;
}

Vector const &BasicBoid::getPosition() const
{
    return currentPosition;
}

double BasicBoid::getMass() const
{
    return mass;
}

void BasicBoid::boidPrint(std::ostream &os) const
{
    os << "    CP: " << getPosition()
       << "    SP: " << getSpeed()
       << "    ACC: " << getAcceleration();
}

std::ostream &operator<<(std::ostream &os, BasicBoid const &boid)
{
    boid.boidPrint(os);
    return os;
}

void BasicBoid::MyTurn(Vector calculatedSumOfRules, double dT)
{
    acceleration = calculatedSumOfRules;
    speed += (acceleration * dT);
    currentPosition += speed * dT;
}

bool BasicBoid::operator==(const BasicBoid &other) const
{
    return this == &other;
}