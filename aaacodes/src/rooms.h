#pragma once

class Room
{
private:
    double depth;         // Szoba mélysége
    double width;         // Szoba szélessége
    double height;        // Belmagasság
    double windowArea;    // Ablakfelület
    double Udoor;         // Ajtók hőátbocsátási tenyezője
    double UInsideWall;   // Belső falak hőátbocsátási tenyezője
    double UOutsideWall;  // Külső falak hőátbocsátási tenyezője
    double URoof;         // Plafon/tető hőátbocsátási tenyezője
    double Ufloor;        // Padló hőátbocsátási tenyezője (nem minden esetben szükséges)
    double heatCapacity;  // Szoba hőkapacitása
    double areaToInside;  // Más szoba felé eső falefelület
    double areaToOutside; // Külső környezet felé eső falfelület

public:
};