#include <SDL.h>
#include <SDL_image.h>
#include"game.h"

/**< Based on the following source: https://stackoverflow.com/questions/28346989/drawing-and-filling-a-circle */
void game::draw_circle(SDL_Renderer * renderer, SDL_Point center, int radius, SDL_Color color, int ballNumber) {
    //draw a filled circle with the desired color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int h = 0; h < radius * 2; h++) {
        for (int w = 0; w < radius * 2; w++) {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
            }
        }
    }
    if (ballNumber>0) {
        //if ball number is greater than 8 make 2 white areas on the ball.
        if (ballNumber > 8){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            for (int h = 0; h < radius * 2; h++) {
                for (int w = 0; w < radius * 2; w++) {
                    int dx = radius - w; // horizontal offset
                    int dy = radius - h; // vertical offset
                    if ((dx*dx + dy*dy) <= (radius * radius) && ((h<radius*0.25) || (h>radius*(2-0.25))))
                    {
                        SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
                    }
                }
            }
        }

        //Draw small white circle for the number to be displayed in
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int h = 0; h < radius * 2; h++) {
            for (int w = 0; w < radius * 2; w++) {
                int dx = radius - w; // horizontal offset
                int dy = radius - h; // vertical offset
                if ((dx*dx + dy*dy) <= (radius * radius)/3)
                {
                    SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
                }
            }
        }


        //Render the number of the ball
        SDL_Color textColor = {.r = 0, .g = 0, .b = 0};
        int texW = 0;
        int texH = 0;
        char integer_string[32];
        sprintf(integer_string, "%d", ballNumber);
        surface = TTF_RenderText_Solid(ballFont, integer_string , textColor);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = { center.x-texW/2, center.y-texH/2, texW, texH };
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_DestroyTexture(texture);
    }


}
