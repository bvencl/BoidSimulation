#include <iostream>
#include <ostream>
#include <cmath>
#include "vector.h"
#include "point.h"
#include "basicboid.h"

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define ever \
    ;        \
    ;

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    if (DEBUG_IS_ON)
    {
        cout << "debug mode is on" << endl;
    }

    // Vektorok létrehozása
    Vector v1(3.0, 4.0);
    Vector v2(1.0, 2.0);

    // Alapértelmezett konstruktorral létrehozott vektor
    Vector v3;

    // Vektorok kiíratása
    std::cout << "Vektor 1: " << v1 << std::endl;
    std::cout << "Vektor 2: " << v2 << std::endl;
    std::cout << "Vektor 3 (alapértelmezett): " << v3 << std::endl;

    // Vektorok összeadása
    Vector vSum = v1 + v2;
    std::cout << "V1 + V2 = " << vSum << std::endl;

    // Vektorok kivonása
    Vector vDiff = v1 - v2;
    std::cout << "V1 - V2 = " << vDiff << std::endl;

    // Vektor negálása
    Vector vNeg = -v1;
    std::cout << "-V1 = " << vNeg << std::endl;

    // Vektor forgatása 90 fokkal (π/2 radián)
    Vector vRotated = v1.rotate(M_PI / 2);
    std::cout << "V1 forgatva 90 fokkal: " << vRotated << std::endl;

    // Skalárral szorzás
    Vector vScaled = v2 * 3;
    std::cout << "V2 * 3 = " << vScaled << std::endl;

    // Vektor hosszának ellenőrzése
    std::cout << "V1 hossza: " << v1.getLength() << std::endl;
    std::cout << "V2 hossza: " << v2.getLength() << std::endl;

    // Vektorok szögének ellenőrzése
    double angle = v1.angleWith(v2);
    std::cout << "V1 és V2 közötti szög (radiánban): " << angle << std::endl;

    // Projekció ellenőrzése
    Vector vProjection = v1.projectionOnto(v2);
    std::cout << "V1 vetülete V2-re: " << vProjection << std::endl;
    BasicBoid Boidocska(1);
    
    
    for (ever)
    {
        cout << Boidocska <<endl;
    }

    return 0;
}
