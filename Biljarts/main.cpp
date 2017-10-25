#include <iostream>
#include <vector>
#include "vectorOperations.h"

using namespace std;

void PrintVector (const vector<double>& v){
  //vector<int> v;
  for (int i=0; i<v.size();i++){
    cout << v[i] << endl;
  }
}

int main(){
    std::vector<double> TestVector = {7, 5, 16, 8};
     PrintVector(TestVector);
    //TestVector = vectorMagnitude(TestVector);
    //Test .gitignore
    cout << TestVector[2] << endl;
    return 0;
}
