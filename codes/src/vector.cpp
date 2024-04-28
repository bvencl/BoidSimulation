#include "vector.h"

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

void ZS::operator+=(const ZS & rhs)
{
    x += rhs.x;
    y = rhs.y;
    calculateLenght();
}

double ZS::operator*(const ZS &rhs) const
{
    return x * rhs.x + y * rhs.y;
}
