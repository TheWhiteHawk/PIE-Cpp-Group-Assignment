#include"game.h"
#include "assignballnumber.h"

bool game::LoadContent ()
{
    //Set mousePos, the max ball velocity in pixels/s, mouseScaling (distance between the mouse and cue ball scalled to the velocity of the cueball when clicked). set some variables.
    mousePos = {0,0};
    maxVel = 1000;
    mouseSpeedScaling = 6;
    firstPlayer = true;
    firstTimeStepAfterPlay = false;


    //Set the ball positions of the corner balls, these are the round edges of the table.
    vector<double> row(2);

    const vector<double> X_OFFSET {CORNER_X , CORNER_X+TABLE_WIDTH};
    const vector<double> Y_OFFSET {CORNER_Y , CORNER_Y+TABLE_HEIGHT};

    for (int x = 0; x<2; x++){
        for(int y = 0; y<2; y++){
            for(int n = 0; n<2; n++){
                row[n] = (CORNER_CORNER);
                row[(n+1)%2] = (-CORNER_BALL_RATIO*BALL_RADIUS);
                //Mirror pockets
                row[0] = row[0]*pow(-1,x) + X_OFFSET[x];
                row[1] = row[1]*pow(-1,y) + Y_OFFSET[y];
                POS_POCKET_CORNER_BALLS.push_back(row);
            }
            row[0] = (TABLE_WIDTH/2 - (POCKET_BALL_RATIO+CORNER_BALL_RATIO)*BALL_RADIUS);
            row[1] = (-CORNER_BALL_RATIO*BALL_RADIUS);
            //Mirror pockets
            row[0] = row[0]*pow(-1,x) + X_OFFSET[x];
            row[1] = row[1]*pow(-1,y) + Y_OFFSET[y];
            POS_POCKET_CORNER_BALLS.push_back(row);
        }
    }

    //make a vector of the round corners so they can be used in collisions.
    for(int n=0; n<POS_POCKET_CORNER_BALLS.size(); n++){
        Ball tempBall;
        tempBall.setBallNumber(100); // so all properties can be set
        tempBall.setMass(pow(10,150));
        vector<double> tempVector {0 , 0};
        tempBall.setVelocity(tempVector);
        for ( int i = 0; i<2; i++ )   { tempVector[i] = POS_POCKET_CORNER_BALLS[n][i]; }
        tempBall.setPosition(tempVector);
        tempBall.setPreviousPosition(tempVector);
        tempBall.setRadius(CORNER_BALL_RATIO*BALL_RADIUS);
        tempBall.setHasScored(false);
        tempBall.setBallNumber(-1);
        POCKET_CORNER_BALLS.push_back(tempBall);
    }





    //Initialize balls
    for(int n =0; n<16; n++)  {
        Ball tempBall;
        balls.push_back(tempBall);
    }

    vector<double> tempVector(2);
    tempVector[0] = TABLE_WIDTH/4+CORNER_X;
    tempVector[1] = TABLE_HEIGHT/2+CORNER_Y;



    balls[0].setPosition(tempVector); // set the position of the cue ball
    int index = 1;
    //set the position of all the other balls.
    for (int n = 0; n<5; n++)  {
            for (int m = 0; m<(n+1); m++) {
                tempVector[0] = (TABLE_WIDTH/4)*3+CORNER_X + n*sqrt(3)*BALL_RADIUS;
                tempVector[1] = TABLE_HEIGHT/2+CORNER_Y - (n-(2*m))*BALL_RADIUS;
                balls[index].setPosition(tempVector);
                index++;
            }
    }

    const double BALL_MASS = 0.170097139; //mass of the ball in kg, the mass is 6 oz
    vector<int> nr = assignballnumber(); // make a vector of ball numbers which are random
    //set all the properties of the balls
    for (int n = 0; n<balls.size(); n++) {
        balls[n].setBallNumber(nr[n]);
        balls[n].setMass(BALL_MASS);
        balls[n].setRadius(BALL_RADIUS);
        balls[n].setVelocity(vector<double>{0,0});
        balls[n].setPreviousPosition(balls[n].getPosition());
        balls[n].setHasScored(false);
    }






    return 1;
}
