#include"game.h"
#include <SDL_ttf.h>

void game::OnEnd()
{
    double desiredFPS = 30;
    int desiredTicks = 1000/desiredFPS;
    int tickBeforeLastRender = SDL_GetTicks();
    for (int n=0; n<300; n++) {
        while ( SDL_PollEvent ( & Event ) )  {
            OnEvent ( & Event ) ;
        }
        if (ForceQuit){
            return;
        }

        //Clear Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);






        //Display winning message
        int texW = 0;
        int texH = 0;
        SDL_Rect dstrect;

        char* message;
        //cout << firstPlayerWins << endl;
        if (firstPlayerWins) {
            message = "PLAYER 1 WINS";
        }
        else {
            message = "PLAYER 2 WINS";
        }


        SDL_Color textColor = {.r = 255, .g = 255, .b = 255};
        surface = TTF_RenderText_Solid(font, message , textColor);
        texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        dstrect = { 0, 0, texW, texH };

        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_DestroyTexture(texture);









        int ticksLeft = desiredTicks - (SDL_GetTicks()-tickBeforeLastRender);
        if (ticksLeft > 0) {
            SDL_Delay(ticksLeft);
        }
        tickBeforeLastRender = SDL_GetTicks();
        SDL_RenderPresent( renderer );
    }
}
