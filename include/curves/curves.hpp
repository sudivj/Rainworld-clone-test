#pragma once

#include <math.h>
#include <iostream>
#include <vector>

#include "../utils.hpp"

float square(float value);

std::vector<point> generateCurve(point p1, point p2, point p3, int smoothness_factor);