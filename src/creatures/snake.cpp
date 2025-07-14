#include "../../include/creatures/snake.hpp"

void Snake::initializeSnake()
{
    body_connection_length = 20;
    body_size_config = {15, 15, 10, 10, 7, 7, 7, 5, 5, 5, 5, 5, 5};
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
    body_vertices.resize(number_of_veritces + 1);
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
    for (int b = 0; b < body.size(); b++)
    {
        BodyPart_draw(r, body[b]);
    }
    for (int b = 0; b < body_vertices.size(); b++)
    {
        setPixel(r, body_vertices[b].first, body_vertices[b].second, COLOR_RED);
    }
    for (int v = 0; v < smooth_body_vertices.size(); v++)
    {
        // setPixel(r, smooth_body_vertices[v].first, smooth_body_vertices[v].second, COLOR_RED);
        if (v > 0)
        {
            SDL_SetRenderDrawColor(r, COLOR_ORANGE.r, COLOR_ORANGE.g, COLOR_ORANGE.b, COLOR_ORANGE.a);
            SDL_RenderDrawLine(r, smooth_body_vertices[v - 1].first, smooth_body_vertices[v - 1].second, smooth_body_vertices[v].first, smooth_body_vertices[v].second);
        }
    }
}

void Snake::printData()
{
}