#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

extern int mouseX, mouseY;
extern std::string mouseXChar, mouseYChar;

void renderText(SDL_Renderer *renderer, int x, int y, const char *s, SDL_Color textColor);
void setBackGroundColor(SDL_Renderer *renderer, SDL_Color color);
void getMouseData();