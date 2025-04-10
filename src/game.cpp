#include <iostream>

#include "../include/game.hpp"

bool game(SDL_Renderer *renderer, int w, int h)
{
    bool quit = false;

    std::cout << mouseX << " : " << mouseY << std::endl;

    Node n(10.0f, 10.0f, 10, 10);
    Node_updatePos(&n, 50.0f, 50.0f);

    //Game Loop
    while (!quit)
    {
        SDL_Event game_event;

        getMouseData();

        while (SDL_PollEvent(&game_event))
        {
            if (game_event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        setBackGroundColor(renderer, COLOR_BLACK);

        Node_updatePos(&n, (float)mouseX, (float)mouseY);

        renderText(renderer, 10, 10, mouseXChar.c_str(), COLOR_WHITE);
        renderText(renderer, 10, 20, mouseYChar.c_str(), COLOR_WHITE);

        SDL_SetRenderDrawColor(renderer, n.color.r, n.color.g, n.color.b, n.color.a);
        SDL_RenderFillRect(renderer, &n.rect);

        SDL_RenderPresent(renderer);
    }

    return true;
}

