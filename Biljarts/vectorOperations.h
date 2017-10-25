#ifndef VECTOROPERATIONS_H_INCLUDED
#define VECTOROPERATIONS_H_INCLUDED

#include <vector>

double vectorMagnitude(std::vector<double> v);

void vectorAddition(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

void vectorSubstraction(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

void vectorDotProduct(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

void vectorDotDivision(std::vector<double> in_1, std::vector<double> in_2, std::vector<double> &out);

#endif // VECTOROPERATIONS_H_INCLUDED
