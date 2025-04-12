#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

extern int mouseX, mouseY;
extern std::string mouseXChar, mouseYChar;

extern int tileWidth;
extern int tileHeight;

void renderText(SDL_Renderer *renderer, int x, int y, const char *s, SDL_Color textColor);
void setBackGroundColor(SDL_Renderer *renderer, SDL_Color color);
void getMouseData();