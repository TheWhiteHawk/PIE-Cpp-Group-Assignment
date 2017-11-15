#include"game.h"

void game::Cleanup ()
{
 TTF_CloseFont(font);
 TTF_CloseFont(ballFont);
 SDL_DestroyTexture(texture);
 SDL_FreeSurface(surface);
 SDL_DestroyRenderer ( renderer ) ;
 SDL_DestroyWindow ( window ) ;
 TTF_Quit();
 SDL_Quit () ;
}
