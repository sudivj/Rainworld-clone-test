#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <SDL2/SDL.h>
#include <yaml-cpp/yaml.h>

#include "body/bodypart.hpp"
#include "math_functions.hpp"
#include "utils.hpp"
#include "curves/curves.hpp"

enum CreatureStatus
{
    IDLING = 0,
    HUNTING,
    SEARCHING,
    SLEEPING
};

struct Creature
{
    YAML::Node creature_config;
    int number_of_veritces;

    int target_x, target_y;

    std::string creature_name;
    CreatureStatus status = CreatureStatus::IDLING;

    bool is_alive = true;
    bool is_variable_body_length;
    bool has_legs;

    std::vector<int> body_connection_length;
    std::vector<int> body_size_config;
    std::vector<BodyPart *> body;
    std::vector<point> body_vertices;
    std::vector<SDL_Point> smooth_body_vertices;

    SDL_Color body_color = {};
    SDL_Color body_outline_color = {};

    BodyPart *head;
    BodyPart *tail;

    Creature(std::string pathname)
    {
        creature_config = YAML::LoadFile(pathname);
    }
    Creature()
    {

    }

    void calculateVertices();
    void initializeCreature();
    void updateCreature(std::function<void(int, int, std::vector<BodyPart *> body)> behavior);
    void updateCreature(int x, int y);
    void draw(SDL_Renderer *r);
    void draw(SDL_Renderer *r, std::function<void()> cosmetic);
    void setVertices();
};
typedef struct Creature Creature;