#pragma once
#include "rule.h"

class AlingmentRule : public Rule
{

private:
public:
    AlingmentRule(double rule_strength = 1);

    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    Vector calculateRuleForIndividual(BasicBoid **, const BasicBoid &, size_t) const override;
    
    double calculateScalingFactor(const BasicBoid &, double, double) const override;
};