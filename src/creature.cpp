#include "../include/creature.hpp"

void Creature::calculateVertices()
{
    number_of_veritces = (body.size() * 2) + 4;
}

void Creature::setVertices()
{
    int point_x, point_y;
    // Head vertex
    float angle = getDirection(body[0], body[1]) + degToRad(180);
    point_x = body[0]->pos_x + ((body[0]->circle.radius) * cos(angle));
    point_y = body[0]->pos_y + ((body[0]->circle.radius) * sin(angle));
    body_vertices.at(0) = {point_x, point_y};
    angle = getDirection(body[0], body[1]) + degToRad(135);
    point_x = body[0]->pos_x + ((body[0]->circle.radius) * cos(angle));
    point_y = body[0]->pos_y + ((body[0]->circle.radius) * sin(angle));
    body_vertices.at(1) = {point_x, point_y};
    angle = getDirection(body[0], body[1]) + degToRad(-135);
    point_x = body[0]->pos_x + ((body[0]->circle.radius) * cos(angle));
    point_y = body[0]->pos_y + ((body[0]->circle.radius) * sin(angle));
    body_vertices.at(number_of_veritces - 1) = {point_x, point_y};
    body_vertices.at(number_of_veritces) = body_vertices[0];

    for (int v = 0; v < (number_of_veritces / 2) - 2; v++)
    {
        if (v > 0)
        {
            angle = getDirection(body[v - 1], body[v]);

            //Side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle + degToRad(90)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle + degToRad(90)));
            body_vertices.at(v + 2) = {point_x, point_y};

            //Corresponding opposite side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle - degToRad(90)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle - degToRad(90)));
            body_vertices.at(number_of_veritces - (v + 2)) = {point_x, point_y};
        }
        else
        {
            //Side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle  - degToRad(135)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle  - degToRad(135)));
            body_vertices.at(v + 2) = {point_x, point_y};

            //Corresponding opposite side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle + degToRad(45)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle + degToRad(45)));
            body_vertices.at(number_of_veritces - (v + 2)) = {point_x, point_y};
        }
    }

    // Tail
    point_x = body.back()->pos_x + (body.back()->circle.radius * cos(angle));
    point_y = body.back()->pos_y + (body.back()->circle.radius * sin(angle));
    body_vertices.at(number_of_veritces / 2) = {point_x, point_y};

    int sm_fac = 50;

    smooth_body_vertices.erase(smooth_body_vertices.begin(), smooth_body_vertices.end());
    for (int i = 0; i < body_vertices.size() / 2; i++)
    {
        std::vector<point> curve = generateCurve(body_vertices[i * 2], body_vertices[(i * 2) + 1], body_vertices[(i * 2) + 2], sm_fac);
        smooth_body_vertices.insert(smooth_body_vertices.begin() + (sm_fac * i), curve.begin(), curve.end());
    }
    
    // SDL_Log(std::to_string(smooth_body_vertices.size()).c_str());
}