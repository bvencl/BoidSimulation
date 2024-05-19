#pragma once

#include <stdexcept>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <cmath>
#include <SFML/System/Vector2.hpp>

/**
 * @brief Az osztály, amely egy kétdimenziós vektort reprezentál. Vektorműveletekhez használom ezt az osztályt, nem pedig tárolóként, mint az std::vectort
 */
class Vector
{
private:
    double x, y;

public:
    /**
     * @brief Vector osztály konstruktora.
     * @param x Az x koordináta (alapértelmezetten 0.0).
     * @param y Az y koordináta (alapértelmezetten 0.0).
     */
    Vector(double x = 0.0, double y = 0.0);

    /**
     * @brief Vector osztály konstruktora egy sf::Vector2i objektumból.
     * @param other Az sf::Vector2i objektum, amelyből inicializáljuk a Vector objektumot.
     */
    Vector(const sf::Vector2i &other);

    /**
     * @brief Getter függvény az x koordinátához.
     * @return Az x koordináta.
     */
    double getX() const;

    /**
     * @brief Getter függvény az y koordinátához.
     * @return Az y koordináta.
     */
    double getY() const;

    /**
     * @brief Getter függvény a vektor hosszához.
     * @return A vektor hossza.
     */
    double getLength() const;

    /**
     * @brief Setter függvény az x koordinátához.
     * @param x Az új x koordináta.
     */
    void setX(double x);

    /**
     * @brief Setter függvény az y koordinátához.
     * @param y Az új y koordináta.
     */
    void setY(double y);

    /**
     * @brief Egy vektort elforgat a megadott radiánnal.
     * @param angle A forgatás szöge radiánban.
     * @return Az elforgatott vektor.
     */
    Vector rotate(double angle) const;

    /**
     * @brief Ellenőrzi, hogy a vektor nullvektor-e.
     * @return True, ha a vektor nullvektor, különben false.
     */
    bool isNull() const;

    /**
     * @brief Kiszámítja a két vektor közötti szöget.
     * @param other A másik vektor, amellyel a szöget számítjuk.
     * @return A két vektor közötti szög radiánban.
     */
    double angleWith(const Vector &other) const;

    /**
     * @brief Kiszámítja a vektor vetületét a paraméter vektorra.
     * @param other A vektor, amelyre vetítjük az aktuális vektort.
     * @return A vetület vektora.
     */
    Vector projectionOnto(const Vector &other) const;

    /**
     * @brief Normálja az aktuális vektort egységnyi hosszúságra.
     */
    void normaliastion();

    /**
     * @brief Képezi az aktuális vektor ellentettjét.
     * @return Az ellentett vektor.
     */
    Vector operator-() const;

    /**
     * @brief Összeadja az aktuális vektort a paraméter vektorral.
     * @param other A vektor, amellyel az aktuális vektort összeadjuk.
     * @return Az összeadás eredményeként kapott vektor.
     */
    Vector operator+(const Vector &other) const;

    /**
     * @brief Kivonja a paraméter vektort az aktuális vektorból.
     * @param other A vektor, amelyet kivonunk az aktuális vektorból.
     * @return Az kivonás eredményeként kapott vektor.
     */
    Vector operator-(const Vector &other) const;

    /**
     * @brief Kiszámítja a skaláris szorzatot a paraméter vektorral.
     * @param other A vektor, amellyel a skaláris szorzatot számítjuk.
     * @return A skaláris szorzat eredménye.
     */
    double operator*(const Vector &other) const;

    /**
     * @brief Az aktuális vektort egyenlővé teszi a paraméter vektorral.
     * @param other A vektor, amellyel az aktuális vektort egyenlővé tesszük.
     */
    void operator=(const Vector &other);

    /**
     * @brief Ellenőrzi, hogy az aktuális vektor egyenlő-e a paraméter vektorral.
     * @param other A vektor, amellyel az aktuális vektort összehasonlítjuk.
     * @return True, ha a vektorok egyenlőek, különben false.
     */
    bool operator==(const Vector &other) const;

    /**
     * @brief Az aktuális vektort összeadja a paraméter vektorral.
     * @param other A vektor, amellyel az aktuális vektort összeadjuk.
     */
    void operator+=(const Vector &other);

    /**
     * @brief Kiírja az aktuális vektort az ostream objektumba.
     * @param os Az ostream objektum, amelybe kiírjuk az aktuális vektort.
     */
    void vectorPrint(std::ostream &os) const;

    /**
     * @brief A nullvektor konstans.
     */
    static const Vector nullVector;

    /**
     * @brief Az SFML által használt sf::Vector2f típusra kasztolható az aktuális Vector objektum.
     * @return Az aktuális Vector objektum sf::Vector2f típusú reprezentációja.
     */
    operator sf::Vector2f() const;
};

/**
 * @brief Vektor skalárral szorzása.
 * @param vector A vektor, amelyet szorozunk a skalárral.
 * @param scalar A skalár, amellyel szorozzuk a vektort.
 * @return Az eredményként kapott vektor.
 */
Vector operator*(const Vector &vector, double scalar);

/**
 * @brief Kiírja a vektort az ostream objektumba.
 * @param os Az ostream objektum, amelybe kiírjuk a vektort.
 * @param vector A vektor, amelyet kiírunk.
 * @return Az ostream objektum.
 */
std::ostream &operator<<(std::ostream &os, const Vector &vector);
