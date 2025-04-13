#include "../include/utils.hpp"

int mouseX, mouseY;
std::string mouseXChar, mouseYChar;

int tileWidth = 20;
int tileHeight = 20;

void renderText(SDL_Renderer *renderer, int x, int y, const char *s, SDL_Color textColor)
{
    stringRGBA(renderer, x, y, s, textColor.r, textColor.g, textColor.b, textColor.a);
}

void setBackGroundColor(SDL_Renderer *renderer, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void getMouseData()
{
    SDL_GetMouseState(&mouseX, &mouseY);
    mouseXChar = std::to_string(mouseX);
    mouseYChar = std::to_string(mouseY);
}

void setPixel(SDL_Renderer *renderer ,int x, int y, SDL_Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderDrawPoint(renderer, x, y);
}


// Draw or fill a circle
// Note: Below code is taken from https://medium.com/@trey.tomes/bresenhams-circle-algorithm-2153b32a0ecf

void drawOctants(SDL_Renderer *r, Circle *cir, int o_x, int o_y)
{
    setPixel(r, cir->x + o_x, cir->y + o_y, cir->c);
    setPixel(r, cir->x - o_x, cir->y + o_y, cir->c);
    setPixel(r, cir->x + o_x, cir->y - o_y, cir->c);
    setPixel(r, cir->x - o_x, cir->y - o_y, cir->c);

    setPixel(r, cir->x + o_y, cir->y + o_x, cir->c);
    setPixel(r, cir->x - o_y, cir->y + o_x, cir->c);
    setPixel(r, cir->x + o_y, cir->y - o_x, cir->c);
    setPixel(r, cir->x - o_y, cir->y - o_x, cir->c);
}

void fillOctants(SDL_Renderer *r, Circle *cir, int o_x, int o_y)
{
    for (int i = cir->x - o_x; i < cir->x + o_x; i++) setPixel(r, i, cir->y + o_y, cir->c);
    for (int i = cir->x - o_x; i < cir->x + o_x; i++) setPixel(r, i, cir->y - o_y, cir->c);

    for (int i = cir->x - o_y; i < cir->x + o_y; i++) setPixel(r, i, cir->y + o_x, cir->c);
    for (int i = cir->x - o_y; i < cir->x + o_y; i++) setPixel(r, i, cir->y - o_x, cir->c);
}

void Circle_draw(SDL_Renderer *renderer, Circle *circle)
{
    int o_x = 0, o_y = circle->radius;
    int d = 3 - 2 * circle->radius;

    !circle->filled ? drawOctants(renderer, circle, o_x, o_y) : fillOctants(renderer, circle, o_x, o_y);

    while (o_y >= o_x)
    {
        o_x++;

        if(d > 0)
        {
            o_y--;
            d = d + 4 * (o_x - o_y) + 10;
        }
        else
        {
            d = d + 4 * o_x + 6;
        }

        !circle->filled ? drawOctants(renderer, circle, o_x, o_y) : fillOctants(renderer, circle, o_x, o_y);
    }
}