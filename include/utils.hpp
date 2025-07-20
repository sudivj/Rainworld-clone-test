#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <yaml-cpp/yaml.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "colors.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef std::pair<int, int> point;

extern int mouseX, mouseY;
extern std::string mouseXChar, mouseYChar;

extern int tileWidth;
extern int tileHeight;

void renderText(SDL_Renderer *renderer, int x, int y, const char *s, SDL_Color textColor);
void setBackGroundColor(SDL_Renderer *renderer, SDL_Color color);
void getMouseData();

struct Circle
{
    int x, y;
    int radius;
    bool filled = false;
    SDL_Color c;
};
typedef struct Circle Circle;

void setPixel(SDL_Renderer *renderer ,int x, int y, SDL_Color c);

void Circle_draw(SDL_Renderer *renderer, Circle *circle);

void fillPolygon(SDL_Renderer *renderer, std::vector<SDL_Point> points, SDL_Color fill_color);

float getFPS();