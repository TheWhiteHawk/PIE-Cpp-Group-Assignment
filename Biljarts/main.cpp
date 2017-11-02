#include <iostream>
#include <vector>
#include "vectorOperations.h"
#include "ball.h"

using namespace std;

void PrintVector (const vector<double>& v){
    cout << "============== Print Vector ==============" << endl;
    for (int i=0; i<v.size();i++){
        cout << v[i] << endl;
    }
    cout << "==========================================" << endl << endl;
}

int main(){
    std::vector<double> TestVector = {7, 5, 16, 8};
    double TestVectorAns;
     PrintVector(TestVector);
    TestVectorAns = vectorMagnitude(TestVector);
    //Test .gitignore
    cout << TestVectorAns << endl;




    Ball ball1;




    return 0;
}
