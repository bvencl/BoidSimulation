#pragma once
#include "vector.h"
#include "point.h"
#include "basicboid.h"
#include "flock.h"
#include "rule.h"
#include "logger.h"
#include <iostream>
#include <ostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef dT
#define dT 1e-2
#endif
#define ever ;;

