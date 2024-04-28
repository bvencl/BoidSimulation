#pragma once
#include <ostream>
#include <iostream>

class Point
{
private:
    double x;
    double y;
public:
    Point(double, double);

    double getX() const;
    double getY() const;

    void setX(double);
    void setY(double);

    void setPoint(double, double);

    double calculateDistance( const Point&) const;
    bool operator==(const Point &) const;
    Point operator+(const Point &) const;
    Point operator-(const Point &) const; 

    static const Point Origo;
};

std::ostream & operator<<(std::ostream &, const Point&);