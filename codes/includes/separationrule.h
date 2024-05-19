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

template <typename Iterator>
Vector SeparationRule::calculateRuleForIndividualImpl(Iterator begin, Iterator end, const BasicBoid &boid) const
{
    Vector sumOfSeparationInFlock(0, 0);

    for (Iterator It = begin; It != end; It++)
    {
        if (!(*It == boid))
        {
            sumOfSeparationInFlock += calculateRuleStrengthBetweenBoids(*It, boid);
        }
    }
    return sumOfSeparationInFlock;
}