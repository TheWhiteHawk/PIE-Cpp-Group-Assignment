#include <iostream>
#include <vector>
#include <math.h>
#include "../BiljardsSDL/vectorOperations.h"
#include "../BiljardsSDL/ball.h"
#include "../BiljardsSDL/TempTable.h"

using namespace std;

int main(){
    vector<double> v {0,0.00000000000000000000000000000001};
    vector<double> in {1,1};
    vector<double> out {0,0};
    double cos = vectorCos(v);
    double sin = vectorSin(v);

    cout << cos << "\t" << sin << endl;
    /*vector<vector<double>> M { {1,2} , {3,4} };
    //matrixPrint(M);
    transformMatrix(cos,sin,M);
    //matrixPrint(M);
    vectorMatrixProduct(in,M,out);
    vectorPrint(out);
    transformMatrixInv(cos,sin,M);
    vector<double> out2 {0,0};
    vectorMatrixProduct(out,M,out2);
    vectorPrint(out2);*/
    return 0;
}



