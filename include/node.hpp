#pragma once

#include <SDL2/SDL.h>
#include "colors.hpp"
#include "utils.hpp"

struct Node
{
    float pos_x, pos_y;
    int room_pos_x, room_pos_y;

    float direction_to_target;

    SDL_Rect rect;
    SDL_Color color;

    Node(float x, float y, int w, int h, SDL_Color c)
    {
        pos_x = x;
        pos_y = y;

        rect.w = w;
        rect.h = h;

        rect.x = (int)(pos_x - (w / 2));
        rect.y = (int)(pos_y - (h / 2));

        color = c;
    }

    Node(float x, float y, int w, int h)
    {
        pos_x = x;
        pos_y = y;

        rect.w = w;
        rect.h = h;

        rect.x = (int)(pos_x - (w / 2));
        rect.y = (int)(pos_y - (h / 2));

        color = COLOR_WHITE;
    }
};
typedef struct Node node;

void Node_updatePos(Node *node, float x, float y);
void Node_printData(SDL_Renderer *renderer, Node *node);