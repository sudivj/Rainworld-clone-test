#include <iostream>

#include "../include/game.hpp"
#include "../include/creature.hpp"

bool game(SDL_Renderer *renderer, int w, int h)
{
    bool quit = false;

    Room r;
    Room_intialize(&r, 1, SCREEN_WIDTH / tileWidth, SCREEN_HEIGHT / tileHeight);

    // BodyPart b(20, BodyPartType::HEAD);
    // Snake s;
    // s.initializeSnake();

    Creature c("include/creatures/data.yml");
    c.initializeCreature();

    // Node n1(100, 100, 10, 10);
    // Node n2(100, 100, 10, 10);
    // Node n3(100, 100, 10, 10);
    // Node n4(100, 100, 10, 10);
    // Node n5(100, 100, 10, 10);
    // Node n6(100, 100, 10, 10);

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

        // Room_draw(renderer, &r);

        renderText(renderer, 10, 10, mouseXChar.c_str(), COLOR_WHITE);
        renderText(renderer, 10, 20, mouseYChar.c_str(), COLOR_WHITE);
        renderText(renderer, 10, 30, std::to_string(fps).c_str(), COLOR_WHITE);

        // BodyPart_setTarget(&b, mouseX, mouseY);
        // BodyPart_drawTarget(renderer, &b);
        // BodyPart_draw(renderer, &b);
        // Node_printData(renderer, b.target);
        // BodyPart_followTarget(&b);

        // std::string consoleOutput = "m_x: " + mouseXChar + " m_y: " + mouseYChar;
        // SDL_Log(consoleOutput.c_str());

        // s.update(mouseX, mouseY);
        // s.draw(renderer);
        c.updateCreature(mouseX, mouseY);
        c.draw(renderer);

        // SDL_SetRenderDrawColor(renderer, COLOR_WHITE.r, COLOR_WHITE.g, COLOR_WHITE.b, COLOR_WHITE.a);

        // int fix_x = 100;
        // int fix_y = 100;

        // Node_updatePos(&n1, mouseX, mouseY);
        // float a = getDirection(&n1, &n2);
        // float new_x = n1.pos_x + (40 * cos(a));
        // float new_y = n1.pos_y + (40 * sin(a));
        // Node_updatePos(&n2, new_x, new_y);
        // a = getDirection(&n2, &n3);
        // new_x = n2.pos_x + (40 * cos(a));
        // new_y = n2.pos_y + (40 * sin(a));
        // Node_updatePos(&n3, new_x, new_y);
        // a = getDirection(&n3, &n4);
        // new_x = n3.pos_x + (40 * cos(a));
        // new_y = n3.pos_y + (40 * sin(a));
        // Node_updatePos(&n4, new_x, new_y);
        // a = getDirection(&n4, &n5);
        // new_x = n4.pos_x + (40 * cos(a));
        // new_y = n4.pos_y + (40 * sin(a));
        // Node_updatePos(&n5, new_x, new_y);
        // a = getDirection(&n5, &n6);
        // new_x = n5.pos_x + (40 * cos(a));
        // new_y = n5.pos_y + (40 * sin(a));
        // Node_updatePos(&n6, new_x, new_y);

        // Node_updatePos(&n6, fix_x, fix_y);
        // a = getDirection(&n6, &n5);
        // new_x = n6.pos_x + (40 * cos(a));
        // new_y = n6.pos_y + (40 * sin(a));
        // Node_updatePos(&n5, new_x, new_y);
        // a = getDirection(&n5, &n4);
        // new_x = n5.pos_x + (40 * cos(a));
        // new_y = n5.pos_y + (40 * sin(a));
        // Node_updatePos(&n4, new_x, new_y);
        // a = getDirection(&n4, &n3);
        // new_x = n4.pos_x + (40 * cos(a));
        // new_y = n4.pos_y + (40 * sin(a));
        // Node_updatePos(&n3, new_x, new_y);
        // a = getDirection(&n3, &n2);
        // new_x = n3.pos_x + (40 * cos(a));
        // new_y = n3.pos_y + (40 * sin(a));
        // Node_updatePos(&n2, new_x, new_y);
        // a = getDirection(&n2, &n1);
        // new_x = n2.pos_x + (40 * cos(a));
        // new_y = n2.pos_y + (40 * sin(a));
        // Node_updatePos(&n1, new_x, new_y);

        // SDL_RenderFillRect(renderer, &n1.rect);
        // SDL_RenderFillRect(renderer, &n2.rect);
        // SDL_RenderFillRect(renderer, &n3.rect);
        // SDL_RenderFillRect(renderer, &n4.rect);
        // SDL_RenderFillRect(renderer, &n5.rect);
        // SDL_RenderFillRect(renderer, &n6.rect);

        SDL_RenderPresent(renderer);
    }

    return true;
}
