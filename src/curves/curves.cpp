#include "../../include/curves/curves.hpp"

float square(float value)
{
    return value * value;
}

std::vector<SDL_Point> generateCurve(point p1, point p2, point p3, int smoothness_factor)
{
    float delta_t = (float)((float)1 / (float)smoothness_factor);
    std::vector<SDL_Point> curve;
    float t = 0;
    SDL_Point p;
    for (int i = 0; i < smoothness_factor; i++)
    {
        t = t + delta_t;
        float x = (square((1 - t)) * (float)p1.first) + (((2 * (1 - t)) * t) * (float)p2.first) + (square(t) * (float)p3.first);
        float y = (square((1 - t)) * (float)p1.second) + (((2 * (1 - t)) * t) * (float)p2.second) + (square(t) * (float)p3.second);
        p.x = floor(x);
        p.y = floor(y);
        curve.push_back(p);
    }

    return curve;
}

std::vector<SDL_Point> pointToSDLPoints(std::vector<point> points)
{
    std::vector<SDL_Point> res = {};
    for (int i = 0; i < points.size(); i++)
    {
        SDL_Point p;
        p.x = points[i].first;
        p.y = points[i].second;
        res.push_back(p);
    }
    return res;
}

std::vector<SDL_Point> generateChaikinCurve(std::vector<point> points, int sm_fac)
{
    if (sm_fac == 0) return pointToSDLPoints(points);
    int len = points.size();
    std::vector<point> smooth = {};
    int x = 0, y = 0;
    for (int i = 0; i < len; i++)
    {
        x = ((0.75f * points[i].first) + (0.25f * points[(i + 1)%len].first));
        y = ((0.75f * points[i].second) + (0.25f * points[(i + 1)%len].second));
        smooth.push_back({x, y});
        x = ((0.25f * points[i].first) + (0.75f * points[(i + 1)%len].first));
        y = ((0.25f * points[i].second) + (0.75f * points[(i + 1)%len].second));
        smooth.push_back({x, y});
    }
    return sm_fac == 1 ? pointToSDLPoints(smooth) : generateChaikinCurve(smooth, sm_fac - 1);
}