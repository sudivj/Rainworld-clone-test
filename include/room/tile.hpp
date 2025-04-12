#pragma once

#include <SDL2/SDL.h>

#include "../colors.hpp"

enum TileType
{
    EMPTY = 0,
    WALL
};

struct Tile
{
    int pos_x, pos_y;

    bool occupied = false;

    TileType type;

    SDL_Rect rect;
    SDL_Color tile_color = {.r = COLOR_WHITE.r, .g = COLOR_WHITE.g, .b = COLOR_WHITE.b, .a = 100};

    Tile(int x, int y, int w, int h, TileType t)
    {
        pos_x = x;
        pos_y = y;
        rect.w = w;
        rect.h = h;
        rect.x = pos_x;
        rect.y = pos_y;
        type = t;
    }
};
typedef struct Tile Tile;

void Tile_draw(SDL_Renderer *renderer, Tile *tile);