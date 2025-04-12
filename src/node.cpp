#include "../include/node.hpp"

void Node_updatePos(Node *node, float x, float y)
{
    node->pos_x = x;
    node->pos_y = y;

    node->rect.x = (int)(node->pos_x - (node->rect.w / 2));
    node->rect.y = (int)(node->pos_y - (node->rect.h / 2));

    node->room_pos_x = node->pos_x / tileWidth;
    node->room_pos_y = node->pos_y / tileHeight;
}

void Node_printData(SDL_Renderer *renderer, Node *node)
{
    int x_offset = 0;
    if (node->pos_x + 160 < SCREEN_WIDTH)
    {
        x_offset = 0;
    }
    else
    {
        x_offset = -160;
    }
    if (node->pos_y - 50 > 0)
    {
        std::string data = "pos_x: " + std::to_string(node->pos_x);
        renderText(renderer, node->pos_x + x_offset, node->pos_y - 20, data.c_str(), COLOR_WHITE);
        data = "pos_y: " + std::to_string(node->pos_y);
        renderText(renderer, node->pos_x + x_offset, node->pos_y - 30, data.c_str(), COLOR_WHITE);
        data = "room_x: " + std::to_string(node->room_pos_x);
        renderText(renderer, node->pos_x + x_offset, node->pos_y - 40, data.c_str(), COLOR_WHITE);
        data = "room_y: " + std::to_string(node->room_pos_y);
        renderText(renderer, node->pos_x + x_offset, node->pos_y - 50, data.c_str(), COLOR_WHITE);
    }
    else
    {
        std::string data = "pos_x: " + std::to_string(node->pos_x);
        renderText(renderer, node->pos_x + x_offset, node->pos_y + 20, data.c_str(), COLOR_WHITE);
        data = "pos_y: " + std::to_string(node->pos_y);
        renderText(renderer, node->pos_x + x_offset, node->pos_y + 30, data.c_str(), COLOR_WHITE);
        data = "room_x: " + std::to_string(node->room_pos_x);
        renderText(renderer, node->pos_x + x_offset, node->pos_y + 40, data.c_str(), COLOR_WHITE);
        data = "room_y: " + std::to_string(node->room_pos_y);
        renderText(renderer, node->pos_x + x_offset, node->pos_y + 50, data.c_str(), COLOR_WHITE);
    }
}