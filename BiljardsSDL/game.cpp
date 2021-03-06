#include"game.h"
#include <SDL_ttf.h>

game::game ()
{
 window = NULL;
 Running = true;
 ForceQuit = false;
}

//runs constantly when called in the main loop
int game::OnExecute ()  {
  if ( OnInit()  == false )  { //initialize stuff
    return -1;
  }



  //loads/initialize content
  if (LoadContent () == false) {
    return -1;
  }

  FPS = 0; // set FPS to zero
  maxDt = 2; //max Dt in ms
  time = SDL_GetTicks(); //set time to the current tick
  previousTime = SDL_GetTicks(); //set previousTime to the current tick

  //the loop which is the build block of the whole program, run on loop, on event and on render.
  while ( Running )  {
        OnLoop () ;
        while ( SDL_PollEvent ( & Event ) )  {
            OnEvent ( & Event ) ;
        }


   OnRender () ;
 }
 //if the game was not forced quit and a winner was declared show the end screen
 if (gameEnd && !ForceQuit){
    OnEnd () ;
 }

//cleanup
 Cleanup () ;

 return 0;
}

//set running to false
void game::stopRunning(){
    Running = false;
}

//Main loop, arguments needed for the game to work.
int main ( int argc , char * argv [ ] )  {

 game theGame;

 return theGame.OnExecute () ;
}
