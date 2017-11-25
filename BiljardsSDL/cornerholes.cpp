#include <SDL.h>
#include <SDL_image.h>
#include"game.h"

//Draw corner holes
void game::DrawCornerHoles(SDL_Renderer * renderer)
{
    int B = CORNER_BALL_RATIO*BALL_RADIUS;
    SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);

    //left pockets
    for (int x = CORNER_X-B-1; x < POCKET_CORNER_BALLS[0].getPosition()[0]+1; x++) {
        //top left pocket
        for (int y = CORNER_Y-B-1; y < POCKET_CORNER_BALLS[0].getPosition()[0]+POCKET_CORNER_BALLS[0].getPosition()[1]-x; y++) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
        //bottom left pocket
        for (int y = POCKET_CORNER_BALLS[3].getPosition()[1]-POCKET_CORNER_BALLS[3].getPosition()[0]+x; y < CORNER_Y+TABLE_HEIGHT+B; y++) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    //right pockets
    for (int x = POCKET_CORNER_BALLS[6].getPosition()[0]; x < CORNER_X+TABLE_WIDTH+B; x++) {
        //top right pocket
        for (int y = CORNER_Y-B-1; y < POCKET_CORNER_BALLS[6].getPosition()[1]-POCKET_CORNER_BALLS[6].getPosition()[0]+x; y++) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
        //bottom right pocket
        for (int y = POCKET_CORNER_BALLS[9].getPosition()[0]+POCKET_CORNER_BALLS[9].getPosition()[1]-x; y < CORNER_Y+TABLE_HEIGHT+B; y++) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

}
