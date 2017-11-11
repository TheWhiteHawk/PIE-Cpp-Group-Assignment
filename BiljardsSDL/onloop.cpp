#include"game.h"
void game::OnLoop ()
{
    time = SDL_GetTicks();
    double timeInBetweenFrames = time-previousTime;
    cout << "dt: " << timeInBetweenFrames << endl;
    FPS = 1000/(timeInBetweenFrames);
    cout << "FPS: " << FPS << endl;
    previousTime = time;

    int numberOfSteps = ceil(timeInBetweenFrames/maxDt);
    double dt = (timeInBetweenFrames/numberOfSteps)/1000;



    //Loop for updating positions and and velocities
    for (int t=0; t<numberOfSteps; t++) {
        //update positions
        for (int n = 0; n<balls.size(); n++) {
            balls[n].setPreviousPosition(balls[n].getPosition());
            vector<double> newPos(2);
            for (int m = 0; m<2; m++)  {  newPos[m] = balls[n].getPosition()[m] + dt*balls[n].getVelocity()[m];  }
            balls[n].setPosition(newPos);

        }

        //collisions
        cout << "for collision Ball pos x: " << balls[0].getPosition()[0] << "       , y: " << balls[0].getPosition()[1] << endl;
        cout << "for collision Ball vel x: " << balls[0].getVelocity()[0] << "       , y: " << balls[0].getVelocity()[1] << endl;
        collisionBalls(balls[0],balls[1],1);
        //collisions(balls, POCKET_CORNER_BALLS);
        cout << "after collision Ball pos x: " << balls[0].getPosition()[0] << "       , y: " << balls[0].getPosition()[1] << endl;
        cout << "after collision Ball vel x: " << balls[0].getVelocity()[0] << "       , y: " << balls[0].getVelocity()[1] << endl;
        return;
    }





}
