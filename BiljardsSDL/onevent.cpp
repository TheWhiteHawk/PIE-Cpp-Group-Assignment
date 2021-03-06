#include"game.h"

void game::OnEvent ( SDL_Event * Event )  {
 if ( Event -> type == SDL_QUIT )  { //if the the x button on the window is clicked set these flags
   Running = false;
   ForceQuit = true;
  }
 if ( Event ->type == SDL_MOUSEMOTION ) { //set the mouse position so it can be used in the loops
    mousePos[0] = Event ->motion.x;
    mousePos[1] = Event ->motion.y;
 }
 if (Event ->type == SDL_MOUSEBUTTONDOWN ) {
    if ( Event->button.button == SDL_BUTTON_LEFT ) { // on left mouse button click
        cout << "Left Mouse Button Pressed" << endl;
        if (zeroVel) { //check if all balls lay still and if so update the velocity of the cue ball accordingly
            firstTimeStepAfterPlay = true;
            vector<double> newVel = {balls[0].getPosition()[0]-mousePos[0] , balls[0].getPosition()[1]-mousePos[1]};
            newVel= {newVel[0] * (mouseSpeedScaling), newVel[1]* (mouseSpeedScaling)};
            double magVec = vectorMagnitude(newVel);
            if (magVec > maxVel) {
                newVel = {newVel[0] * (maxVel/magVec), newVel[1]* (maxVel/magVec)};
            }
            balls[0].setVelocity(newVel);
        }
    }
 }
}
