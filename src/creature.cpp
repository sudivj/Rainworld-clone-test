#include "../include/creature.hpp"

void Creature::calculateVertices()
{
    number_of_veritces = (body.size() * 2) + 4;
}

void Creature::initializeCreature()
{
    // Get creature data from YAML file.
    this->creature_name = creature_config["creatureName"].as<std::string>();
    this->is_variable_body_length = creature_config["isVariableBodyLength"].as<bool>();
    this->has_legs = creature_config["hasLegs"].as<bool>();

    this->body_color.r = creature_config["bodyColor"][0].as<Uint8>();
    this->body_color.g = creature_config["bodyColor"][1].as<Uint8>();
    this->body_color.b = creature_config["bodyColor"][2].as<Uint8>();
    this->body_color.a = creature_config["bodyColor"][3].as<Uint8>();

    this->body_outline_color.r = creature_config["bodyOutlineColor"][0].as<Uint8>();
    this->body_outline_color.g = creature_config["bodyOutlineColor"][1].as<Uint8>();
    this->body_outline_color.b = creature_config["bodyOutlineColor"][2].as<Uint8>();
    this->body_outline_color.a = creature_config["bodyOutlineColor"][3].as<Uint8>();

    if (!this->is_variable_body_length)
    {
        this->body_connection_length.push_back(creature_config["bodyConnectionLength"].as<int>());
    }
    else
    {
        // If creature has variable
    }

    for (int i = 0; i < creature_config["bodySizeConfig"].size(); i++)
    {
        this->body_size_config.push_back(creature_config["bodySizeConfig"][i].as<int>());
    }

    // Initialize Creature
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
            head = body[b];
        }
        else if (b == body_size_config.size() - 1)
        {
            body[b]->prev == body[b - 1];
            body[b]->next == nullptr;
            tail = body[b];
        }
        else
        {
            body[b]->prev == body[b - 1];
            body[b]->next == body[b + 1];
        }
    }

    calculateVertices();
    body_vertices.resize(number_of_veritces);
}

void Creature::updateCreature(std::function<void(int, int, std::vector<BodyPart *> body)> behavior)
{
    // Custom behavior function
}

void Creature::updateCreature(int x, int y)
{
    BodyPart_setTarget(head, x, y);
    BodyPart_followTarget(head);
    for (int b = 1; b < body.size(); b++)
    {
        float body_angle = getDirection(body[b - 1], body[b]);
        float new_x = body[b - 1]->pos_x + (body_connection_length[0] * cos(body_angle));
        float new_y = body[b - 1]->pos_y + (body_connection_length[0] * sin(body_angle));

        BodyPart_updatePos(body[b], new_x, new_y);
    }
    setVertices();
}

void Creature::draw(SDL_Renderer *r, std::function<void()> cosmetic)
{
    // cosmetics
}

void Creature::draw(SDL_Renderer *r)
{
    fillPolygon(r, smooth_body_vertices, body_color);
    for (int v = 0; v < smooth_body_vertices.size(); v++)
    {
        if (v > 0)
        {
            SDL_SetRenderDrawColor(r, body_outline_color.r, body_outline_color.g, body_outline_color.b, body_outline_color.a);
            SDL_RenderDrawLine(r, smooth_body_vertices[v - 1].x, smooth_body_vertices[v - 1].y, smooth_body_vertices[v].x, smooth_body_vertices[v].y);
        }
    }
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

    for (int v = 0; v < (number_of_veritces / 2) - 2; v++)
    {
        if (v > 0)
        {
            angle = getDirection(body[v - 1], body[v]);

            // Side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle + degToRad(90)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle + degToRad(90)));
            body_vertices.at(v + 2) = {point_x, point_y};

            // Corresponding opposite side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle - degToRad(90)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle - degToRad(90)));
            body_vertices.at(number_of_veritces - (v + 2)) = {point_x, point_y};
        }
        else
        {
            // Side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle - degToRad(135)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle - degToRad(135)));
            body_vertices.at(v + 2) = {point_x, point_y};

            // Corresponding opposite side vertex
            point_x = body[v]->pos_x + (body[v]->circle.radius * cos(angle + degToRad(45)));
            point_y = body[v]->pos_y + (body[v]->circle.radius * sin(angle + degToRad(45)));
            body_vertices.at(number_of_veritces - (v + 2)) = {point_x, point_y};
        }
    }

    // Tail
    point_x = body.back()->pos_x + (body.back()->circle.radius * cos(angle));
    point_y = body.back()->pos_y + (body.back()->circle.radius * sin(angle));
    body_vertices.at(number_of_veritces / 2) = {point_x, point_y};

    int sm_fac = 3;

    smooth_body_vertices = generateChaikinCurve(body_vertices, sm_fac);
}