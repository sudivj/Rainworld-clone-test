#pragma once

#include <math.h>

#include "node.hpp"

#define PI 3.14159265359

float getDistance(int start_x, int start_y, int target_x, int target_y);
float getDistance(Node start_node, Node target_node);
float radToDeg(float radians);
float degToRad(float degrees);