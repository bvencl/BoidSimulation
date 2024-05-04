#include "basicboid.h"
#include "vector.h"
#include "point.h"
#include <ostream>
#define REPELLING_FORCE 1.0

BasicBoid::BasicBoid(double mass = 0.1) : speed(Vector()), acceleration(Vector()), currentPosition(Point()), mass(mass)
{
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

Point const & BasicBoid::getPosition() const
{
    return currentPosition.getPoint();
}

double BasicBoid::getMass() const
{
    return mass;
}

std::ostream &operator<<(std::ostream &os, BasicBoid const &boid)
{
    os << "Current position: " << boid.getPosition()
       << " speed: " << boid.getSpeed()
       << " acceleration: " << boid.getAcceleration()
       << " how fat I am: " << boid.getMass();

    return os;
}