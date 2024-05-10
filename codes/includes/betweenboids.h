#pragma once
#include "basicboid.h"

class ForcesBetweenBoids
{
private:
public:
    ForcesBetweenBoids() {}
    virtual Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const = 0;
};