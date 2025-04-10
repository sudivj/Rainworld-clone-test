#include "../include/utils.hpp"

int mouseX, mouseY;
std::string mouseXChar, mouseYChar;

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