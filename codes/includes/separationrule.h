#pragma once
#include "rule.h"

class SeparationRule : Rule
{

private:
public:
    SeparationRule(double rule_strength = 1);
    double calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;
    Vector calculateRuleForIndividual(const BasicBoid &) override;
    void calculateRuleForFlockPerTurn(Flock &) override;
};