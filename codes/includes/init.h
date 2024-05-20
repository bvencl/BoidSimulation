#pragma once

// init.h
// A szimuláció kezdeti állapotát beállító függvények deklarációját tartalmazó header file.

#include "flock.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// A függvény, amely a nyájt "inicializálja", azaz bekéri a kívánt Boidok számát, feltölti a kezdőpozícióban lévő Boidokkal
void initFlock(Flock &, double, double);

// A nyájhoz tartozó grafikus objektumokkal feltölt egy std:.vectort. Ez nagyban megkönnyíti azoknak ábrázolását. A kívánt színnel lehet benne Boidokat létrehozni.
void initGraphics(std::vector<sf::CircleShape> &, Flock &, sf::Color);

// A zenét megkereső függvény.
void initMusic(sf::Music &);
