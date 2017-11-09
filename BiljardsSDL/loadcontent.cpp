#include"game.h"
bool game::LoadContent ()
{
    vector<double> row(2);

    const vector<double> X_OFFSET {CORNER_X , CORNER_X+TABLE_WIDTH};
    const vector<double> Y_OFFSET {CORNER_Y , CORNER_Y+TABLE_HEIGHT};

    for (int x = 0; x<2; x++){
        for(int y = 0; y<2; y++){
            for(int n = 0; n<2; n++){
                row[n] = (CORNER_CORNER);
                row[(n+1)%2] = (-CORNER_BALL_RATIO*BALL_RADIUS);
                //Mirror pockets
                row[0] = row[0]*pow(-1,x) + X_OFFSET[x];
                row[1] = row[1]*pow(-1,y) + Y_OFFSET[y];
                POS_POCKET_CORNER_BALLS.push_back(row);
            }
            row[0] = (TABLE_WIDTH/2 - (POCKET_BALL_RATIO+CORNER_BALL_RATIO)*BALL_RADIUS);
            row[1] = (-CORNER_BALL_RATIO*BALL_RADIUS);
            //Mirror pockets
            row[0] = row[0]*pow(-1,x) + X_OFFSET[x];
            row[1] = row[1]*pow(-1,y) + Y_OFFSET[y];
            POS_POCKET_CORNER_BALLS.push_back(row);
        }
    }






//    for(int n = 0; n<4; n++){
//        vector<double> row {n , n};
//        POS_POCKET_CORNER_BALLS.push_back(row);
//    }




 return 1;
}
