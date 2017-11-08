#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"includes.h"

class game
{
private :
 bool Running;
 const int SCREEN_WIDTH = 1440;
 const int SCREEN_HEIGHT = 900;
 const double TABLE_WIDTH_MM = 3569;
 const double TABLE_HEIGH_MM = 1778;
 const int TABLE_WIDTH = 1000;
 const int TABLE_HEIGHT = TABLE_WIDTH*(TABLE_HEIGH_MM/TABLE_WIDTH_MM);
 const int CORNER_X = (SCREEN_WIDTH-TABLE_WIDTH)/2;
 const int CORNER_Y = (SCREEN_HEIGHT-TABLE_HEIGHT)/2;
 SDL_Window * window;
 SDL_Renderer * renderer;
 SDL_Event Event;
 int time;
public :
 game () ;
  // virtual ~game () ;
 int OnExecute () ;
 bool OnInit () ;
 bool LoadContent () ;
 void OnEvent ( SDL_Event * Event ) ;
 void OnLoop () ;
 void OnRender () ;
 void Cleanup () ;

} ;
#endif // GAME_H_INCLUDED
