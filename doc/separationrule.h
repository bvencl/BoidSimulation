#pragma once
#include "rule.h"

class SeparationRule : public Rule, public ForcesBetweenBoids
{

private:
public:
    SeparationRule(double rule_strength = 1);

    double calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    Vector calculateRuleForIndividual(const BasicBoid &, std::optional<sf::Vector2i>) override;

};