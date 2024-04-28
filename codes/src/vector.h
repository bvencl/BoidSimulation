#pragma once
#include <cmath>
#include <iostream>
#include <ostream>


class ZS
{
private:
    double x;
    double y;
    double Length;

public:
    ZS(double x, double y) : x(x), y(y) // Vector konstruktora, x és y koordinátára van csak szüksége,, számolja a hosszt
    {
        calculateLenght();
        // Length = std::sqrt(x * x + y * y);
    }

    ZS(const ZS &other) // Vector copykonstruktora, mert miért ne
    {
        x = other.x;
        y = other.y;
        calculateLenght;
        std::cout << "copyconstructed a vector" << std::endl;
    }

    double getX() const;      // getter függvény az X-re
    double getY() const;      // getter függvény az Y-ra
    double getLength() const; // getter függvény az lenght-re

    void setX(double); // setter függvény az X-re
    void setY(double); // setter függvény az Y-ra

    void setVector(double, double); // későbbi könnyebbségért egy teljes setter

    double calculateLenght(); // Frissíti a Length értékét, vissza is adja szükség esetén

    ZS operator-() const; // Vektor ellentettét képezi

    ZS operator+(const ZS &) const;     // Vektorok összeadása
    ZS operator-(const ZS &) const;     // Vektorok kivonása
    void operator=(const ZS &);         // Vektorok egyenlővé tétele
    void operator+=(const ZS &);        // Értékadás vektorral
    double operator*(const ZS &) const; // Skaláris szorzat (dot product)

    // double operator[](int i) const; 
};

ZS operator*(const ZS &vec, int lambda) // Skalárral szorzás
{
    return ZS(vec.getX() * lambda, vec.getY() * lambda);
}