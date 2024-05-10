#pragma once
#include "rule.h"

class AlingmentRule : Rule
{

private:
public:
    AlingmentRule(double rule_strength = 1);
    double calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;
    Vector calculateRuleForIndividual(const BasicBoid &) override;
    void calculateRuleForFlockPerTurn(Flock &) override;
};