#pragma once
#include "rule.h"

class SeparationRule : public Rule<SeparationRule>
{

public:
    SeparationRule(double rule_strength = 1);

    template <typename Iterator>
    Vector calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &) const;

private:
    Vector calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    double calculateScalingFactor(const BasicBoid &, double, double) const override;
};