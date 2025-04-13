#include <iostream>

#include "../include/game.hpp"

bool game(SDL_Renderer *renderer, int w, int h)
{
    bool quit = false;

    std::cout << mouseX << " : " << mouseY << std::endl;

    Room r;
    Room_intialize(&r, 1, SCREEN_WIDTH / tileWidth, SCREEN_HEIGHT / tileHeight);

    Node n(10.0f, 10.0f, 10, 10);
    Node_updatePos(&n, 50.0f, 50.0f);

    Circle cir = {.x = 100, .y = 100, .radius = 20, .c = COLOR_ORANGE};

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

        Room_draw(renderer, &r);

        // Node_updatePos(&n, (float)mouseX, (float)mouseY);
        Node_printData(renderer, &n);


        renderText(renderer, 10, 10, mouseXChar.c_str(), COLOR_WHITE);
        renderText(renderer, 10, 20, mouseYChar.c_str(), COLOR_WHITE);

        float dir_value = getDirection(n.pos_x, n.pos_y, mouseX, mouseY);
        std::string dir = std::to_string(dir_value);
        renderText(renderer, 10, 40, dir.c_str(), COLOR_WHITE);
        std::string dist = std::to_string(getDistance(n.pos_x, n.pos_y, mouseX, mouseY));
        renderText(renderer, 10, 50, dist.c_str(), COLOR_WHITE);

        SDL_SetRenderDrawColor(renderer, COLOR_ORANGE.r, COLOR_ORANGE.g, COLOR_ORANGE.b, COLOR_ORANGE.a);
        int dir_x = n.pos_x + (20 * cos(dir_value));
        int dir_y = n.pos_y + (20 * sin(dir_value));
        SDL_RenderDrawLine(renderer, n.pos_x, n.pos_y, dir_x, dir_y);

        SDL_SetRenderDrawColor(renderer, n.color.r, n.color.g, n.color.b, n.color.a);
        SDL_RenderFillRect(renderer, &n.rect);

        cir.x = mouseX; 
        cir.y = mouseY;
        Circle_draw(renderer, &cir);

        SDL_RenderPresent(renderer);
    }

    return true;
}

