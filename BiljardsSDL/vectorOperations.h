#ifndef VECTOROPERATIONS_H_INCLUDED
#define VECTOROPERATIONS_H_INCLUDED

#include <vector>
#include "../BiljardsSDL/ball.h"

double vectorMagnitude(std::vector<double> v);

void vectorAddition(std::vector<double> &in_1, std::vector<double> &in_2, std::vector<double> &out);

void vectorSubstraction(std::vector<double> &in_1, std::vector<double> &in_2, std::vector<double> &out);

double vectorDotProduct(std::vector<double> &in_1, std::vector<double> &in_2);

void vectorDotDivision(std::vector<double> &in_1, std::vector<double> &in_2, std::vector<double> &out);

void vectorPrint(std::vector<double> &v);

void matrixPrint(std::vector<std::vector<double>> &M);

double vectorCos(std::vector<double> v);

double vectorSin(std::vector<double> v);

void transformMatrix(double &cos, double &sin, std::vector<std::vector<double>> &M);

void transformMatrixInv(double &cos, double &sin, std::vector<std::vector<double>> &M);

int vectorMatrixProduct(std::vector<double> &in, std::vector<std::vector<double>> &M, std::vector<double> &out);

void collisionReturnVelocity(std::vector<double> &velocity_1, std::vector<double> &velocity_2, double &mass_1, double &mass_2, double &restitutionCoefficient);

void collisionBalls(Ball &ball_A, Ball &ball_B, double &restitutionCoefficient);

#endif // VECTOROPERATIONS_H_INCLUDED
