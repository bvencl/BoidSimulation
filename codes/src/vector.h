#pragma once
#include <iostream>
#include <ostream>
#include <cmath>
#include <iomanip>

class Vector
{
private:
    double x, y;

public:
    Vector();
    Vector(double, double); // Vector konstruktora, x és y koordinátára van csak szüksége,, számolja a hosszt
    Vector(const Vector &); // Vector copykonstruktora, mert miért ne
    ~Vector();
    double getX() const;      // getter függvény x-re
    double getY() const;      // getter függvény y-ra
    double getLength() const; // getter függvény length-re
    Vector const &getVector() const;
    void setX(double);              // setter függvény x-re
    void setY(double);              // setter függvény y-ra
    void setVector(double, double); // későbbi könnyebbségért egy teljes setter

    Vector rotate(double) const;                 // Forgat egy vektort megadott radiánnal, mintegy operátorként működve...                                                                                                       https://www.youtube.com/watch?v=YGXCnZMGa6M
    bool isNull();                               // Ellenőrzi, hogy nullvektor-e, azért nem const, mert frissíti a hosszt
    double angleWith(const Vector &) const;      // visszaadja a két vektor közötti szöget
    Vector projectionOnto(const Vector &) const; // A paraméter vektorra eső vetület vektort adja vissza

    Vector operator-() const;               // Vektor ellentettét képezi
    Vector operator+(const Vector &) const; // Vektorok összeadása
    Vector operator-(const Vector &) const; // Vektorok kivonása
    double operator*(const Vector &) const; // Skaláris szorzat (dot product)
    void operator=(const Vector &);         // Vektorok egyenlővé tétele
    void operator+=(const Vector &);        // Értékadás vektorral

    static const Vector xAxis;
    static const Vector yAxis;
};

Vector operator*(const Vector &, int); // Skalárral szorzás

std::ostream &operator<<(std::ostream &, const Vector &); // vektor kiírása, azért nem const Vector &, mert frissíti a hosszát kiírás előtt
