#include "../../include/node.hpp"

void Node_updatePos(Node *node, float x, float y)
{
    node->pos_x = x;
    node->pos_y = y;

    node->rect.x = (int)(node->pos_x - (node->rect.w / 2));
    node->rect.y = (int)(node->pos_y - (node->rect.h / 2));
}