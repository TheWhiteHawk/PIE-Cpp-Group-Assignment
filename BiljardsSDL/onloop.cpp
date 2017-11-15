#include"game.h"
void game::OnLoop ()
{
    time = SDL_GetTicks();
    double timeInBetweenFrames = time-previousTime;
    //cout << "dt: " << timeInBetweenFrames << endl;
    FPS = 1000/(timeInBetweenFrames);
    //cout << "FPS: " << FPS << endl;
    previousTime = time;

    int numberOfSteps = ceil(timeInBetweenFrames/maxDt);
    double dt = (timeInBetweenFrames/numberOfSteps)/1000;



    //Loop for updating positions, velocities and collisions
    double rolingResistanceCoefficient = 0.010; //mu ball cloth
    double g = 9.81;
    double a_m = g*rolingResistanceCoefficient; //acceleration in m/s^2
    double a = a_m*PIXEL_METER_RATIO; //acceleration in px/s^2
    double restitutionCoefficientWalls = 0.6;
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
            double velMagnitude = vectorMagnitude(balls[n].getVelocity());
            if (velMagnitude < dt*a) {
                newVel = {0,0};
            }
            else {
                newVel[0] = balls[n].getVelocity()[0] - vectorCos(balls[n].getVelocity())*dt*a;
                newVel[1] = balls[n].getVelocity()[1] - vectorSin(balls[n].getVelocity())*dt*a;
            }

            balls[n].setVelocity(newVel);
        }





        //Ball on ball collisions
        for (int i = 0; i < (balls.size() - 1); i++){
            for (int j = i; j < balls.size(); j++){
                double restitutionCoefficientBalls = 0.9;
                collisionBalls(balls[i],balls[j],restitutionCoefficientBalls);
            }
        }


        //Wall collitions
        //Flat wall ranges
        double A = POCKET_CORNER_BALLS[0].getPosition()[0]; //X coordinate pocket ball 0
        double B = POCKET_CORNER_BALLS[2].getPosition()[0]; //X coordinate pocket ball 2
        double C = POCKET_CORNER_BALLS[8].getPosition()[0]; //X coordinate pocket ball 8
        double D = POCKET_CORNER_BALLS[6].getPosition()[0]; //X coordinate pocket ball 6
        double E = POCKET_CORNER_BALLS[1].getPosition()[1]; //Y coordinate pocket ball 1
        double F = POCKET_CORNER_BALLS[4].getPosition()[1]; //Y coordinate pocket ball 4

        for (int i = 0; i < balls.size(); i++){
            //Checking if the ball has scored
            bool hasScored = balls[i].getHasScored();

            if (!hasScored){
                //cout << "possible collision hasScored= false" << endl;
                //Checking if the balls experience flat wall collisions or corner collisions
                std::vector<double> r = balls[i].getPosition();

                if ((   (r[0]<A) || (r[0]>B&&r[0]<C) || (r[0]>D)   ) && ( r[1]<E || r[1]>F )){
                    //Ball is able to score or the collide on a pocket corner in this area
                    //If statement for individual pockets
                    //Top left pocket
                    if (r[1]+r[0] <= POCKET_CORNER_BALLS[0].getPosition()[0]+POCKET_CORNER_BALLS[0].getPosition()[1]){
                        hasScored = true;
                    }
                    //Top middle pocket
                    if (r[1] <= POCKET_CORNER_BALLS[2].getPosition()[1]){
                        hasScored = true;
                    }
                    //Top right pocket
                    if (r[1]-r[0] <= POCKET_CORNER_BALLS[6].getPosition()[1]-POCKET_CORNER_BALLS[6].getPosition()[0]){
                        hasScored = true;
                    }
                    //Bottom left pocket
                    if (r[1]-r[0] >= POCKET_CORNER_BALLS[3].getPosition()[1]-POCKET_CORNER_BALLS[3].getPosition()[0]){
                        hasScored = true;
                    }
                    //Bottom middle pocket
                    if (r[1] >= POCKET_CORNER_BALLS[5].getPosition()[1]){
                        hasScored = true;
                    }
                    //Bottom right pocket
                    if (r[1]+r[0] >= POCKET_CORNER_BALLS[9].getPosition()[0]+POCKET_CORNER_BALLS[9].getPosition()[1]){
                        hasScored = true;
                    }

                    if (hasScored){
                        balls[i].setHasScored(hasScored);
                        balls[i].setVelocity(vector<double>{0,0});
                        cout << "Ball " << balls[i].getBallNumber() << " has scored" << endl;

                        //Balls to player assignment
                        int ballNumber = balls[i].getBallNumber();
                        bool isEven;

                        if ((ballNumber > 0) && (ballNumber != 8) && firstScore){

                            if (ballNumber % 2 == 0){
                                isEven = true;
                                cout << "even" << endl;
                            }
                            else{
                                isEven = false;
                                cout << "odd" << endl;
                            }

                            if (firstPlayer){
                                firstPlayerIsEven = isEven;

                            }
                            else{
                                firstPlayerIsEven = !isEven;
                            }
                            firstScore = false;
                        }

                        if (!firstScore){

                        }
                    }
                    else {
                        //Ball on corner collisions, but only if there was no score
                        for (int j = 0; j < POCKET_CORNER_BALLS.size(); j++){
                            collisionBalls(balls[i],POCKET_CORNER_BALLS[j],restitutionCoefficientWalls);
                        }
                    }
                }
                else{
                    //Ball on wall collisions
                    //Relevant table dimensions
                    double W = TABLE_WIDTH;
                    double H = TABLE_HEIGHT;
                    double cornerX = CORNER_X;
                    double cornerY = CORNER_Y;

                    //Relevant ball variables
                    double R = balls[i].getRadius();
                    std::vector<double> v = balls[i].getVelocity();

                    if ((r[0]<CORNER_X+R) && v[0]<0){
                        v[0] = -restitutionCoefficientWalls*v[0];
                    }
                    if ((r[0]>CORNER_X+W-R) && v[0]>0){
                        v[0] = -restitutionCoefficientWalls*v[0];
                    }
                    if ((r[1]<CORNER_Y+R) && v[1]<0){
                        v[1] = -restitutionCoefficientWalls*v[1];
                    }
                    if((r[1]>CORNER_Y+H-R) && v[1]>0){
                        v[1] = -restitutionCoefficientWalls*v[1];
                    }
                    balls[i].setVelocity(v);
                }
            }
        }
    }

    //Check if all balls which are in play have a velocity of 0
    zeroVel = true;
    for ( int n=0; n< balls.size(); n++) {
        if (!balls[n].getHasScored()) {
            if ( vectorMagnitude(balls[n].getVelocity()) > pow(10,-200)){
                zeroVel = false;
            }
        }
    }

    //End game and winning conditions
    bool evenAllScored = true;
    bool oddAllScored = true;
    bool gameEnd = false;
    bool evenHasWon;
    for (int i = 0; i < balls.size(); i++){
        int ballNumber = balls[i].getBallNumber();
        if (ballNumber > 0){
            if (ballNumber != 8){
                if (!balls[i].getHasScored()){
                    if (ballNumber % 2 == 0){
                        evenAllScored = false;
                    }
                    else{
                        oddAllScored = false;
                    }
                }
            }
            else{
                gameEnd = balls[i].getHasScored();
            }
        }
    }

    if (gameEnd && evenAllScored){
        evenHasWon = true;
    }
    if (gameEnd && oddAllScored){
        evenHasWon = false;
    }


    if (gameEnd && (evenAllScored || oddAllScored)){
        if (firstPlayerIsEven == evenHasWon){
            firstPlayerWins == true;
            cout << "Player 1 wins!" << endl;
       }
       else{
            firstPlayerWins == false;
            cout << "Player 2 wins!" << endl;
       }
    }
    if (gameEnd){
        cout << "Game has ended" << endl;
        //Running == false;
    }

    if ( zeroVel && balls[0].getHasScored() ) {
        balls[0].setHasScored(false);
        balls[0].setPosition(vector<double>{TABLE_WIDTH/4+CORNER_X,TABLE_HEIGHT/2+CORNER_Y});
    }




}
