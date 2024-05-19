#pragma once
#include "rule.h"

class SeparationRule : public Rule
{

private:
    template <typename chosenContainer>
    Vector calculateRuleForIndividual(std::vector<BasicBoid> &, const BasicBoid &) const override;

    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    double calculateScalingFactor(const BasicBoid &, double, double) const override;

public:
    SeparationRule(double rule_strength = 1);

    Vector applyRule() const override;
};