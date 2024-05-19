#include "separationrule.h"
#define DESIRED_MINIMAL_DISTANCE 150.0
#define EMPIRIC_SCALING_VALUE 500.0

SeparationRule::SeparationRule(double rule_strength) : Rule<SeparationRule>(rule_strength) {}

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

Vector SeparationRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    Vector direction = individual.getPosition() - currentFlockMember.getPosition();
    double distance = direction.getLength();

    try
    {
        direction.normaliastion();
    }
    catch (std::runtime_error &rte)
    {
        std::cerr << rte.what() << '\n';
        return Vector::nullVector;
    }

    double scalingFactor = 0.0;

    if (distance < individual.getMass() / 2 + currentFlockMember.getMass() / 2 + 50) // Ha nagyon közel vannak egymáshoz  (azért arányos a súlyukkal,
    {                                                                                // mert az ábrázolásnál a méretük (kör sugara) a súlyukkal egyezik meg)
        scalingFactor = EMPIRIC_SCALING_VALUE;                                       // Empirikusan választott scalingFactor erre az eshetőségre
    }
    else if (distance > individual.getMass() / 2 + currentFlockMember.getMass() / 2 + 15 && distance < individual.getMass() / 2 + currentFlockMember.getMass() / 2 + DESIRED_MINIMAL_DISTANCE) // Ha kicsit távolabb vannak azért
    {
        scalingFactor = 1.0 / (distance - (individual.getMass() + currentFlockMember.getMass()));
    }
    else if (distance > individual.getMass() / 2 + currentFlockMember.getMass() / 2 + DESIRED_MINIMAL_DISTANCE && direction.angleWith(individual.getSpeed()) > M_PI / 3)
    {
        scalingFactor = currentFlockMember.getMass() * individual.getMass() / (distance * distance);
    }

    return direction * getRuleStrength() * scalingFactor;
}

double SeparationRule::calculateScalingFactor(const BasicBoid &, double, double) const
{
    return 0;
}