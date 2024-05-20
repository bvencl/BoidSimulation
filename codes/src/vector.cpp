#include "vector.h"

//---------------------------------------------------------Konstruktorok Destruktorok
Vector::Vector(double x, double y) : x(x), y(y){};

Vector::Vector(const sf::Vector2i &other)
{
    x = other.x;
    y = other.y;
}

//--------------------------------------------------------Getter-Setter függvények---------------------------------------------------------------

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
    return std::sqrt(x * x + y * y);
}

void Vector::setX(double x)
{
    this->x = x;
}

void Vector::setY(double y)
{
    this->y = y;
}

//--------------------------------------------Számoló függvények-----------------------------------------------------------------------------------

Vector Vector::rotate(double thetaInRadians) const
{
    double cosTheta = std::cos(thetaInRadians);
    double sinTheta = std::sin(thetaInRadians);
    return Vector(x * cosTheta - y * sinTheta, x * sinTheta + y * cosTheta);
}

bool Vector::isNull() const
{
    if (std::abs(getLength()) < 1e-6)
        return true;
    return false;
}

double Vector::angleWith(const Vector &other) const
{
    double dotProduct = *this * other;
    double dotLength = getLength() * other.getLength();
    return std::acos(dotProduct / dotLength);
}

Vector Vector::projectionOnto(const Vector &onto) const
{
    double dotProduct = *this * onto;
    double lengthSquared = onto.getLength() * onto.getLength();
    return onto * (dotProduct / lengthSquared);
}

void Vector::normaliastion()
{
    if (getLength() == 0) // egyes szabályok számolásánál előfordulhat, hogy nullával kellene osztani
        throw std::runtime_error("Normalization failed, dividing by zero");
    x /= getLength();
    y /= getLength();
}

//----------------------------------------Túlterhelt operátorok-------------------------------

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
}

bool Vector::operator==(const Vector &rhs) const
{
    return x == rhs.x && y == rhs.y;
}

double Vector::operator*(const Vector &rhs) const
{
    return x * rhs.x + y * rhs.y;
}

void Vector::operator+=(const Vector &rhs)
{
    x += rhs.x;
    y += rhs.y;
}

void Vector::vectorPrint(std::ostream &os) const
{
    os << "< x: " << std::setprecision(6) << std::fixed << getX()
       << " y: " << std::setprecision(6) << std::fixed << getY()
       << " Length: " << std::setprecision(6) << std::fixed << getLength();
}

std::ostream &operator<<(std::ostream &os, const Vector &vec)
{
    vec.vectorPrint(os);
    return os;
}

Vector operator*(const Vector &vec, double lambda)
{
    return Vector(vec.getX() * lambda, vec.getY() * lambda);
}

Vector::operator sf::Vector2f() const
{
    return sf::Vector2f(x, y);
}

const Vector Vector::nullVector(0, 0);
