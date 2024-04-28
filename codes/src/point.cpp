#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif

#include <iostream>
#include <ostream>
#include <cmath>
#include "point.h"

Point::Point(double x = 0, double y = 0) : x(x), y(y)
{
    if (DEBUG_IS_ON)
        std::cout << "Point constructed" << *this << std::endl;
}

Point::~Point()
{
    if(DEBUG_IS_ON)
        std::cout << "deconstructed point " << *this << std::endl;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::setX(double x)
{
    x = x;
}

void Point::setY(double y)
{
    y = y;
}

void Point::setPoint(double x, double y)
{
    x = x;
    y = y;
}

double Point::calculateDistance(const Point& other) const
{
    Point tmp = *this - other;
    return std::sqrt(tmp.x*tmp.x + tmp.y*tmp.y);
}

bool Point::operator==(const Point &rhs) const
{
    if (x == rhs.x && y == rhs.y)
        return true;
    return false;
}

Point Point::operator+(const Point &rhs) const
{
    return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Point &rhs) const
{
    return Point(x - rhs.x, y - rhs.y);
}

std::ostream &operator<<(std::ostream &os, const Point &P)
{
    os << "< x: " << P.getX() << ", y: " << P.getY();
    return os;
}

const Point Point::Origo(0.0, 0.0);