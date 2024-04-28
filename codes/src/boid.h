#pragma once
#include "vector.h"
#include "point.h"
class Boid
{
private:
    Vector speed;
    Vector acceleration;
    Point currentposition;
    double repellingForce;
    double mass;



public:

    Boid();

};