#include "chasingrule.h"

ChasingRule::ChasingRule(double rule_strength) : Rule(rule_strength) {}


Vector ChasingRule::calculateRuleForIndividual(const BasicBoid &boid, sf::Vector2i mousePosition)
{
    Point target(mousePosition.x, mousePosition.y);
    double distance = target.calculateDistance(boid.getPosition());
    Vector direction = target - boid.getPosition();
    direction.normaliastion();  // Normalizáljuk az irányvektort

    // Dinamikus gyorsulási skálázás a távolság függvényében
    double scalingFactor;
    if (distance < 100) {
        scalingFactor = distance / 2000;  // Nagyon finom gyorsulás kis távolságra
    } else if (distance < 300) {
        scalingFactor = distance / 1000;  // Erősebb gyorsulás közepes távolságra
    } else {
        scalingFactor = sqrt(distance / 1000);  // Stabil gyorsulás nagyobb távolságra
    }

    Vector acceleration = direction * scalingFactor;

    // Korrekciós gyorsulás, ha a boid túllő a célon
    Vector currentVelocity = boid.getSpeed();
    if (currentVelocity * direction < 0) {  // Ellenőrizzük, hogy a sebesség és az irány ellentétes-e
        double correctionFactor = 2.0;  // Nagyobb gyorsulás az ellentétes irányba
        acceleration = acceleration * correctionFactor;
    }

    // Maximális gyorsulási korlát beállítása
    double maxAcceleration = 5.0;  // Csökkentettük a maximális gyorsulást
    if (acceleration.getLength() > maxAcceleration) {
        acceleration.normaliastion();  // Normalizáljuk az új gyorsulási vektort
        acceleration = acceleration * maxAcceleration;  // Korlátozzuk a maximális gyorsulásra
    }

    return acceleration;  // Visszaadjuk a számított gyorsulást
}






// Vector ChasingRule::calculateRuleForIndividual(const BasicBoid &boid, sf::Vector2i mousePosition)
// {
//     Point target(mousePosition.x, mousePosition.y);

//     double distance = target.calculateDistance(boid.getPosition());

//     Vector direction = target - boid.getPosition();

//     direction.normaliastion();

//     if (distance < 400 && direction * boid.getSpeed() < 0.0)
//     {
//         return direction * (-distance);
//     }

//     if (distance < 400)
//     {
//         direction = direction * (distance / 100);
//         return direction;
//     }
//     if (400 < distance && distance < 1500)
//     {
//         direction += direction * exp(distance * (1 / 200));
//     }
//     if (1500 < distance)
//     {
//         direction += direction * sqrt(distance / 100);
//     }
//     return direction * getRuleStrength();
// }