#include "../../include/body/bodypart.hpp"

void BodyPart_setTarget(BodyPart *b, int t_x, int t_y)
{
    Node_updatePos(b->target, t_x, t_y);
}

void BodyPart_drawTarget(SDL_Renderer *r, BodyPart *b)
{
    SDL_Color c = b->target->color;
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(r, &b->target->rect);
}

void BodyPart_draw(SDL_Renderer *r, BodyPart *b)
{
    SDL_Color c = b->color;
    b->circle.filled = true;
    // SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
    // SDL_RenderFillRect(r, &b->rect);

    Circle_draw(r, &b->circle);
}

void BodyPart_followTarget(BodyPart *b)
{
    Node_updatePos(b, b->target->pos_x, b->target->pos_y);
    b->circle.x = b->pos_x;
    b->circle.y = b->pos_y;
}

void BodyPart_updatePos(BodyPart *b, float x, float y)
{
    Node_updatePos(b, x, y);
    b->circle.x = b->pos_x;
    b->circle.y = b->pos_y;
}