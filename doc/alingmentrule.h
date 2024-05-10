#pragma once
#include "rule.h"

class AlingmentRule : public Rule, public ForcesBetweenBoids
{

private:
public:
    AlingmentRule(double rule_strength = 1);

    double calculateRuleStrengthBetweenBoids(const BasicBoid &, const BasicBoid &) const override;

    Vector calculateRuleForIndividual(const BasicBoid &, std::optional<sf::Vector2i>) override;
};