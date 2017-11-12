#include <iostream>
#include <vector>
#include <math.h>
#include "../BiljardsSDL/vectorOperations.h"
#include "../BiljardsSDL/ball.h"
#include "../BiljardsSDL/TempTable.h"

using namespace std;


void score(vector<Ball> &balls,vector<Ball> &pocketBalls){
    TempTable table;
    double W = table.TABLE_WIDTH;
    double H = table.TABLE_HEIGHT;
    double cornerX = table.CORNER_X;
    double cornerY = table.CORNER_Y;

    double A = pocketBalls[0].getPosition()[0];
    double R = pocketBalls[0].getRadius();

    for (int i = 0; i < balls.size(); i++){
        bool hasScored = false;
        double x = balls[i].getPosition()[0];
        double y = balls[i].getPosition()[1];

        //If statement for individual pockets
        //Top left pocket
        if (y+x <= A - R){
            hasScored = true;
        }
        //Top middle pocket
        if (y <= cornerY - R){
            hasScored = true;
        }
        //Top right pocket
        if (y-x <= -A - R - cornerX - H){
            hasScored = true;
        }
        //Bottom left pocket
        if (y-x >= -A + R + cornerY + W){
            hasScored = true;
        }
        //Bottom middle pocket
        if (y >= cornerY + W + R){
            hasScored = true;
        }
        //Bottom right pocket
        if (y+x >= -A + R + cornerX + H + cornerY + W){
            hasScored = true;
        }

        if (hasScored){
            balls[i].setHasScored(hasScored);
            cout << "Ball " << balls[i].getBallNumber() << " has scored" << endl;
        }
    }
}





int main(){
    return 0;
}



