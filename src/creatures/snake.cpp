#include "../../include/creatures/snake.hpp"

void Snake::initializeSnake()
{
    creatureName = "Snake";

    body.push_back(new BodyPart(body_size_config[0], BodyPartType::HEAD));
    for (int b = 1; b < body_size_config.size() - 1; b++)
    {
        body.push_back(new BodyPart(body_size_config[b], BodyPartType::BODY));
    }
    body.push_back(new BodyPart(body_size_config.back(), BodyPartType::TAIL));

    for (int b = 0; b < body_size_config.size(); b++)
    {
        if (b == 0)
        {
            body[b]->prev = nullptr;
            body[b]->next = body[b + 1];
            snake_head = body[b];
        }
        else if (b == body_size_config.size() - 1)
        {
            body[b]->prev == body[b - 1];
            body[b]->next == nullptr;
            snake_tail = body[b];
        }
        else
        {
            body[b]->prev == body[b - 1];
            body[b]->next == body[b + 1];
        }
    }

    calculateVertices();
}

void Snake::update(int x, int y)
{
    BodyPart_setTarget(snake_head, x, y);
    BodyPart_followTarget(snake_head);
    for (int b = 1; b < body.size(); b++)
    {
        float body_angle = getDirection(body[b - 1], body[b]);
        float new_x = body[b - 1]->pos_x + (body_connection_length * cos(body_angle));
        float new_y = body[b - 1]->pos_y + (body_connection_length * sin(body_angle));

        // std::string data = "bodypart(" + std::to_string(b) +
        //                    ")->BodyAngle: " + std::to_string(radToDeg(body_angle)) +
        //                    ", new_x: " + std::to_string(new_x) +
        //                    ", new_y: " + std::to_string(new_y);
        // SDL_Log(data.c_str());

        BodyPart_updatePos(body[b], new_x, new_y);
    }

    setVertices();
}

void Snake::draw(SDL_Renderer *r)
{
    // for (int b = 0; b < body.size(); b++)
    // {
    //     BodyPart_draw(r, body[b]);
    // }
    for (int v = 0; v < body_vertices.size(); v++)
    {
        setPixel(r, body_vertices[v].first, body_vertices[v].second, COLOR_RED);
        if (v > 0)
        {
            SDL_SetRenderDrawColor(r, COLOR_ORANGE.r, COLOR_ORANGE.g, COLOR_ORANGE.b, COLOR_ORANGE.a);
            // SDL_RenderDrawLine(r, body_vertices[v - 1].first, body_vertices[v - 1].second, body_vertices[v].first, body_vertices[v].second);
        }
    }
}

void Snake::printData()
{
}

void Snake::calculateVertices()
{
    number_of_veritces = (body.size() * 2) + 2;
}

void Snake::setVertices()
{
    calculateVertices();
    body_vertices.erase(body_vertices.begin(), body_vertices.end());
    int point_x, point_y;
    float angle = getDirection(body[0], body[1]) + degToRad(180);
    point_x = body[0]->pos_x + (body[0]->circle.radius * cos(angle));
    point_y = body[0]->pos_y + (body[0]->circle.radius * sin(angle));
    body_vertices.push_back({point_x, point_y});
    for (int v = 0; v < (number_of_veritces / 2) - 1; v++)
    {
        if (v > 0)
        {
            angle = getDirection(body[v - 1], body[v]) + degToRad(90);
        }
        else
        {
            angle = angle - degToRad(90);
        }
        point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle));
        point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle));
        body_vertices.push_back({point_x, point_y});
    }
    angle = angle - degToRad(90);
    point_x = body.back()->pos_x + (body.back()->circle.radius * cos(angle));
    point_y = body.back()->pos_y + (body.back()->circle.radius * sin(angle));
    body_vertices.push_back({point_x, point_y});
    int size = body.size() - 1;
    for (int v = 0; v < (number_of_veritces / 2) - 1; v++)
    {
        if (v > 0)
        {
            angle = getDirection(body[size - (v - 1)], body[size - v]) + degToRad(90);
        }
        else
        {
            angle = angle - degToRad(90);
        }
        point_x = body[size - v]->pos_x + (body[size - v]->circle.radius * cos(angle));
        point_y = body[size - v]->pos_y + (body[size - v]->circle.radius * sin(angle));
        body_vertices.push_back({point_x, point_y});
    }
    angle = getDirection(body[0], body[1]) + degToRad(180);
    point_x = body[0]->pos_x + (body[0]->circle.radius * cos(angle));
    point_y = body[0]->pos_y + (body[0]->circle.radius * sin(angle));
    body_vertices.push_back({point_x, point_y});
}