#ifndef DRAWCIRCLE_H_INCLUDED
#define DRAWCIRCLE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include"game.h"

void draw_circle(SDL_Renderer * renderer, SDL_Point center, int radius, SDL_Color color);

#endif // DRAWCIRCLE_H_INCLUDED
