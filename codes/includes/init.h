#pragma once

/**
 * @file init.h
 * @brief A szimuláció kezdeti állapotát beállító függvények deklarációját tartalmazó header fájl.
 */

#include "flock.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * @brief A függvény, amely a nyájat inicializálja.
 * 
 * Bekéri a kívánt Boidok számát, és feltölti a kezdőpozícióban lévő Boidokkal.
 * 
 * @param flock A nyáj, amelyet inicializálunk.
 * @param width A képernyő szélessége pixelben.
 * @param height A képernyő magassága pixelben.
 */
void initFlock(Flock &flock, double width, double height);

/**
 * @brief A nyájhoz tartozó grafikus objektumokkal feltölt egy std::vectort.
 * 
 * Ez nagyban megkönnyíti azok ábrázolását. A kívánt színnel lehet benne Boidokat létrehozni.
 * 
 * @param graphics A grafikus objektumokat tartalmazó std::vector.
 * @param flock A nyáj, amelyhez a grafikus objektumok tartoznak.
 * @param color A Boidok színe.
 */
void initGraphics(std::vector<sf::CircleShape> &graphics, Flock &flock, sf::Color color);

/**
 * @brief A zenét megkereső függvény.
 * 
 * Inicializálja és betölti a szükséges zenefájlokat.
 * 
 * @param music Az sf::Music objektum, amelyet inicializálunk.
 */
void initMusic(sf::Music &music);
