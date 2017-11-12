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



    //Loop for updating positions, velocities and collisions
    double rolingResistanceCoefficient = 0.010; //mu ball cloth
    double g = 9.81;
    double a_m = g*rolingResistanceCoefficient; //acceleration in m/s^2
    double a = a_m*PIXEL_METER_RATIO; //acceleration in px/s^2
    for (int t=0; t<numberOfSteps; t++) {
        //update positions
        for (int n = 0; n<balls.size(); n++) {
            //update positions
            balls[n].setPreviousPosition(balls[n].getPosition());
            vector<double> newPos(2);
            for (int m = 0; m<2; m++)  {  newPos[m] = balls[n].getPosition()[m] + dt*balls[n].getVelocity()[m];  }
            balls[n].setPosition(newPos);

            //update velocity due to friction
            vector<double> newVel(2);

            newVel[0] = balls[n].getVelocity()[0] - vectorCos(balls[n].getVelocity())*dt*a;
            newVel[1] = balls[n].getVelocity()[1] - vectorSin(balls[n].getVelocity())*dt*a;
             balls[n].setVelocity(newVel);

            for (int m = 0; m<2; m++)  {
                bool is_negative = balls[n].getVelocity()[m] < 0;
                if (is_negative == 1) {

                }
                else {

                }
                newVel[m] = balls[n].getVelocity()[m] + dt*balls[n].getVelocity()[m];
            }
        }





        //Ball on ball collisions
        for (int i = 0; i < (balls.size() - 1); i++){
            for (int j = i; j < balls.size(); j++){
                double restitutionCoefficientBalls = 0.9;
                collisionBalls(balls[i],balls[j],restitutionCoefficientBalls);
            }
        }










        //collisions
        //cout << "for collision Ball pos x: " << balls[0].getPosition()[0] << "       , y: " << balls[0].getPosition()[1] << endl;
        //cout << "for collision Ball vel x: " << balls[0].getVelocity()[0] << "       , y: " << balls[0].getVelocity()[1] << endl;
        //collisionBalls(balls[0],balls[1],1);
        //collisions(balls, POCKET_CORNER_BALLS);
        //cout << "after collision Ball pos x: " << balls[0].getPosition()[0] << "       , y: " << balls[0].getPosition()[1] << endl;
        //cout << "after collision Ball vel x: " << balls[0].getVelocity()[0] << "       , y: " << balls[0].getVelocity()[1] << endl;
        //return;
    }





}
