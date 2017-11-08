#include <iostream>
#include <vector>
#include <math.h>

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
