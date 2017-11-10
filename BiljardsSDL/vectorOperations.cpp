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

double vectorCos(std::vector<double> v){
    std::vector<double> x {1,0};
    double dotproduct = vectorDotProduct(v,x);
    double magnitude = vectorMagnitude(v);
    double cos = dotproduct / magnitude;
    return cos;
}

double vectorSin(std::vector<double> v){
    std::vector<double> y {0,1};
    double dotproduct = vectorDotProduct(v,y);
    double magnitude = vectorMagnitude(v);
    double sin = dotproduct / magnitude;
    return sin;
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
