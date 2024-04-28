#pragma once
#include <cmath>
#include <iostream>
#include <ostream>
class Vector
{
private:
    double x;
    double y;
    double Length;

public:
    Vector(double, double);// Vector konstruktora, x és y koordinátára van csak szüksége,, számolja a hosszt


    Vector(const Vector &); // Vector copykonstruktora, mert miért ne


    double getX() const;      // getter függvény az X-re
    double getY() const;      // getter függvény az Y-ra
    double getLength() const; // getter függvény az lenght-re

    void setX(double);              // setter függvény az X-re
    void setY(double);              // setter függvény az Y-ra
    void setVector(double, double); // későbbi könnyebbségért egy teljes setter

    double calculateLenght(); // Frissíti a Length értékét, vissza is adja szükség esetén

    // bool isNull() const; // Ellenőrzi, hogy nullvektor-e

    Vector operator-() const;               // Vektor ellentettét képezi
    Vector operator+(const Vector &) const;     // Vektorok összeadása
    Vector operator-(const Vector &) const;     // Vektorok kivonása
    double operator*(const Vector &) const; // Skaláris szorzat (dot product)
    void operator=(const Vector &);         // Vektorok egyenlővé tétele
    void operator+=(const Vector &);        // Értékadás vektorral

    // double operator[](int i) const;
};

Vector operator*(const Vector &, int); // Skalárral szorzás

std::ostream &operator<<(std::ostream &, Vector &); // vektor kiírása, azért nem const Vector &, mert frissíti a hosszát kiírás előtt