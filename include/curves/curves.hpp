#pragma once

#include <math.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

#include "../utils.hpp"

float square(float value);

std::vector<SDL_Point> generateCurve(point p1, point p2, point p3, int smoothness_factor);
std::vector<SDL_Point> generateChaikinCurve(std::vector<point> points, int sm_fac);
// std::vector<point> generateCurve(point p1, point p2, point p3, int smoothness_factor);