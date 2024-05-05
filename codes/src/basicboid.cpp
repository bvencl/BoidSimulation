#include "basicboid.h"
#include "vector.h"
#include "point.h"
#include <ostream>
#define REPELLING_FORCE 1.0
#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif
#ifndef dT
#define dT 1e-6
#endif

BasicBoid::BasicBoid(double mass = 0.1) : speed(Vector()), acceleration(Vector()), currentPosition(Point()), mass(mass)
{
    if (DEBUG_IS_ON)
        std::cout << "Boid constructed: \n " << *this << std::endl;
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

std::ostream &operator<<(std::ostream &os, BasicBoid const &boid)
{
    os << "\tCurrent position: " << boid.getPosition()
       << "\n \tspeed: " << boid.getSpeed()
       << "\n \tacceleration: " << boid.getAcceleration()
       << "\thow fat I am: " << boid.getMass();

    return os;
}

void BasicBoid::move()
{
    currentPosition + (speed * (1.0 / (double)dT));
}