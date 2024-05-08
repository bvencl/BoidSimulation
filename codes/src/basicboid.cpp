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

void BasicBoid::setAcceleration(const Vector &other)
{
    double x = other.getX();
    double y = other.getY();
    acceleration.setX(x);
    acceleration.setY(y);
}

Vector &BasicBoid::getSpeed()
{
    return speed.getVectorNonConst();
}

Vector &BasicBoid::getAcceleration()
{
    return acceleration.getVectorNonConst();
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
    os << "    CP: " << boid.getPosition()
       << "    SP: " << const_cast<BasicBoid &>(boid).getSpeed()
       << "    ACC: " << const_cast<BasicBoid &>(boid).getAcceleration()
        //    << "\thow fat I am: " << boid.getMass()
        ;
    if (DEBUG_IS_ON)
        os << "\t" << &boid;

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

    /*
    ...
    */

    acceleration += calculatedSumOfRules;

    accelerationToSpeed();
    move();
}

void BasicBoid::move()
{
    currentPosition.setPoint(currentPosition + (speed * dT));
}

bool BasicBoid::operator==(const BasicBoid &other) const
{
    return currentPosition == other.currentPosition && mass == other.mass && speed == other.speed && acceleration == other.acceleration;
}