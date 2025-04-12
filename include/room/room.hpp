#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "tile.hpp"
#include "../utils.hpp"

struct Room
{
    int room_id;
    
    int room_x_tiles;
    int room_y_tiles;

    int room_w;
    int room_h;

    std::vector<std::vector<Tile*>> Room_tiles;
};
typedef struct Room Room;

void Room_intialize(Room *room, int id, int w, int h);
void Room_draw(SDL_Renderer *renderer, Room *room);