#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"includes.h"
#include <math.h>
#include "TempTable.h"

class game : public TempTable
{
private :
 bool Running;

 /*
 //Screen in pixels
 const int SCREEN_WIDTH = 1440;
 const int SCREEN_HEIGHT = 900;
 //Table dimensions in meters
 const double TABLE_WIDTH_M = 3.569;
 const double TABLE_HEIGH_M = 1.778;
 //Table dimensions in pixels
 const int TABLE_WIDTH = 1000;
 const int TABLE_HEIGHT = TABLE_WIDTH*(TABLE_HEIGH_M/TABLE_WIDTH_M);
 //Pixel/Meter ratio
 const double PIXEL_METER_RATIO = TABLE_WIDTH / TABLE_WIDTH_M;
 //Radius of the ball in meters
 const double BALL_RADIUS_M = 57.15/1000;
 //Radius of the ball in pixels
 const double BALL_RADIUS = BALL_RADIUS_M*PIXEL_METER_RATIO;
 //Pocket width/Ball diameter Ratio
 const double POCKET_BALL_RATIO = 1.6;
 //Pocket corner radius/Ball diameter Ratio;
 const double CORNER_BALL_RATIO = 2;
 //Distance pocket corner center to table corner
 const double CORNER_CORNER = sqrt(pow(2*(POCKET_BALL_RATIO+CORNER_BALL_RATIO)*BALL_RADIUS,2)/2)-(2*BALL_RADIUS);


 const int CORNER_X = (SCREEN_WIDTH-TABLE_WIDTH)/2;
 const int CORNER_Y = (SCREEN_HEIGHT-TABLE_HEIGHT)/2;
 */



  //Position of the pocket corners
 std::vector<std::vector<double>> POS_POCKET_CORNER_BALLS;
 std::vector<Ball> POCKET_CORNER_BALLS;

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
