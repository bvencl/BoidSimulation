#pragma once
#include "rule.h"

class ChasingRule
{
private:
    double ruleStrength;

public:
    ChasingRule(double rule_strength = 1);

    Vector calculateRuleForIndividual(const BasicBoid &, sf::Vector2i);
    double getRuleStrength() const;
};