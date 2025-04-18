#pragma once

#include <SDL2/SDL.h>

#include "../node.hpp"
#include "../utils.hpp"

#define DEFAULT_BODY_SIZE 10.0f

enum BodyPartType
{
    HEAD = 0,
    BODY,
    TAIL
};

struct BodyPart : public Node
{
    Circle circle;
    Node *target;
    BodyPart *prev;
    BodyPart *next;

    BodyPart(int size, BodyPartType type):Node(0, 0, DEFAULT_BODY_SIZE, DEFAULT_BODY_SIZE)
    {
        circle.x = pos_x;
        circle.y = pos_y;
        circle.radius = size;
        circle.c = color;

        if(type == BodyPartType::HEAD)
        {
            target = new Node(pos_x, pos_y, 10.0f, 10.0f, COLOR_RED);
        }
        else
        {
            target = nullptr;
        }
    }
};
typedef struct BodyPart BodyPart;

void BodyPart_setTarget(BodyPart *b, int t_x, int t_y);
void BodyPart_drawTarget(SDL_Renderer *r, BodyPart *b);
void BodyPart_draw(SDL_Renderer *r, BodyPart *b);
void BodyPart_followTarget(BodyPart *b);
void BodyPart_updatePos(BodyPart *b, float x, float y);