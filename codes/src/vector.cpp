#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif

#include "vector.h"

Vector::Vector(double x, double y) : x(x), y(y)
{
    Length = std::sqrt(x * x + y * y);
    if (DEBUG_IS_ON)
        std::cout << " vector constructed" << *this;
}

Vector::Vector(const Vector &other)
{
    x = other.x;
    y = other.y;
    calculateLenght();
    if (DEBUG_IS_ON)
        std::cout << "copyconstructed a vector" << *this << std::endl;
}

double Vector::getX() const
{
    return x;
}

double Vector::getY() const
{
    return y;
}

double Vector::getLength() const
{
    return Length;
}

void Vector::setX(double x)
{
    x = x;
}

void Vector::setY(double y)
{
    y = y;
}

void Vector::setVector(double x, double y)
{
    x = x;
    y = y;
}

double Vector::calculateLenght()
{
    Length = std::sqrt(x * x + y * y);
    return Length;
}

Vector Vector::operator-() const
{
    return Vector(-x, -y);
}

Vector Vector::operator+(const Vector &rhs) const
{
    return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator-(const Vector &rhs) const
{
    return Vector(x - rhs.x, y - rhs.y);
}

void Vector::operator=(const Vector &rhs)
{
    x = rhs.x;
    y = rhs.y;
    calculateLenght();
}

void Vector::operator+=(const Vector &rhs)
{
    x += rhs.x;
    y = rhs.y;
    calculateLenght();
}

double Vector::operator*(const Vector &rhs) const
{
    return x * rhs.x + y * rhs.y;
}

std::ostream &operator<<(std::ostream &os, Vector &vec)
{
    os << "VECTOR , x: " << vec.getX() << " y: " << vec.getY() << " lenght: " << vec.calculateLenght() << std::endl;
    return os;
}

Vector operator*(const Vector &vec, int lambda)
{
    return Vector(vec.getX() * lambda, vec.getY() * lambda);
}