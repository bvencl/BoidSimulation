#pragma once

// basicboid.h
// ez a header fájl tárolja a BasicBoid osztály definícióját és metódusainak deklarációját

#include "vector.h"
#include <iostream>
#include <ostream>

// Az alapvető egyedeket reprezentáló osztály. Az osztály, ezzel az egyedek Craig Reynolds 1986-os "Boids" mesterséges élet projektje után kapta nevét.
// Későbbi bővítés miatt kapta a "Basic" Boid nevet, ugyanis később több különféle,
// más viszelkedéseket mutató Boidot is hozzá lehetne majd adni a programhoz.
class BasicBoid
{
private:
    Vector speed;           // A Boid adott időpillanatbeli sebességét reprezentáló vektor
    Vector acceleration;    // A Boid adott időpillanatbeli gyorsulását reprezentáló vektor
    Vector currentPosition; // A Boid adott időpillanatbeli pozícióját reprezentáló vektor
    double mass;            // A Boid tömegét, ezzel együtt méretét is meghatározó változó

public:
    // Boid konstruktora, amelyet a kzedeti tesztelésnél könnyebbség kedvéért 1 double értéket és 3 vektort várt. A végső implementációban ennek már nem nagyon van szerepe
    BasicBoid(double mass, Vector starting_position, Vector starting_speed, Vector starting_acceleration);
    // A Boid osztály fő konstruktora, a program ezt használja Boidok létrehozására. Egyben default kontruktor is
    BasicBoid(double mass = 1, double starting_position_x = 0, double starting_position_y = 0, double speed_x = 0, double speed_y = 0, double acceleration_x = 0, double acceleration_y = 0);

    // A Boid sebességét visszaadó függvény

    Vector const &getSpeed() const;

    // A Boid gyorsulását visszaadó függvény
    Vector const &getAcceleration() const;

    // A Boid pozícióját visszaadó függvény
    Vector const &getPosition() const;

    // A Boid tömegét (és ezzel méretét is) visszaadó függvény
    double getMass() const;

    // A Boidok pozícióját, sebességét és gyorsulását kiíró függény, hibakeresésnél rendkívül hasznos lehet
    void boidPrint(std::ostream &) const;

    // A Boidok mozgásáért felelős függvény. Ez frissíti és számolja a szabályok által szolgáltatott gyorsulás komponenssel a Boid gyorsulását, sebességét, majd pozícióját
    // A moveFlock() függvény által szoolgáltatott dT idővel működik.
    void MyTurn(Vector, double);

    // Boidok egyenlőségét vizsgáló függvény. A nyájban történő nyílvántartásuknál használatos leginkább
    bool operator==(const BasicBoid &) const;
};

// A Boidok kiíratását megkönnyítő operátor
std::ostream &operator<<(std::ostream &, const BasicBoid &);