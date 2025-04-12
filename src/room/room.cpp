#include "../../include/room/room.hpp"

void Room_intialize(Room *room, int id, int w, int h)
{
    room->room_id = id;
    room->room_x_tiles = w;
    room->room_y_tiles = h;
    room->room_w = room->room_x_tiles * tileWidth;
    room->room_w = room->room_x_tiles * tileHeight;

    for (int x = 0; x < room->room_x_tiles; x++)
    {
        std::vector<Tile*> room_tile_row;
        for (int y = 0; y < room->room_y_tiles; y++)
        {
            room_tile_row.push_back(new Tile(x * tileWidth, y * tileHeight, tileWidth, tileHeight, TileType::EMPTY));
        }
        room->Room_tiles.push_back(room_tile_row);
    }
}

void Room_draw(SDL_Renderer *renderer, Room *room)
{
    for (int x = 0; x < room->room_x_tiles; x++)
    {
        for (int y = 0; y < room->room_y_tiles; y++)
        {
            Tile_draw(renderer, room->Room_tiles[x][y]);
        }
    }
}