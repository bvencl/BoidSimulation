#pragma once

/**
 * @file flock.h
 * @brief A Flock osztály definícióját és metódusainak deklarációját tartalmazó header fájl.
 */

#include "basicboid.h"
#include "chasingrule.h"
#include "separationrule.h"
#include "cohesionrule.h"
#include "alignmentrule.h"
#include <vector>
#include <list>

/**
 * @class Flock
 * @brief A nyáj osztály, amely tartalmazza a Boidokat és a nyáj szabályait.
 *
 * A Flock osztály felelős a boidok tárolásáért és a nyáj szabályainak végrehajtásáért.
 * A boidokat egy std::vector-ban tárolja, és a nyáj szabályait külön-külön objektumokként kezeli.
 * A Boidokat tárolhatnánk akár std::list-ben is, minden metódus kompatibilis lenne azzal is.
 */
class Flock
{
    std::vector<BasicBoid> flockMembers; ///< Boidokat tároló std::vector. Ebben az új megvalósításban már nem BasicBoid *-ot, hanem az egész BasicBoid-ot tárolja.
    ChasingRule chase; ///< A nyáj Chase szabálya.
    SeparationRule separation; ///< A nyáj Separation szabálya.
    CohesionRule cohesion; ///< A nyáj Cohesion szabálya.
    AlignmentRule alignment; ///< A nyáj Alignment szabálya.

public:
    /**
     * @brief Flock osztály konstruktora.
     * @param flock_chasing_coefficient A nyáj üldözési együtthatója.
     * @param flock_repulsion A nyáj taszítási együtthatója.
     * @param flock_cohesion A nyáj összetartási együtthatója.
     * @param flock_alignment A nyáj igazodási együtthatója.
     */
    Flock(double flock_chasing_coefficient = 1, double flock_repulsion = 1, double flock_cohesion = 1, double flock_alignment = 1);

    /**
     * @brief Boid beillesztése a nyájba.
     * @param boid A beillesztendő boid objektum, most már érték szerint.
     */
    void insert(BasicBoid boid);

    /**
     * @brief Boid eltávolítása a nyájból.
     * @param boid Az eltávolítandó boid objektum.
     */
    void remove(const BasicBoid &boid);

    /**
     * @brief A nyáj mozgatása időegységenként.
     * @param time A mozgatás időegysége.
     * @param target A cél pozíciója.
     */
    void moveFlock(double time, const sf::Vector2i &target);

    /**
     * @brief Megvizsgálja, hogy a boid tagja-e már a nyájnak.
     * @param boid A vizsgált boid objektum.
     * @return true, ha a boid tagja a nyájnak, false egyébként.
     */
    bool isMemberOfFlock(const BasicBoid &boid) const;

    /**
     * @brief A nyáj indexelésére használt operátor.
     * @param index Az index, amelyre hivatkozni szeretnénk.
     * @return A megadott indexű boid objektum referenciája.
     */
    BasicBoid &operator[](size_t index);

    /**
     * @brief A nyáj indexelésére használt operátor konstans.
     * @param index Az index, amelyre hivatkozni szeretnénk.
     * @return A megadott indexű boid objektum konstans referenciája.
     */
    BasicBoid const &operator[](size_t index) const;

    /**
     * @brief Visszaadja a nyáj méretét.
     * @return A nyáj mérete.
     */
    size_t flockSize() const;
};

