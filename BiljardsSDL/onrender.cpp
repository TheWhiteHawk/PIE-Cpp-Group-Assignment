#include"game.h"
#include"drawcircle.h"

void game::OnRender()
{
    //Clear Render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Render red filled quad
    SDL_Rect fillRect = { CORNER_X, CORNER_Y, TABLE_WIDTH, TABLE_HEIGHT };
	SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
	SDL_RenderFillRect( renderer, &fillRect );

    //Draw blue horizontal line
	SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0xFF, 0xFF );
	SDL_RenderDrawLine( renderer,140+ time/10, 30, 140+45, 60+time/10 );




    SDL_Point center = {200+time/5, 200};
    int radius = time/10;
    SDL_Color color = {.r = 255, .g = 255, .b = 255};
    draw_circle(renderer, center, radius, color);





    SDL_RenderPresent( renderer );
}
