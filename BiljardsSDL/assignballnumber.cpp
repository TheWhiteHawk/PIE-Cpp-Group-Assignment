#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

vector<int> assignballnumber() {
    srand (time(NULL));
    vector<int> out(16);
    vector<int> pool(out.size());           //set pool size equal to the size of the out vector
    //Include all the posible balls in the pool array
    for (int n = 0; n<pool.size(); n++) {
        pool[n] = n;
    }
    int ind;
    int N = pool.size();
    //loop to assign every ball a random number
    for (int n = 0; n<N; n++) {
        if (n == 0) { //set ball 0 to 0, the cue ball
            ind = 0;
            out[ind] = pool[ind];
            pool.erase (pool.begin()+ind); //erase the element from the array pool
        }
        else if (n == 1) { //set ball 5 to be the 8ball
            ind = 7;
            out[5] = pool[ind];
            pool.erase (pool.begin()+ind);
        }
        else if (n == 2) { // set the back corner balls to a random half an full ball.
            int corner = rand() % 2;
            if (corner == 0){
                ind = rand() % 7 + 7;
                out[11] = pool[ind];
                pool.erase (pool.begin()+ind);
                ind = rand() % 7;
                out[15] = pool[ind];
                pool.erase (pool.begin()+ind);
            }
            else {
                ind = rand() % 7 + 7;
                out[15] = pool[ind];
                pool.erase (pool.begin()+ind);
                ind = rand() % 7;
                out[11] = pool[ind];
                pool.erase (pool.begin()+ind);
            }
            n++;
        }
        else { //distribute the remaining balls random over the grid
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
            out[outInd] = pool[ind];
            pool.erase (pool.begin()+ind);
        }
    }

    return out;
}
