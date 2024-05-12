#pragma once

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif

#include <ostream>
#include <iostream>
#include <cmath>
#include "vector.h"
#include <SFML/System/Vector2.hpp>

class Point
{
private:
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0);
    ~Point();
    double getX() const;
    double getY() const;
    Point const &getPoint() const;
    void setX(double);
    void setY(double);

    void setPoint(double, double);
    void setPoint(Point);
    double calculateDistance(const Point &) const;
    bool operator==(const Point &) const;
    Point operator+(const Point &) const;
    Vector operator-(const Point &) const;
    Point operator+(const Vector &) const;
    void operator=(const Point &);
    operator Vector() const;
    operator sf::Vector2f() const;
    static const Point Origo;
};

std::ostream &operator<<(std::ostream &, const Point &);