#pragma once

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif

#include "vector.h"
#include <ostream>
#include <iostream>
#include <cmath>
#include <SFML/System/Vector2.hpp>

/**
 * @brief Egy kétdimenzós pontot megvalósító osztály. Matematikai műveletek elvégzéséhez hoztam létre.
 */
class Point
{
private:
    double x; // X koordináta
    double y; // Y koordináta

public:
    /**
     * @brief Konstruktor az osztálynak.
     * @param x Az X koordináta kezdőértéke (alapértelmezett: 0.0).
     * @param y Az Y koordináta kezdőértéke (alapértelmezett: 0.0).
     */
    Point(double x = 0.0, double y = 0.0);

    /**
     * @brief A Point destruktora.
     */
    ~Point();

    /**
     * @brief Getter az X koordinát lekérdezéséhez.
     * @return Az X koordináta értéke.
     */
    double getX() const;

    /**
     * @brief Getter az Y koordinát lekérdezéséhez.
     * @return Az Y koordináta értéke.
     */
    double getY() const;

    /**
     * @brief Getter az egész Point lekérdezéséhez.
     * @return A POint objektum konstansreferenciája.
     */
    Point const &getPoint() const;

    /**
     * @brief Setter az X koordináta beállításához.
     * @param x Az új X koordináta értéke.
     */
    void setX(double x);

    /**
     * @brief Setter az Y koordináta beállításához.
     * @param y Az új Y koordináta értéke.
     */
    void setY(double y);

    /**
     * @brief Setter az egész Point beállításához.
     * @param x Az új X koordináta értéke.
     * @param y Az új Y koordináta értéke.
     */
    void setPoint(double x, double y);

    /**
     * @brief Setter az egész Point beállításához egy másik Pointtal.
     * @param point A Point objektum új értékei.
     */
    void setPoint(Point point);

    /**
     * @brief Két Point közötti távolság kiszámítására használt függvény.
     * @param point A másik Point objektum.
     * @return A két Point közötti távolság.
     */
    double calculateDistance(const Point &point) const;

    /**
     * @brief Két Point összehasonlítása.
     * @param point A másik Point objektum.
     * @return True, ha a két Point egyenlő, különben False.
     */
    bool operator==(const Point &point) const;

    /**
     * @brief Két Point összeadása.
     * @param point A másik Point objektum.
     * @return Az összeadás eredményeként kapott új Point objektum.
     */
    Point operator+(const Point &point) const;

    /**
     * @brief Két Point kivonása egymásból (tehát az egyikből a másikba vezető vektort adja meg).
     * @param point A másik Point objektum.
     * @return Az kivonás eredményeként kapott Vector objektum.
     */
    Vector operator-(const Point &point) const;

    /**
     * @brief Point és Vector összeadása, a Boid mozgásánál fontos szerepet tölt be.
     * @param vector A Vector objektum.
     * @return Az összeadás eredményeként kapott új Point objektum.
     */
    Point operator+(const Vector &vector) const;

    /**
     * @brief Az értékadás operátor felüldefiniálása.
     * @param point Az új Point objektum.
     */
    void operator=(const Point &point);

    /**
     * @brief Az Point objektumot Vector objektummá konvertáló operátor.
     * @return Az Point objektumot Vector objektummá konvertált érték.
     */
    operator Vector() const;

    /**
     * @brief Az Point objektumot sf::Vector2f típusára konvertáló operátor.
     * @return Az Point objektumot sf::Vector2f típusára konvertált érték.
     */
    operator sf::Vector2f() const;

    /**
     * @brief Néhol könnyebbséget jelent, hogy a (0,0) pont előre definiálva van.
     */
    static const Point Origo;

};

/**
 * @brief Point kiíratására használt operátor.
 * @param os Az output stream objektum.
 * @param point A kiírandó Point objektum.
 * @return Az output stream objektum referenciája.
 */
std::ostream &operator<<(std::ostream &os, const Point &point);
