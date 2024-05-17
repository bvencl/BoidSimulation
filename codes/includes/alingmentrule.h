#pragma once
#include "rule.h"

class AlingmentRule : public Rule
{

private:
public:
    AlingmentRule(double rule_strength = 1);

    Vector calculateRuleForIndividual(std::vector<BasicBoid *>, const BasicBoid &) const override;

    Vector calculateRuleStrengthBetweenBoids(const BasicBoid & , const BasicBoid &) const override;
    
    double calculateScalingFactor(const BasicBoid &, double, double) const override;
};