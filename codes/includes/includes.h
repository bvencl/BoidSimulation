#pragma once
#include "vector.h"
#include "point.h"
#include "basicboid.h"
#include "flock.h"
#include "rule.h"
#include "chasingrule.h"
#include "separationrule.h"
#include "cohesionrule.h"
#include "alignmentrule.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ostream>
#include <cmath>
#include <memory>
#include "memtrace.h"

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
Error list:

*/