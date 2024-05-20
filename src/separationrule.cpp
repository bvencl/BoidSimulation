#include "separationrule.h"


SeparationRule::SeparationRule(double rule_strength) : Rule<SeparationRule>(rule_strength) {}

Vector SeparationRule::calculateRuleStrengthBetweenBoids(const BasicBoid &currentFlockMember, const BasicBoid &individual) const
{
    // Az egyed pozícióját mutató vektor és a vizsgált másik egyed pozícióját mutató vektor különbségeként megkaphatjuk az egyikből a másikba mutató vektort.
    Vector direction = individual.getPosition() - currentFlockMember.getPosition();
    double distance = direction.getLength(); // Ennek hossza lesz a két vektor távolsága

    try
    {
        // Lévén, hogy csak az irányra van szükségünk jelenleg, a skálázást máshol végezzük, így a vektort normáljuk
        // A normálás során előfordulhat, hogy nullával osztunk, ilyenkor ettől a függvénytől azt várjuk, hogy hibát dobjon
        direction.normaliastion();
    }
    catch (std::runtime_error &rte)
    {
        std::cerr << rte.what() << '\n';
        // Amennyiben a normálásnál nullával osztunk, tudjhatjuk, hogy a két egyed távolsága nulla,
        // ilyenkor nem tudjuk milyen irányú gyorsulást kellene adnia a függvénynek, ezért nem adunk semmilyet,
        // más szabály úgyis eltávolítja a két egyedet egymástól még ebben az időlépésbens
        return Vector::nullVector;
    }

    double scalingFactor = 0.0;

    //! Az alábbi képletek empirikusan vannak meghatározva, így tudtam a "talán legtermészetesebb" hatást elérni
    //  Ha nagyon közel vannak egymáshoz
    if (distance < individual.getMass() / 2 + currentFlockMember.getMass() / 2 + DESIRED_MINIMAL_DISTANCE / 3) // (azért arányos a súlyukkal,
    {                                                                                                          // mert az ábrázolásnál a méretük (kör sugara) a súlyukkal egyezik meg)
        scalingFactor = EMPIRIC_SCALING_VALUE;                                                                 // Empirikusan választott scalingFactor erre az eshetőségre
    }
    // Amennyiben azért valamennyire távolabb vannak egymástól
    else if (distance > individual.getMass() / 2 + currentFlockMember.getMass() / 2 + DESIRED_MINIMAL_DISTANCE / 3 && distance < individual.getMass() / 2 + currentFlockMember.getMass() / 2 + DESIRED_MINIMAL_DISTANCE) // Ha kicsit távolabb vannak azért
    {
        scalingFactor = 1.0 / (distance - (individual.getMass() + currentFlockMember.getMass())); // 1 / (Távolság - Boidok méretének (őket reprezentáló körök sugarainak hosszának) összege)
    }

    // Amennyiben már elég távol vannak, és a vizsgált egyed "előtt" helyezkedik el, azaz benne van annak +- 60 fokos látószögében
    else if (individual.getMass() / 2 + currentFlockMember.getMass() / 2 + DESIRED_MINIMAL_DISTANCE < distance && direction.angleWith(individual.getSpeed()) > M_PI / 3)
    {
        scalingFactor = currentFlockMember.getMass() * individual.getMass() / (distance * distance); // (Boidok mérete) / (távolság^2)
    }

    return direction * getRuleStrength() * scalingFactor; // Visstaadjuk a választott skálázó faktorral a gyorsulás komponenst
}

// Ennek a függvénynek ennél az osztálynál nincsen szerepe
double SeparationRule::calculateScalingFactor(const BasicBoid &, double, double) const
{
    return 0;
}