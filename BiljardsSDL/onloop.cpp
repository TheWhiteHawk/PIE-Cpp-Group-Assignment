#include"game.h"
void game::OnLoop ()
{
    time = SDL_GetTicks();
    double timeInBetweenFrames = time-previousTime;
    //cout << "dt: " << timeInBetweenFrames << endl;
    FPS = 1000/(timeInBetweenFrames);
    //cout << "FPS: " << FPS << endl;
    previousTime = time;

    int numberOfSteps = ceil(timeInBetweenFrames/maxDt);
    double dt = (timeInBetweenFrames/numberOfSteps)/1000;

    //Loop for updating positions, velocities and collisions
    double rolingResistanceCoefficient = 0.010; //mu ball cloth
    double g = 9.81;
    double a_m = g*rolingResistanceCoefficient; //acceleration in m/s^2
    double a = a_m*PIXEL_METER_RATIO; //acceleration in px/s^2
    double restitutionCoefficientWalls = 0.6;

    for (int t=0; t<numberOfSteps; t++) {
        //----------------------VARIABLE-UPDATE----------------------
        //update positions
        for (int n = 0; n<balls.size(); n++) {
            //update positions
            balls[n].setPreviousPosition(balls[n].getPosition());
            vector<double> newPos(2);
            for (int m = 0; m<2; m++)  {  newPos[m] = balls[n].getPosition()[m] + dt*balls[n].getVelocity()[m];  }
            balls[n].setPosition(newPos);

            //update velocity due to friction
            vector<double> newVel(2);
            double velMagnitude = vectorMagnitude(balls[n].getVelocity());
            if (velMagnitude < dt*a) {
                newVel = {0,0};
            }
            else {
                newVel[0] = balls[n].getVelocity()[0] - vectorCos(balls[n].getVelocity())*dt*a;
                newVel[1] = balls[n].getVelocity()[1] - vectorSin(balls[n].getVelocity())*dt*a;
            }

            balls[n].setVelocity(newVel);
        }

        //Ball on ball collisions
        for (int i = 0; i < (balls.size() - 1); i++){
            for (int j = i; j < balls.size(); j++){
                double restitutionCoefficientBalls = 0.9;
                collisionBalls(balls[i],balls[j],restitutionCoefficientBalls);
            }
        }

        //Wall collitions
        //Flat wall ranges
        double A = POCKET_CORNER_BALLS[0].getPosition()[0]; //X coordinate pocket ball 0
        double B = POCKET_CORNER_BALLS[2].getPosition()[0]; //X coordinate pocket ball 2
        double C = POCKET_CORNER_BALLS[8].getPosition()[0]; //X coordinate pocket ball 8
        double D = POCKET_CORNER_BALLS[6].getPosition()[0]; //X coordinate pocket ball 6
        double E = POCKET_CORNER_BALLS[1].getPosition()[1]; //Y coordinate pocket ball 1
        double F = POCKET_CORNER_BALLS[4].getPosition()[1]; //Y coordinate pocket ball 4

        for (int i = 0; i < balls.size(); i++){
            //Checking if the ball has scored
            bool hasScored = balls[i].getHasScored();
            if (!hasScored){
                std::vector<double> r = balls[i].getPosition();
                //----------------------SCORING-CHECK----------------------
                //Checking if the balls experience flat wall collisions or corner collisions/scoring
                if ((   (r[0]<A) || (r[0]>B&&r[0]<C) || (r[0]>D)   ) && ( r[1]<E || r[1]>F )){
                    //Ball is able to score or the collide on a pocket corner in this area
                    //If statement for scoring conditions of individual pockets
                        //Top left pocket
                        if (r[1]+r[0] <= POCKET_CORNER_BALLS[0].getPosition()[0]+POCKET_CORNER_BALLS[0].getPosition()[1]){
                            hasScored = true;
                        }
                        //Top middle pocket
                        if (r[1] <= POCKET_CORNER_BALLS[2].getPosition()[1]){
                            hasScored = true;
                        }
                        //Top right pocket
                        if (r[1]-r[0] <= POCKET_CORNER_BALLS[6].getPosition()[1]-POCKET_CORNER_BALLS[6].getPosition()[0]){
                            hasScored = true;
                        }
                        //Bottom left pocket
                        if (r[1]-r[0] >= POCKET_CORNER_BALLS[3].getPosition()[1]-POCKET_CORNER_BALLS[3].getPosition()[0]){
                            hasScored = true;
                        }
                        //Bottom middle pocket
                        if (r[1] >= POCKET_CORNER_BALLS[5].getPosition()[1]){
                            hasScored = true;
                        }
                        //Bottom right pocket
                        if (r[1]+r[0] >= POCKET_CORNER_BALLS[9].getPosition()[0]+POCKET_CORNER_BALLS[9].getPosition()[1]){
                            hasScored = true;
                        }

                    //----------------------ACTIONS-UPON-SCORE----------------------
                    //Checks if a ball has scored, then it set the score variable of the ball to true
                    //and its velocity vector to a zero vector
                    if (hasScored){
                        balls[i].setHasScored(hasScored);
                        balls[i].setVelocity(vector<double>{0,0});
                        cout << "Ball " << balls[i].getBallNumber() << " has scored" << endl;


                        int ballNumber = balls[i].getBallNumber(); //Declare the ball number for compacter notation
                        bool isFull; //Boolean for the type of the first scored ball
                        if ((ballNumber > 0) && (ballNumber != 8)){
                            scoreHappend = true; //Boolean to keep track if balls have been scored during a turn
                            //A check is done on which type of ball has been scored
                            if (ballNumber < 8){
                                isFull = true;
                                allHalf = false;
                            }
                            else{
                                isFull = false;
                                allFull = false;
                            }

                            //---------------------BALL-ASSIGNMENT----------------------
                            //Balls to player assignment when the first ball is scored
                            if (firstScore){
                                if (firstPlayer){
                                    firstPlayerIsFull = isFull;
                                }
                                else{
                                    firstPlayerIsFull = !isFull;
                                }
                                firstScore = false;
                            }

                        }
                        //Scoring the cue ball is not counted as a ball being scored
                        if (ballNumber == 0){
                            scoreHappend = false;
                        }
                    }
                    //---------------------POCKET-CORNER-COLLISION-CHECK----------------------
                    //Ball on corner collisions, but only if there was no score
                    else {
                        for (int j = 0; j < POCKET_CORNER_BALLS.size(); j++){
                            collisionBalls(balls[i],POCKET_CORNER_BALLS[j],restitutionCoefficientWalls);
                        }
                    }
                }
                //----------------------FLAT-WALL-COLLISION-CHECK----------------------
                //Ball on wall collisions
                else{
                    //Relevant table dimensions
                    double W = TABLE_WIDTH;
                    double H = TABLE_HEIGHT;
                    double cornerX = CORNER_X;
                    double cornerY = CORNER_Y;

                    //Relevant ball variables
                    double R = balls[i].getRadius();
                    std::vector<double> v = balls[i].getVelocity();

                    //Collision conditions for the walls
                    if ((r[0]<CORNER_X+R) && v[0]<0){
                        v[0] = -restitutionCoefficientWalls*v[0];
                    }
                    if ((r[0]>CORNER_X+W-R) && v[0]>0){
                        v[0] = -restitutionCoefficientWalls*v[0];
                    }
                    if ((r[1]<CORNER_Y+R) && v[1]<0){
                        v[1] = -restitutionCoefficientWalls*v[1];
                    }
                    if((r[1]>CORNER_Y+H-R) && v[1]>0){
                        v[1] = -restitutionCoefficientWalls*v[1];
                    }
                    balls[i].setVelocity(v);
                }
            }
        }
    }


    //----------------------TURN-END-CONDITIONS----------------------
    //Check if all balls which are in play have a velocity of 0
    zeroVel = true;
    for ( int n=0; n< balls.size(); n++) {
        if (!balls[n].getHasScored()) {
            if ( vectorMagnitude(balls[n].getVelocity()) > pow(10,-200)){
                zeroVel = false;
                newTurn = false;
            }
        }
    }

    //----------------------END-GAME-CHECKS----------------------
    //End game and winning conditions

    //The game ends when the 8-ball is pocketed
    //The state of the game (i.e. which balls are still on the table when the 8-ball is pocketed)
    //and the player who pockets the 8-ball determine which player wins the game
    bool fullAllScored = true;
    bool halfAllScored = true;
    bool fullHasWon;
    if (!gameEnd){
        //A check is done for all balls to see if the entire set of balls (e.g. half or full balls) has been pocketed
        for (int i = 0; i < balls.size(); i++){
            int ballNumber = balls[i].getBallNumber();
            //Checking all the balls except for the 8-ball and the cue ball
            if (ballNumber > 0){
                if (ballNumber != 8){
                    //If a ball in the full or half set has not scored the corresponding boolean is set to false
                    if (!balls[i].getHasScored()){
                        if (ballNumber < 8){
                            fullAllScored = false;
                        }
                        else{
                            halfAllScored = false;
                        }
                    }
                }
                //The gameEnd boolean has the same value as the hasScored boolean in the 8-ball
                else{
                    gameEnd = balls[i].getHasScored();
                }
            }
        }
    }

    //----------------------WINNING-CONDITIONS----------------------
    //The player who pockets the 8-ball after pocketing all his own balls wins
    //The player who pockets the 8-ball before pocketing all his own balls loses
    if (gameEnd && fullAllScored){
        fullHasWon = true;
    }
    if (gameEnd && halfAllScored){
        fullHasWon = false;
    }

    if (gameEnd && ((fullAllScored && !halfAllScored) || (halfAllScored && !fullAllScored))){
        if (firstPlayerIsFull == fullHasWon){
            firstPlayerWins = true;
            cout << "Player 1 wins!" << endl;
        }
        else{
            firstPlayerWins = false;
            cout << "Player 2 wins!" << endl;
        }
    }
    else if (gameEnd && fullAllScored && halfAllScored){
        if (firstPlayer){
            firstPlayerWins = true;
            cout << "Player 1 wins!" << endl;
        }
        else{
            firstPlayerWins = false;
            cout << "Player 2 wins!" << endl;
        }
    }
    else if (gameEnd){
        if (!firstPlayer){
            firstPlayerWins = true;
            cout << "Player 1 wins!" << endl;
        }
        else{
            firstPlayerWins = false;
            cout << "Player 2 wins!" << endl;
        }
    }

    //----------------------GAME-END----------------------
    if (gameEnd){
        cout << "Game has ended" << endl;
        stopRunning();
    }

    //---------------------ACTIONS-ON-TURN-END----------------------
    //Only execute on the first time step after pbool hasScoredlay
    if (zeroVel&&firstTimeStepAfterPlay){
        //---------------------PLAYER-SWITCHING-CONDITIONS----------------------
        //Player switching does not happen when a player only pockets balls that belong to him during a turn
        //it does happen when any other ball is pocketed or no ball is pocketed
        if (scoreHappend){
            if (firstPlayer){
                if (firstPlayerIsFull){
                    if (allFull){
                        shouldSwitch = false;
                    }
                    else{
                        shouldSwitch = true;
                    }
                }
                else{
                    if (allHalf){
                        shouldSwitch = false;
                     }
                     else{
                        shouldSwitch = true;
                    }
                }
            }
            else{
                if (!firstPlayerIsFull){
                    if (allFull){
                        shouldSwitch = false;
                    }
                    else{
                        shouldSwitch = true;
                    }
                }
                else{
                    if (allHalf){
                        shouldSwitch = false;
                    }
                    else{
                        shouldSwitch = true;
                    }
                }
            }
        }

        //Switching the player
        if (shouldSwitch){
            switch (firstPlayer){
                case true: firstPlayer = false; break;
                case false: firstPlayer = true; break;
            }
        }

        //---------------------REMAINING-ACTIONS----------------------
        //Booleans that need to be reset for ever turn
        firstTimeStepAfterPlay = false;
        newTurn = true;
        shouldSwitch = true;
        scoreHappend = false;
        allFull = true;
        allHalf = true;


        //Repositioning the cue ball when it has been pocketed
        if (balls[0].getHasScored() ) {
            balls[0].setHasScored(false);
            balls[0].setPosition(vector<double>{TABLE_WIDTH/4+CORNER_X,TABLE_HEIGHT/2+CORNER_Y});
        }
    }
}
