#include "../../include/room/tile.hpp"

void Tile_draw(SDL_Renderer *renderer, Tile *tile)
{
    SDL_Color c = tile->tile_color;
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    if (tile->occupied)
    {
        SDL_RenderFillRect(renderer, &tile->rect);
    }
    else
    {
        SDL_RenderDrawRect(renderer, &tile->rect);
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}