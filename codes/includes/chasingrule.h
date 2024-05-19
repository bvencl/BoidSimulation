#pragma once
#include "basicboid.h"
class ChasingRule
{
private:
    double ruleStrength;

public:
    ChasingRule(double rule_strength = 1);

    Vector calculateRuleForIndividual(const BasicBoid &,const sf::Vector2i &);
    double getRuleStrength() const;
};