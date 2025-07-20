#include "../include/utils.hpp"

int mouseX, mouseY;
std::string mouseXChar, mouseYChar;

int tileWidth = 20;
int tileHeight = 20;

int oldtime = 0, newtime = 0;

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

void setPixel(SDL_Renderer *renderer ,int x, int y, SDL_Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderDrawPoint(renderer, x, y);
}


// Draw or fill a circle
// Note: Below code is taken from https://medium.com/@trey.tomes/bresenhams-circle-algorithm-2153b32a0ecf

void drawOctants(SDL_Renderer *r, Circle *cir, int o_x, int o_y)
{
    setPixel(r, cir->x + o_x    , cir->y + o_y, cir->c);
    setPixel(r, cir->x - o_x - 1, cir->y + o_y, cir->c);
    setPixel(r, cir->x + o_x    , cir->y - o_y - 1, cir->c);
    setPixel(r, cir->x - o_x - 1, cir->y - o_y - 1, cir->c);

    setPixel(r, cir->x + o_y    , cir->y + o_x, cir->c);
    setPixel(r, cir->x - o_y - 1, cir->y + o_x, cir->c);
    setPixel(r, cir->x + o_y    , cir->y - o_x - 1, cir->c);
    setPixel(r, cir->x - o_y - 1, cir->y - o_x - 1, cir->c);
}

void fillOctants(SDL_Renderer *r, Circle *cir, int o_x, int o_y)
{
    for (int i = cir->x - o_x; i < cir->x + o_x; i++) setPixel(r, i, cir->y + o_y, cir->c);
    for (int i = cir->x - o_x; i < cir->x + o_x; i++) setPixel(r, i, cir->y - o_y, cir->c);

    for (int i = cir->x - o_y; i < cir->x + o_y; i++) setPixel(r, i, cir->y + o_x, cir->c);
    for (int i = cir->x - o_y; i < cir->x + o_y; i++) setPixel(r, i, cir->y - o_x, cir->c);
}

void Circle_draw(SDL_Renderer *renderer, Circle *circle)
{
    int o_x = 0, o_y = circle->radius;
    int d = 3 - 2 * circle->radius;

    !circle->filled ? drawOctants(renderer, circle, o_x, o_y) : fillOctants(renderer, circle, o_x, o_y);

    while (o_y >= o_x)
    {
        o_x++;

        if(d > 0)
        {
            o_y--;
            d = d + 4 * (o_x - o_y) + 10;
        }
        else
        {
            d = d + 4 * o_x + 6;
        }

        !circle->filled ? drawOctants(renderer, circle, o_x, o_y) : fillOctants(renderer, circle, o_x, o_y);
    }
}

float getFPS()
{
    oldtime = newtime;
    newtime = SDL_GetTicks();
    float fps_val = 1.f/((float)(newtime - oldtime) / 1000.f);
    std::string fps = "fps: " + std::to_string(fps_val);
    // SDL_Log(fps.c_str());
    return fps_val;
}

Uint32 ColourToUint(int R, int G, int B) // https://gist.github.com/exsersewo/ac1b4ff4470a7f6b443cef34e26d72ad
{
	return (Uint32)((R << 16) + (G << 8) + (B << 0));
}

void fillPolygon(SDL_Renderer *renderer, std::vector<SDL_Point> points, SDL_Color fill_color)
{
    std::vector<Sint16> vx = {}, vy = {};
    for (int i = 0; i < points.size(); i++)
    {
        vx.push_back(points[i].x);
        vy.push_back(points[i].y);
    }
    filledPolygonRGBA(renderer, vx.data(), vy.data(), points.size(), fill_color.r, fill_color.g, fill_color.b, fill_color.a);
}