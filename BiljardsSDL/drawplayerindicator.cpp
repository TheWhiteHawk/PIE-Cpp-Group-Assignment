#include <SDL.h>
#include <SDL_image.h>
#include"game.h"

void game::DrawPlayerIndicator(SDL_Renderer * renderer, double X, double Y, double W , double H)
{
    SDL_SetRenderDrawColor(renderer, 255, 0,0, 255);
    //SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
    for (int x = 0; x < W; x++)
    {
        for (int y = 0; y < H; y++)
        {
            if ((y+(H/(2*W)*x) < H) && (y-(H/(2*W)*x) > 0))
            {
                SDL_RenderDrawPoint(renderer, X + x, Y + y);
            }
        }
    }
}
