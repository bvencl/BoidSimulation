#pragma once
#include "basicboid.h"
#include "vector.h"
#include "point.h"
#include "betweenboids.h"
#include <SFML/Graphics.hpp>
#include <optional>
#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif

class Rule
{
private:
    double ruleStrength;

public:
    Rule(double rule_strength) : ruleStrength(rule_strength){};
    virtual Vector calculateRuleForIndividual(const BasicBoid &, sf::Vector2i) = 0;
    double getRuleStrength() const { return ruleStrength; }
};