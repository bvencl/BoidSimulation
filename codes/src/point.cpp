#include "point.h"

Point::Point(double x, double y) : x(x), y(y)
{
    if (DEBUG_IS_ON)
        std::cout << "Point constructed" << *this << std::endl;
}

Point::~Point()
{
    if (DEBUG_IS_ON)
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

const Point &Point::getPoint() const
{
    return *this;
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

void Point::setPoint(Point other)
{
    *this = other;
}

double Point::calculateDistance(const Point &other) const
{
    Point tmp = *this - other;
    return std::sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
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

Point Point::operator+(const Vector &vector) const
{
    return Point(x + vector.getX(), y + vector.getY());
}
void Point::operator=(const Point &other)
{
    x = other.x;
    y = other.y;
}

Point::operator sf::Vector2f() const
{
    return sf::Vector2f(x, y);
}

std::ostream &operator<<(std::ostream &os, const Point &P)
{
    os << "< x: " << P.getX() << ", y: " << P.getY();
    return os;
}

const Point Point::Origo(0.0, 0.0);