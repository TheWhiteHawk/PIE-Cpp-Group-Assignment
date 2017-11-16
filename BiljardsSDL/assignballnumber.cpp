#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

vector<int> assignballnumber() {
    srand (time(NULL));
    vector<int> out(16);
    vector<int> pool(out.size());
    for (int n = 0; n<pool.size(); n++) {
        pool[n] = n;
    }
    int ind;
    int N = pool.size();
    for (int n = 0; n<N; n++) {
        cout << "n: " << n << endl;
        if (n == 0) {
            ind = 0;
            out[ind] = pool[ind];
            pool.erase (pool.begin()+ind);
        }
        else if (n == 1) {
            ind = 7;
            out[5] = pool[ind];
            pool.erase (pool.begin()+ind);
        }
        else if (n == 2) {
            int corner = rand() % 2;
            if (corner == 0){
                ind = rand() % 7 + 8;
                out[11] = pool[ind];
                pool.erase (pool.begin()+ind);
                ind = rand() % 7;
                out[15] = pool[ind];
                pool.erase (pool.begin()+ind);
            }
            else {
                ind = rand() % 7 + 8;
                out[15] = pool[ind];
                pool.erase (pool.begin()+ind);
                ind = rand() % 7;
                out[11] = pool[ind];
                pool.erase (pool.begin()+ind);
            }
            n++;
        }
        else {
            int outInd;
            if (n<8) {
                outInd = n-3;
            }
            else if ( n<13) {
                outInd = n-2;
            }
            else {
                outInd = n-1;
            }
            ind = rand() % pool.size();
            cout << "n: " << n << " , ind: " << ind << " , pool[ind]: " << pool[ind] << endl;
            out[outInd] = pool[ind];
            pool.erase (pool.begin()+ind);
        }
    }

    return out;
}
