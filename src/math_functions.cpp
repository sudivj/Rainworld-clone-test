#include "../include/math_functions.hpp"

float getDistance(int start_x, int start_y, int target_x, int target_y)
{
    float diff_x = abs(start_x - target_x);
    float diff_y = abs(start_y - target_y);

    return (float)sqrt((diff_x * diff_x) + (diff_y * diff_y));
}

float getDistance(Node start_node, Node target_node)
{
    float diff_x = abs(start_node.pos_x - target_node.pos_x);
    float diff_y = abs(start_node.pos_y - target_node.pos_y);

    return (float)sqrt((diff_x * diff_x) + (diff_y * diff_y));
}

float radToDeg(float radians)
{
    return (float)(radians * (180 / PI));
}

float degToRad(float degrees)
{
    return (float)(degrees * (PI / 180));
}