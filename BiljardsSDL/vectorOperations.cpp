#include <iostream>
#include <vector>
#include <math.h>
#include "../BiljardsSDL/ball.h"
#include "../BiljardsSDL/TempTable.h"

double vectorMagnitude(std::vector<double> v){
    //vectorMagnitude squares all the elements of a vector,
    //sums them and calculates the square root of the sum
    double value = 0;
    int s = v.size();
    for (int i = 0; i < s; i++){
        value += v[i]*v[i];
    }
    return sqrt(value);
}

void vectorAddition(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out){
    //vectorAddition element wise addition of two vectors
    int s1 = in_1.size();
    int s2 = in_2.size();
    out.resize(s1,0);

    //If vector in_2 has one element it will be added to
    //every element of the vector in_1
    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i++){
            out[i] = in_1[i] + in_2[i];
        }
    }
    else {
        std::cout << "Vector sizes do not match!" << std::endl;
    }
}

void vectorSubstraction(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out){
    //vectorSubtraction preforms element wise subtraction of two vectors
    int s1 = in_1.size();
    int s2 = in_2.size();
    out.resize(s1,0);

    //If vector in_2 has one element it will be subtracted from
    //every element of the vector in_1
    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i++){
            out[i] = in_1[i] - in_2[i];
        }
    }
    else {
            std::cout << "Vector sizes do not match!" << std::endl;
    }
}

double vectorDotProduct(std::vector<double> in_1, std::vector<double> in_2){
    //vectorDotProduct preforms element wise multiplication of two vectors and then,
    //calculates the sum the products
    int s1 = in_1.size();
    int s2 = in_2.size();
    double dotproduct = 0;

    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i++){
            dotproduct += in_1[i] * in_2[i];
        }
    }
    else {
            std::cout << "Vector sizes do not match!" << std::endl;
    }
    return dotproduct;
}

void vectorDotDivision(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out){
    //vectorDotDivision preforms element wise division of two vectors
    int s1 = in_1.size();
    int s2 = in_2.size();
    out.resize(s1,0);

    //If vector in_2 has one element it will be the denominator in
    //every fraction with elements of the vector in_1
    if (s2 == 1){
        in_2.resize(s1,in_2[0]);
        s2 = in_2.size();
    }

    if (s1 == s2){
        for (int i = 0; i < s1; i++){
            out[i] = in_1[i] / in_2[i];
        }
    }
    else {
            std::cout << "Vector sizes do not match!" << std::endl;
    }
}

void vectorPrint(std::vector<double> v){
    //vectorPrint prints all the vector elements below each other on the screen
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
}

void matrixPrint(std::vector<std::vector<double>> M){
    //matrixPrint prints all the matrix elements,
    //where the elements of a row are printed in a single line
    for (int i = 0; i < M.size(); i++){
        for (int j = 0; j < (M[0].size()); j++){
            std::cout << M[i][j] << "\t";
        }
    std::cout << std::endl;
    }
}

double vectorCos(std::vector<double> v){
    //vectorCos calculates the value of the cosine from the angle between the vector v and the x-axis
    //cos(theta) = v*x/|v|, x is a unit vector so it has size one, * denotes a dot product
    std::vector<double> x {1,0};
    double dotproduct = vectorDotProduct(v,x);
    double magnitude = vectorMagnitude(v);
    //When magnitude is very close to zero the function returns zero instead of Nan
    if (magnitude > pow(10,-300)){
        double cos = dotproduct / magnitude;
        return cos;
    }
    else{
        return 0;
    }
}

double vectorSin(std::vector<double> v){
    //vectorSin calculates the value of the sine from the angle between the vector v and the x-axis
    //cos(pi/2-theta) = sin(theta) = v*y/|v|, y is a unit vector so it has size one, * denotes a dot product
    std::vector<double> y {0,1};
    double dotproduct = vectorDotProduct(v,y);
    double magnitude = vectorMagnitude(v);
    //When magnitude is very close to zero the function returns zero instead of Nan
    if (magnitude > pow(10,-300)){
    double sin = dotproduct / magnitude;
    return sin;
    }
    else{
        return 0;
    }
}

void transformMatrix(double cos, double sin, std::vector<std::vector<double>> &M){
    //This matrix preforms a coordinate transformation for any {x,y} vector when it is multiplied with it
    M = { {cos , sin},{-sin , cos} };
}

void transformMatrixInv(double cos, double sin, std::vector<std::vector<double>> &M){
    //This matrix preforms an inverse coordinate transformation for any {x,y} vector when it is multiplied with it
    M = { {cos , -sin},{sin , cos} };
}

void vectorMatrixProduct(std::vector<double> in, std::vector<std::vector<double>> M, std::vector<double> &out){
    //vectorMatrixProduct preforms vector matrix multiplication for any suitable sets of vectors and matrices
    //it returns the vector out
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
    //collisionReturnVelocity calculates the new velocity components after collision between two object along the collision direction
    //the velocity calculation is generalized to allow for inelastic collisions

    //restitutionCoefficient = 0 -> perfectly inelastic
    //0 < restitutionCoefficient < 1 -> inelastic
    //restitutionCoefficient = 1 -> elastic

    double vPar_1 = velocity_1[0]; //Velocity component parallel to the collision direction of object 1
    double vPar_2 = velocity_2[0]; //Velocity component parallel to the collision direction of object 2
    velocity_1[0] = ((restitutionCoefficient * mass_2 * (vPar_2 - vPar_1)) + (mass_1 * vPar_1) + (mass_2 * vPar_2)) / (mass_1 + mass_2); //New velocity component object 1
    velocity_2[0] = ((restitutionCoefficient * mass_1 * (vPar_1 - vPar_2)) + (mass_2 * vPar_2) + (mass_1 * vPar_1)) / (mass_1 + mass_2); //New velocity component object 2
}

void collisionBalls(Ball &ball_A, Ball &ball_B, double restitutionCoefficient){
    //collisionBalls calculates the new velocity vectors of two balls after the collide

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

            if (ball_A_velocityTrans[0] > ball_B_velocityTrans[0]){
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
}




