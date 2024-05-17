#pragma once
#include "basicboid.h"
#include "vector.h"
#include "point.h"
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
    virtual Vector calculateRuleForIndividual(std::vector<BasicBoid *>&, const BasicBoid &) const = 0;
    double getRuleStrength() const { return ruleStrength; }
    virtual Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const = 0;
    virtual double calculateScalingFactor(const BasicBoid &, double, double) const = 0;
};