#include"game.h"
void game::OnLoop ()
{
    time = SDL_GetTicks();
    FPS = 1000/(time-previousTime);
    cout << "FPS: " << FPS << endl;
    previousTime = time;


}
