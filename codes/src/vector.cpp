#include "vector.h"

ZS::ZS(double x, double y) : x(x), y(y)
{
    Length = std::sqrt(x * x + y * y);
    if (DEGUG_IS_ON)
        std::cout << " vector constructed" << *this;
}

ZS::ZS(const ZS &other)
{
    x = other.x;
    y = other.y;
    calculateLenght();
    if (DEGUG_IS_ON)
        std::cout << "copyconstructed a vector" << *this << std::endl;
}

double ZS::getX() const
{
    return x;
}

double ZS::getY() const
{
    return y;
}

double ZS::getLength() const
{
    return Length;
}

void ZS::setX(double x)
{
    x = x;
}

void ZS::setY(double y)
{
    y = y;
}

void ZS::setVector(double x, double y)
{
    x = x;
    y = y;
}

double ZS::calculateLenght()
{
    Length = std::sqrt(x * x + y * y);
    return Length;
}

ZS ZS::operator-() const
{
    return ZS(-x, -y);
}

ZS ZS::operator+(const ZS &rhs) const
{
    return ZS(x + rhs.x, y + rhs.y);
}

ZS ZS::operator-(const ZS &rhs) const
{
    return ZS(x - rhs.x, y - rhs.y);
}

void ZS::operator=(const ZS &rhs)
{
    x = rhs.x;
    y = rhs.y;
    calculateLenght();
}

void ZS::operator+=(const ZS &rhs)
{
    x += rhs.x;
    y = rhs.y;
    calculateLenght();
}

double ZS::operator*(const ZS &rhs) const
{
    return x * rhs.x + y * rhs.y;
}

std::ostream &operator<<(std::ostream &os, ZS &vec)
{
    os << "VECTOR , x: " << vec.getX() << " y: " << vec.getY() << " lenght: " << vec.calculateLenght() << std::endl;
    return os;
}
