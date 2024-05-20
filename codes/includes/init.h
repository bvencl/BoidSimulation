#pragma once

#include "flock.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void initFlock(Flock &, double, double);

void initGraphics(std::vector<sf::CircleShape> &, Flock &, sf::Color);

void initMusic(sf::Music &);
