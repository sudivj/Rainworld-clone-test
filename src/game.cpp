#include <iostream>

#include "../include/game.hpp"
#include "../include/creature.hpp"

bool game(SDL_Renderer *renderer, int w, int h)
{
    bool quit = false;

    Room r;
    Room_intialize(&r, 1, SCREEN_WIDTH / tileWidth, SCREEN_HEIGHT / tileHeight);

    Creature c("include/creatures/data.yml");
    c.initializeCreature();

    // Game Loop
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

        float fps = getFPS();

        setBackGroundColor(renderer, COLOR_BLACK);

        renderText(renderer, 10, 10, mouseXChar.c_str(), COLOR_WHITE);
        renderText(renderer, 10, 20, mouseYChar.c_str(), COLOR_WHITE);
        renderText(renderer, 10, 30, std::to_string(fps).c_str(), COLOR_WHITE);

        c.updateCreature(mouseX, mouseY);
        c.draw(renderer);

        SDL_RenderPresent(renderer);
    }

    return true;
}
