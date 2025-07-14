#include "../../include/curves/curves.hpp"

float square(float value)
{
    return value * value;
}

std::vector<point> generateCurve(point p1, point p2, point p3, int smoothness_factor)
{
    float delta_t = (float)((float)1 / (float)smoothness_factor);
    std::vector<point> curve = {};
    float t = 0;
    for (int i = 0; i < smoothness_factor; i++)
    {
        t = t + delta_t;
        // SDL_Log(std::to_string(t).c_str());
        float x = (square((1-t)) * (float)p1.first) + (((2 * (1-t)) * t) * (float)p2.first) + (square(t) * (float)p3.first);
        // SDL_Log(std::to_string(x).c_str());
        float y = (square((1-t)) * (float)p1.second) + (((2 * (1-t)) * t )* (float)p2.second) + (square(t) * (float)p3.second);
        // SDL_Log(std::to_string(y).c_str());
        curve.push_back({(int)x, (int)y});
    }
    
    return curve;
}