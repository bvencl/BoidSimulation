#include "basicboid.h"

BasicBoid::BasicBoid() : speed(Vector(0, 0)), acceleration(Vector(0, 0)), currentPosition(Point(0, 0)), mass(0)
{
    if (DEBUG_IS_ON)
        std::cout << "Boid defconstructed: \n " << *this << std::endl;
}

// double mass, double speedx, double speedy, double accx, double accy, double srtposx, double strposy
BasicBoid::BasicBoid(double mass = 0.1, Vector startingSpeed = Vector(0, 0), Vector startingAcceleration = Vector(0, 0), Point startingPoint = Point(0, 0)) : speed(startingSpeed), acceleration(startingAcceleration), currentPosition(startingPoint), mass(mass)
{
    if (DEBUG_IS_ON)
        std::cout << "Boid constructed: \n " << *this << std::endl;
}

void BasicBoid::setSpeed(double x, double y)
{
    speed = Vector(x, y);
}

void BasicBoid::setSpeed(const Vector &other)
{
    double x = other.getX();
    double y = other.getY();
    speed.setX(x);
    speed.setY(y);
}

void BasicBoid::setAcceleration(double x, double y)
{
    acceleration = Vector(x, y);
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
       << "\tspeed: " << boid.getSpeed()
       << "\tacceleration: " << boid.getAcceleration()
        //    << "\thow fat I am: " << boid.getMass()
        ;

    return os;
}

void BasicBoid::accelerationToSpeed()
{
    speed += (acceleration * dT);
}

/*
Egy adott egyed egy "időpillanatra" viszonyított
gyorsulását, sebességét, mozgását és pozícióját számoló függvény.
Több függvényre bontom, és nem a mainben csinálom.
Sorrendiség:
    - Gyorsulás kiszámítása a 4 szabály alapján:
        - Először a Chasing összetevő: ez a legerősebb összetevő, az ott leírtakkal megeflelően számolom
        - Másodszor a Separation kerül számításra, ugyanis eza második legerősebb, számolása ott leírva
        - Harmadszor a Cohesion számolódik, szerintem ez lesz a harmadik legerősebb, számolása ott leírva
        - Negyedszer számolódik az Alignment, szerintem ez a legkevésbé fontos összetevő
    - Gyorsulás módosítása
    - Ebből sebesség számolás
    - Majd a Pozíció kiszámítása
*/
void BasicBoid::MyTurn()
{
    Vector calculatedSumOfRules(0, 0);

    acceleration += calculatedSumOfRules;

    accelerationToSpeed();
    move();
}

void BasicBoid::move()
{
    currentPosition.setPoint(currentPosition + (speed * dT));
}