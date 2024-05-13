#include "basicboid.h"

BasicBoid::BasicBoid(double mass, double starting_position_x, double starting_position_y, double speed_x, double speed_y, double acceleration_x, double acceleration_y)
    : speed(speed_x, speed_y),
      acceleration(acceleration_x, acceleration_y),
      currentPosition(starting_position_x, starting_position_y),
      mass(mass)
{
    if (DEBUG_IS_ON)
        std::cout << "Boid constructed: \n " << *this << std::endl;
}

BasicBoid::BasicBoid(double mass, Point starting_position, Vector starting_speed, Vector starting_acceleration)
    : speed(starting_speed),
      acceleration(starting_acceleration),
      currentPosition(starting_position),
      mass(mass)
{
    if (DEBUG_IS_ON)
        std::cout << "Boid constructed: \n " << *this << std::endl;
}

BasicBoid::~BasicBoid()
{
    if (DEBUG_IS_ON)
    {
        std::cout << "BasicBoid deconstructed" << std::endl;
    }
}

void BasicBoid::setSpeed(double x, double y)
{
    speed.setX(x);
    speed.setY(y);
}

void BasicBoid::setSpeed(const Vector &other)
{
    speed.setVector(other);
}

void BasicBoid::setAcceleration(double x, double y)
{
    if (Vector(x, y).getLength() < 20)
    {
        acceleration.setX(x);
        acceleration.setY(y);
    }
}

void BasicBoid::setAcceleration(const Vector &other)
{
    if (other.getLength() < 20)
        acceleration.setVector(other);
}

Vector const &BasicBoid::getSpeed() const
{
    return speed.getVector();
}

Vector const &BasicBoid::getAcceleration() const
{
    return acceleration.getVector();
}

Point const &BasicBoid::getPosition() const
{
    return currentPosition.getPoint();
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
    currentPosition.setPoint(currentPosition + (speed * dT));
}

bool BasicBoid::operator==(const BasicBoid &other) const
{
    return this == &other;
}