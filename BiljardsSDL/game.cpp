#include"game.h"
#include <SDL_ttf.h>

game::game ()
{
 window = NULL;
 Running = true;
}

int game::OnExecute ()  {
  if ( OnInit()  == false )  {
    return -1;
  }




  if (LoadContent () == false) {
    return -1;
  }
  //matrixPrint(POS_POCKET_CORNER_BALLS);

  FPS = 0;
  maxDt = 5; //max Dt in ms
  time = SDL_GetTicks();
  previousTime = SDL_GetTicks();

  balls[0].setVelocity(vector<double>{500,10});

  while ( Running )  {
        while ( SDL_PollEvent ( & Event ) )  {
            OnEvent ( & Event ) ;
        }

   OnLoop () ;
   OnRender () ;
  }

 Cleanup () ;

 return 0;
}

int main ( int argc , char * argv [ ] )  {
 game theGame;

 return theGame.OnExecute () ;
}
