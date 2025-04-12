#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

#include "include/game.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized!\nSDL_Error:\n"
                  << SDL_GetError() << std::endl;

        return 0;
    }

    SDL_Window *window = SDL_CreateWindow("test-2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cout << "Window could not be created!\nSDL_Error:\n"
                  << SDL_GetError() << std::endl;
    }
    else
    {
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer)
        {
            std::cout << "Renderer could not be created!\nSDL_Error:\n"
                  << SDL_GetError() << std::endl;
        }
        else
        {
            game(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

            SDL_DestroyRenderer(renderer);
        }

        SDL_DestroyWindow(window);
    }

    SDL_Quit();

    return 0;
}
