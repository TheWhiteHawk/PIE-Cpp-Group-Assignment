#include <iostream>
#include <vector>
#include <math.h>
#include "../BiljardsSDL/ball.h"
#include "../BiljardsSDL/TempTable.h"

double vectorMagnitude(std::vector<double> v){
    double value = 0;
    int s = v.size();
    for (int i = 0; i < s; i++){
        value += v[i]*v[i];
    }
    return sqrt(value);
}

void vectorAddition(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out){
    int s1 = in_1.size();
    int s2 = in_2.size();
    out.resize(s1,0);

    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i ++){
            out[i] = in_1[i] + in_2[i];
        }
    }
    else {
        std::cout << "Vector sizes do not match!" << std::endl;
    }
}

void vectorSubstraction(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out){
    int s1 = in_1.size();
    int s2 = in_2.size();
    out.resize(s1,0);

    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i ++){
            out[i] = in_1[i] - in_2[i];
        }
    }
    else {
            std::cout << "Vector sizes do not match!" << std::endl;
    }
}

double vectorDotProduct(std::vector<double> in_1, std::vector<double> in_2){
    int s1 = in_1.size();
    int s2 = in_2.size();
    double dotproduct = 0;

    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i ++){
            dotproduct += in_1[i] * in_2[i];
        }
    }
    else {
            std::cout << "Vector sizes do not match!" << std::endl;
    }
    return dotproduct;
}

void vectorDotDivision(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out){
    int s1 = in_1.size();
    int s2 = in_2.size();
    out.resize(s1,0);

    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i ++){
            out[i] = in_1[i] / in_2[i];
        }
    }
    else {
            std::cout << "Vector sizes do not match!" << std::endl;
    }
}

void vectorPrint(std::vector<double> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
}

void matrixPrint(std::vector<std::vector<double>> M){
    for (int i = 0; i < M.size(); i++){
        for (int j = 0; j < (M[0].size()); j++){
            std::cout << M[i][j] << "\t";
        }
    std::cout << std::endl;
    }
}

double vectorCos(std::vector<double> v){
    std::vector<double> x {1,0};
    double dotproduct = vectorDotProduct(v,x);
    double magnitude = vectorMagnitude(v);
    if (magnitude > pow(10,-300)){
        double cos = dotproduct / magnitude;
        return cos;
    }
    else{
        return 0;
    }
}

double vectorSin(std::vector<double> v){
    std::vector<double> y {0,1};
    double dotproduct = vectorDotProduct(v,y);
    double magnitude = vectorMagnitude(v);
    if (magnitude > pow(10,-300)){
    double sin = dotproduct / magnitude;
    return sin;
    }
    else{
        return 0;
    }
}

void transformMatrix(double cos, double sin, std::vector<std::vector<double>> &M){
    M = { {cos , -sin},{sin , cos} };
}

void transformMatrixInv(double cos, double sin, std::vector<std::vector<double>> &M){
    M = { {cos , sin},{-sin , cos} };
}

void vectorMatrixProduct(std::vector<double> in, std::vector<std::vector<double>> M, std::vector<double> &out){
    int sizeVector = in.size();
    out.resize(sizeVector,0);
    int rowMatrix = M.size();
    int colMatrix = M[0].size();
    if (rowMatrix == colMatrix){
        if (colMatrix == sizeVector){
            for (int i = 0; i < rowMatrix; i++){
                for (int j = 0; j < colMatrix; j++){
                    out[i] += in[j]*M[i][j];
                }
            }
        }
        else{
            std::cout << "Number of columns in the matrix does not match vector size!" << std::endl;
        }
    }
    else{
        std::cout << "Matrix is not square!" << std::endl;
    }
}

void collisionReturnVelocity(std::vector<double> &velocity_1, std::vector<double> &velocity_2, double mass_1, double mass_2, double restitutionCoefficient){
    double vPar_1 = velocity_1[0];
    double vPar_2 = velocity_2[0];
    velocity_1[0] = ((restitutionCoefficient * mass_2 * (vPar_2 - vPar_1)) + (mass_1 * vPar_1) + (mass_2 * vPar_2)) / (mass_1 + mass_2);
    velocity_2[0] = ((restitutionCoefficient * mass_1 * (vPar_1 - vPar_2)) + (mass_2 * vPar_2) + (mass_1 * vPar_1)) / (mass_1 + mass_2);
}

void collisionBalls(Ball &ball_A, Ball &ball_B, double restitutionCoefficient){
    //Checking if either or both of the balls have scored
    //No collision check is necessary of one of the balls has scored
    bool hasScored_A = ball_A.getHasScored();
    bool hasScored_B = ball_B.getHasScored();
    if (!hasScored_A && !hasScored_B){
        //Calculating the distance between the balls
        std::vector<double> ball_A_position = ball_A.getPosition();
        std::vector<double> ball_B_position = ball_B.getPosition();
        std::vector<double> differenceBallPosition;

        vectorSubstraction(ball_B_position, ball_A_position, differenceBallPosition);
        double distanceBetweenBalls = vectorMagnitude(differenceBallPosition);

        //Checking if they are close enough for collisions
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
                std::vector<double> ball_A_velocityTrans = {0,0};
                vectorMatrixProduct(ball_A_velocity,transformationMatrix,ball_A_velocityTrans);

                //Target ball
                std::vector<double> ball_B_velocity = ball_B.getVelocity();
                std::vector<double> ball_B_velocityTrans = {0,0};
                vectorMatrixProduct(ball_B_velocity,transformationMatrix,ball_B_velocityTrans);

            //Collision constants
            //Masses
            double ball_A_mass = ball_A.getMass();
            double ball_B_mass = ball_B.getMass();

            //Calculating new velocities
            collisionReturnVelocity(ball_A_velocityTrans, ball_B_velocityTrans, ball_A_mass, ball_B_mass, restitutionCoefficient);

            //Preforming inverse coordinate transformation to collision frame
                //Current ball
                ball_A_velocity = {0,0};
                vectorMatrixProduct(ball_A_velocityTrans,inverseTransformationMatrix,ball_A_velocity);
                ball_A.setVelocity(ball_A_velocity);

                //Target ball
                ball_B_velocity = {0,0};
                vectorMatrixProduct(ball_B_velocityTrans,inverseTransformationMatrix,ball_B_velocity);
                ball_B.setVelocity(ball_B_velocity);

            //Setting position
            ball_A.setPosition(ball_A.getPreviousPosition());
            ball_B.setPosition(ball_B.getPreviousPosition());
        }
    }
}

void collisionWalls(std::vector<Ball> &balls, std::vector<Ball> pocketBalls){
    //Defining the table geometry
    TempTable table;

    //Flat wall ranges
    double A = pocketBalls[0].getPosition()[0]; //X coordinate pocket ball 0
    double B = pocketBalls[2].getPosition()[0]; //X coordinate pocket ball 2
    double C = pocketBalls[8].getPosition()[0]; //X coordinate pocket ball 8
    double D = pocketBalls[6].getPosition()[0]; //X coordinate pocket ball 6
    double E = pocketBalls[1].getPosition()[1]; //Y coordinate pocket ball 1
    double F = pocketBalls[4].getPosition()[1]; //Y coordinate pocket ball 4

    for (int i = 0; i < balls.size(); i++){
        //Checking if the ball has scored
        bool hasScored = balls[i].getHasScored();
        if (!hasScored){

            double restitutionCoefficientWalls = 0.6;

            //Checking if the balls experience flat wall collisions or corner collisions
            std::vector<double> r = balls[i].getPosition();
            if (!(((A <= r[0] <= B) || (C <= r[0] <= D)) && (E <= r[1] <= F))){
                //Ball on corner collisions
                for (int j = 0; j < pocketBalls.size(); j++){
                    collisionBalls(balls[i],pocketBalls[j],restitutionCoefficientWalls);
                }
            }
            else{
                //Ball on wall collisions
                //Relevant table dimensions
                double W = table.TABLE_WIDTH;
                double H = table.TABLE_HEIGHT;
                double cornerX = table.CORNER_X;
                double cornerY = table.CORNER_Y;

                //Relevant ball variables
                double R = balls[i].getRadius();
                std::vector<double> v = balls[i].getVelocity();

                //Setting new velocity
                    //Collisions with vertical walls
                    if ((r[0]-cornerX < R)||(abs(r[0]-H-cornerX))){
                        v[0] = -restitutionCoefficientWalls*v[0];
                    }
                    //Collisions with horizontal walls
                    if ((r[1]-cornerY < R)||(abs(r[1]-W-cornerY))){
                        v[1] = -restitutionCoefficientWalls*v[1];
                    }

                    balls[i].setVelocity(v);
            }
        }
    }
}

void collisions(std::vector<Ball> &balls, std::vector<Ball> pocketBalls){
    //Ball on ball collisions
    for (int i = 0; i < (balls.size() - 1); i++){
        for (int j = i; j < balls.size(); j++){
            double restitutionCoefficientBalls = 0.9;
            collisionBalls(balls[i],balls[j],restitutionCoefficientBalls);
        }
    }

    //Ball on wall collisions
    collisionWalls(balls,pocketBalls);
}
