#pragma once
#include "basicboid.h"
#include "vector.h"
#include "point.h"
#include "flock.h"
// #ifndef dT
// #define dT 1e-2
// #endif
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
    Rule(double rule_strength): ruleStrength(rule_strength) {};
    virtual double calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const;
    virtual Vector calculateRuleForIndividual(const BasicBoid &);
    virtual void calculateRuleForFlockPerTurn(Flock &);
};