#pragma once
#include "rule.h"

class ChasingRule : public Rule
{
private:
public:
    ChasingRule(double rule_strength = 1);

    Vector calculateRuleForIndividual(const BasicBoid &, sf::Vector2i);
};