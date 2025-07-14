#pragma once

#include <iostream>
#include <vector>

#include "body/bodypart.hpp"
#include "math_functions.hpp"
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
    int number_of_veritces;

    std::string creatureName;
    CreatureStatus status = CreatureStatus::IDLING;
    bool alive = true;

    int body_connection_length;
    std::vector<int> body_size_config;
    std::vector<BodyPart *> body;
    std::vector<point> body_vertices;
    std::vector<point> smooth_body_vertices;

    BodyPart *head;
    BodyPart *tail;

    void calculateVertices();
    void setVertices();
};
typedef struct Creature Creature;