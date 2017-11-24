#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"includes.h"
#include <math.h>
#include "TempTable.h"

class game : public TempTable
{
private :
 bool Running;
 bool ForceQuit;

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
 //Mouse properties and Max cue ball velocity
 vector<double> mousePos;
 double maxVel;
 double mouseSpeedScaling;
 //FPS and frames
 int FPS;
 double time;
 double previousTime;
 double maxDt;
 bool firstTimeStepAfterPlay;

 //Check if balls lay still
 bool zeroVel;
 //Is current player, player 1
 bool firstPlayer;
 //Does player 1 have even balls
 bool firstPlayerIsFull;
 //Has player 1 won
 bool firstPlayerWins;
 //First score
 bool firstScore = true;
 //8-ball has been pocketed
 bool gameEnd = false;
 //A ball has been pocketed this turn
 bool scoreHappend = false;
 //Players should switch at the end of the turn
 bool shouldSwitch = true;
 //Are all the balls that are pocketed this turn full
 bool allFull = true;
 //Are all the balls that are pocketed this turn half
 bool allHalf = true;

 //Text that is displayed for the players
 char* firstPlayerMessage = "PLAYER 1";
 char* secondPlayerMessage = "PLAYER 2";

 //Position of the pocket corners
 std::vector<std::vector<double>> POS_POCKET_CORNER_BALLS;
 std::vector<Ball> POCKET_CORNER_BALLS;
 std::vector<Ball> balls;

 SDL_Window * window;
 SDL_Renderer * renderer;
 TTF_Font * font;
 TTF_Font * ballFont;
 SDL_Surface * surface;
 SDL_Texture * texture;

 SDL_Event Event;
public :
 game () ;
  // virtual ~game () ;
 int OnExecute () ;
 bool OnInit () ;
 bool LoadContent () ;
 void OnEvent ( SDL_Event * Event ) ;
 void OnLoop () ;
 void OnRender () ;
 void OnEnd () ;
 void Cleanup () ;

 void stopRunning();

 //needed to draw stuff
 void draw_circle(SDL_Renderer * renderer, SDL_Point center, int radius, SDL_Color color, int ballNumber);
 void DrawPlayerIndicator(SDL_Renderer * renderer, double X, double Y, double W , double H);

} ;
#endif // GAME_H_INCLUDED
