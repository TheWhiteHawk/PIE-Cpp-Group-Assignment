#include <iostream>
#include <vector>
#include <math.h>
#include "../BiljardsSDL/vectorOperations.h"
#include "../BiljardsSDL/ball.h"
#include "../BiljardsSDL/TempTable.h"

using namespace std;

int main(){
    vector<double> v {1,1};
    vector<double> in {0,1};
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



