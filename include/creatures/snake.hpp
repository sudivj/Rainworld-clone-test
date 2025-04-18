#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "../creature.hpp"
#include "../utils.hpp"
#include "../math_functions.hpp"
#include "../colors.hpp"

struct Snake : public Creature
{
private:
    int number_of_veritces;
    void calculateVertices();
public:
    int body_connection_length = 20;
    std::vector<int> body_size_config = {10, 15, 10, 10, 7, 7, 7, 5, 5, 5, 5, 5, 5};
    std::vector<BodyPart *> body;
    std::vector<std::pair<int, int>> body_vertices;

    BodyPart *snake_head;
    BodyPart *snake_tail;

    void initializeSnake();
    void update(int x, int y);
    void draw(SDL_Renderer *r);
    void printData();
    void setVertices();
};
typedef struct Snake Snake;