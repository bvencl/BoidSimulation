#pragma once

/**
 * @file basicboid.h
 * @brief Ez a header fájl tárolja a BasicBoid osztály definícióját és metódusainak deklarációját.
 */

#include "vector.h"
#include <iostream>
#include <ostream>

/**
 * @class BasicBoid
 * @brief Az alapvető egyedeket reprezentáló osztály. Az osztály, ezzel az egyedek Craig Reynolds 1986-os "Boids" mesterséges élet projektje után kapta nevét.
 * Későbbi bővítés miatt kapta a "Basic" Boid nevet, ugyanis később több különféle,
 * más viselkedéseket mutató Boidot is hozzá lehetne majd adni a programhoz.
 */
class BasicBoid
{
private:
    Vector speed;           ///< A Boid adott időpillanatbeli sebességét reprezentáló vektor
    Vector acceleration;    ///< A Boid adott időpillanatbeli gyorsulását reprezentáló vektor
    Vector currentPosition; ///< A Boid adott időpillanatbeli pozícióját reprezentáló vektor
    double mass;            ///< A Boid tömegét, ezzel együtt méretét is meghatározó változó

public:
    /**
     * @brief Boid konstruktora, amelyet a kezdeti tesztelésnél könnyebbség kedvéért 1 double értéket és 3 vektort várt.
     * A végső implementációban ennek már nem nagyon van szerepe.
     * @param mass A Boid tömege.
     * @param starting_position A Boid kezdő pozíciója.
     * @param starting_speed A Boid kezdő sebessége.
     * @param starting_acceleration A Boid kezdő gyorsulása.
     */
    BasicBoid(double mass, Vector starting_position, Vector starting_speed, Vector starting_acceleration);

    /**
     * @brief A Boid osztály fő konstruktora, a program ezt használja Boidok létrehozására. Egyben default konstruktor is.
     * @param mass A Boid tömege (alapértelmezetten 1).
     * @param starting_position_x A kezdő pozíció x koordinátája (alapértelmezetten 0).
     * @param starting_position_y A kezdő pozíció y koordinátája (alapértelmezetten 0).
     * @param speed_x A kezdő sebesség x koordinátája (alapértelmezetten 0).
     * @param speed_y A kezdő sebesség y koordinátája (alapértelmezetten 0).
     * @param acceleration_x A kezdő gyorsulás x koordinátája (alapértelmezetten 0).
     * @param acceleration_y A kezdő gyorsulás y koordinátája (alapértelmezetten 0).
     */
    BasicBoid(double mass = 1, double starting_position_x = 0, double starting_position_y = 0, double speed_x = 0, double speed_y = 0, double acceleration_x = 0, double acceleration_y = 0);

    /**
     * @brief A Boid sebességét visszaadó függvény.
     * @return A Boid sebessége.
     */
    Vector const &getSpeed() const;

    /**
     * @brief A Boid gyorsulását visszaadó függvény.
     * @return A Boid gyorsulása.
     */
    Vector const &getAcceleration() const;

    /**
     * @brief A Boid pozícióját visszaadó függvény.
     * @return A Boid pozíciója.
     */
    Vector const &getPosition() const;

    /**
     * @brief A Boid tömegét (és ezzel méretét is) visszaadó függvény.
     * @return A Boid tömege.
     */
    double getMass() const;

    /**
     * @brief A Boidok pozícióját, sebességét és gyorsulását kiíró függvény, hibakeresésnél rendkívül hasznos lehet.
     * @param os Az ostream objektum, amelybe kiírjuk az aktuális Boid adatait.
     */
    void boidPrint(std::ostream &os) const;

    /**
     * @brief A Boidok mozgásáért felelős függvény. Ez frissíti és számolja a szabályok által szolgáltatott gyorsulás komponenssel a Boid gyorsulását, sebességét, majd pozícióját.
     * A moveFlock() függvény által szolgáltatott dT idővel működik.
     * @param acceleration Az új gyorsulás vektor.
     * @param dT Az eltelt idő.
     */
    void MyTurn(Vector acceleration, double dT);

    /**
     * @brief Boidok egyenlőségét vizsgáló függvény. A nyájban történő nyilvántartásuknál használatos leginkább.
     * @param other A másik Boid, amelyet összehasonlítunk az aktuális Boiddal.
     * @return True, ha a Boidok egyenlőek, különben false.
     */
    bool operator==(const BasicBoid &other) const;
};

/**
 * @brief A Boidok kiíratását megkönnyítő operátor.
 * @param os Az ostream objektum, amelybe kiírjuk a Boidot.
 * @param boid A Boid, amelyet kiírunk.
 * @return Az ostream objektum.
 */
std::ostream &operator<<(std::ostream &os, const BasicBoid &boid);

