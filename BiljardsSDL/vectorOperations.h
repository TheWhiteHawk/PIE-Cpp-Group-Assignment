#ifndef VECTOROPERATIONS_H_INCLUDED
#define VECTOROPERATIONS_H_INCLUDED

#include <vector>

double vectorMagnitude(std::vector<double> v);

void vectorAddition(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

void vectorSubstraction(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

double vectorDotProduct(std::vector<double> in_1, std::vector<double> in_2);

void vectorDotDivision(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

void vectorPrint(std::vector<double> v);

void matrixPrint(std::vector<std::vector<double>> M);

#endif // VECTOROPERATIONS_H_INCLUDED
