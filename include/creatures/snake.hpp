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
public:

    BodyPart *snake_head;
    BodyPart *snake_tail;

    void initializeSnake();
    void update(int x, int y);
    void draw(SDL_Renderer *r);
    void printData();
};
typedef struct Snake Snake;