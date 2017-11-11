#include <iostream>
#include <vector>
#include "../BiljardsSDL/vectorOperations.h"
#include "../BiljardsSDL/ball.h"
#include "../BiljardsSDL/TempTable.h"

using namespace std;




void collisionBalls(Ball &ball_A, Ball &ball_B, double restitutionCoefficient){
    bool hasScored_A = ball_A.getHasScored();
    bool hasScored_B = ball_B.getHasScored();
    if (!hasScored_A && !hasScored_B){
        std::vector<double> ball_A_position = ball_A.getPosition();
        std::vector<double> ball_B_position = ball_B.getPosition();
        std::vector<double> differenceBallPosition;

        vectorSubstraction(ball_A_position, ball_B_position, differenceBallPosition);
        double distanceBetweenBalls = vectorMagnitude(differenceBallPosition);

        if (distanceBetweenBalls < (ball_A.getRadius() + ball_B.getRadius())){
            //Calculating transformation matrices
            double cos = vectorCos(differenceBallPosition);
            double sin = vectorSin(differenceBallPosition);
            std::vector<std::vector<double>> transformationMatrix;
            std::vector<std::vector<double>> inverseTransformationMatrix;
            transformMatrix(cos,sin,transformationMatrix);
            transformMatrixInv(cos,sin,inverseTransformationMatrix);

            //Preforming coordinate transformation to collision frame
                //Current ball
                std::vector<double> ball_A_velocity = ball_A.getVelocity();
                std::vector<double> ball_A_velocityTrans;
                vectorMatrixProduct(ball_A_velocity,transformationMatrix,ball_A_velocityTrans);

                //Target ball
                std::vector<double> ball_B_velocity = ball_B.getVelocity();
                std::vector<double> ball_B_velocityTrans;
                vectorMatrixProduct(ball_B_velocity,transformationMatrix,ball_B_velocityTrans);

            //Collision constants
            //Masses
            double ball_A_mass = ball_A.getMass();
            double ball_B_mass = ball_B.getMass();

            //Calculating new velocities
            collisionReturnVelocity(ball_A_velocityTrans, ball_B_velocityTrans, ball_A_mass, ball_B_mass, restitutionCoefficient);

            //Preforming inverse coordinate transformation to collision frame
                //Current ball
                vectorMatrixProduct(ball_A_velocityTrans,inverseTransformationMatrix,ball_A_velocity);
                ball_A.setVelocity(ball_A_velocity);

                //Target ball
                vectorMatrixProduct(ball_B_velocityTrans,inverseTransformationMatrix,ball_B_velocity);
                ball_B.setVelocity(ball_B_velocity);

            //Setting position
            ball_A.setPosition(ball_A.getPreviousPosition());
            ball_B.setPosition(ball_B.getPreviousPosition());
        }
    }
}

void collisions(std::vector<Ball> balls, std::vector<Ball> pocketBalls){
    TempTable table;
    //Ball on ball collisions
    for (int i = 0; i < (balls.size() - 1); i++){
        for (int j = i; j < balls.size(); j++){
            double restitutionCoefficientBalls = 0.9;
            collisionBalls(balls[i],balls[j],restitutionCoefficientBalls);
        }
    }

    //Wall collisions
    //Flat wall ranges
    double A = pocketBalls[0].getPosition()[0];
    double B = pocketBalls[2].getPosition()[0];
    double C = pocketBalls[8].getPosition()[0];
    double D = pocketBalls[6].getPosition()[0];
    double E = pocketBalls[1].getPosition()[1];
    double F = pocketBalls[4].getPosition()[1];

    for (int i = 0; i < balls.size(); i++){
        std::vector<double> r = balls[i].getPosition();
        double restitutionCoefficientWalls = 0.6;
        if (!(((A <= r[0] <= B) || (C <= r[0] <= D)) && (E <= r[1] <= F))){
            //Ball on corner collisions
            for (int j = 0; j < pocketBalls.size(); j++){
                collisionBalls(balls[i],pocketBalls[j],restitutionCoefficientWalls);
            }
        }
        else{
            double W = table.TABLE_WIDTH;
            double H = table.TABLE_HEIGHT;
            double cornerX = table.CORNER_X;
            double cornerY = table.CORNER_Y;
            double R = balls.getRadius();
            if ((r[0] < R)||()){

            }
        }
    }
}

int main(){
    vector<double> v {1,1};
    vector<double> in {1,1};
    vector<double> out {0,0};
    double cos = vectorCos(v);
    double sin = vectorSin(v);
    vector<vector<double>> M { {1,2} , {3,4} };
    //matrixPrint(M);
    transformMatrixInv(cos,sin,M);
    //matrixPrint(M);
    vectorMatrixProduct(in,M,out);
    vectorPrint(out);
    return 0;
}



