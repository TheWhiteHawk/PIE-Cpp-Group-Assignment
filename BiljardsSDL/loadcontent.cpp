#include"game.h"
bool game::LoadContent ()
{
    //Set mousePos
    mousePos = {0,0};
    maxVel = 1000;
    mouseSpeedScaling = 6;
    firstPlayer = true;



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

    for(int n=0; n<POS_POCKET_CORNER_BALLS.size(); n++){
        Ball tempBall;
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
    //cout << "TEST DINGEN:  " <<POCKET_CORNER_BALLS[0].getPosition()[0] << endl;


//    for(int n = 0; n<4; n++){
//        vector<double> row {n , n};
//        POS_POCKET_CORNER_BALLS.push_back(row);
//    }




    //Initialize balls
    for(int n =0; n<16; n++)  {
        Ball tempBall;
        balls.push_back(tempBall);
    }

    vector<double> tempVector(2);
    tempVector[0] = TABLE_WIDTH/4+CORNER_X;
    tempVector[1] = TABLE_HEIGHT/2+CORNER_Y;

    //TEST
    //tempVector[0] = (TABLE_WIDTH/4)*3+CORNER_X;
    //tempVector[1] = TABLE_HEIGHT+CORNER_Y;

    balls[0].setPosition(tempVector);
    int index = 1;
    for (int n = 0; n<5; n++)  {
            for (int m = 0; m<(n+1); m++) {
                tempVector[0] = (TABLE_WIDTH/4)*3+CORNER_X + n*sqrt(3)*BALL_RADIUS;
                tempVector[1] = TABLE_HEIGHT/2+CORNER_Y - (n-(2*m))*BALL_RADIUS;
                balls[index].setPosition(tempVector);
                index++;
            }
    }

    const double BALL_MASS = 0.170097139; //mass of the ball in kg, the mass is 6 oz
    for (int n = 0; n<balls.size(); n++) {
        switch (n) {
            case 0 ... 4:   balls[n].setBallNumber(n);
                                    break;
            case 5:          balls[n].setBallNumber(8);
                                    break;
            case 6 ... 8:   balls[n].setBallNumber(n-1);
                                    break;
            case 9 ... 13:   balls[n].setBallNumber(n);
                                    break;
            case 14:        balls[n].setBallNumber(n+1);
                                    break;
            case 15:        balls[n].setBallNumber(n-1);
                                    break;
        }
        balls[n].setMass(BALL_MASS);
        balls[n].setRadius(BALL_RADIUS);
        balls[n].setVelocity(vector<double>{0,0});
        balls[n].setPreviousPosition(balls[n].getPosition());
        balls[n].setHasScored(false);
    }




    return 1;
}
