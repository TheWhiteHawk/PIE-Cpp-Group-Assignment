#include"game.h"

void game::OnRender()
{

    //Clear Render and set the background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Render green filled quad
    SDL_Rect fillRect = { CORNER_X-CORNER_BALL_RATIO*BALL_RADIUS, CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS, TABLE_WIDTH+CORNER_BALL_RATIO*BALL_RADIUS*2, TABLE_HEIGHT+CORNER_BALL_RATIO*BALL_RADIUS*2 };
	SDL_SetRenderDrawColor( renderer, 0, 150, 0, 255 );
	SDL_RenderFillRect( renderer, &fillRect );

	//draw corners holes (triagle corners)
    DrawCornerHoles(renderer);



    //Divine center, radius and color for plotting circles
    SDL_Point center;
    int radius;
    SDL_Color color = {.r = 255, .g = 255, .b = 255};




    //Plot Side Pannels
    const vector<double> X_OFFSET {CORNER_X , CORNER_X+TABLE_WIDTH};
    const vector<double> Y_OFFSET {CORNER_Y , CORNER_Y+TABLE_HEIGHT};
    double rect_X;
    double rect_Y;
    double rect_width;
    double rect_height;
    SDL_Color sideColor = {.r = 0, .g = 80, .b = 0};
    SDL_Rect sidePanels;
    SDL_SetRenderDrawColor(renderer, sideColor.r, sideColor.g, sideColor.b, sideColor.a);
    for (int x = 0; x<2; x++){
        for(int y = 0; y<2; y++){
            rect_X = CORNER_CORNER*pow(-1,x) + X_OFFSET[x];
            rect_Y = 0*pow(-1,y) + Y_OFFSET[y];
            rect_width = (TABLE_WIDTH/2-(CORNER_CORNER+(POCKET_BALL_RATIO+CORNER_BALL_RATIO)*BALL_RADIUS))*pow(-1,x);
            rect_height = -CORNER_BALL_RATIO*BALL_RADIUS*2*pow(-1,y);
            sidePanels = { rect_X, rect_Y, rect_width, rect_height };
            SDL_RenderFillRect( renderer, &sidePanels );
        }
        rect_X = 0 + X_OFFSET[x];
        rect_Y = CORNER_CORNER + Y_OFFSET[0];
        rect_width =-CORNER_BALL_RATIO*BALL_RADIUS*2*pow(-1,x);
        rect_height = TABLE_HEIGHT-2*CORNER_CORNER;
        sidePanels = { rect_X, rect_Y, rect_width, rect_height };
        SDL_RenderFillRect( renderer, &sidePanels );
    }

    //Plot Corner Radii
    for(int n=0; n<POS_POCKET_CORNER_BALLS.size(); n++){
        center = {POS_POCKET_CORNER_BALLS[n][0], POS_POCKET_CORNER_BALLS[n][1]};
        radius = CORNER_BALL_RATIO*BALL_RADIUS;
        draw_circle(renderer, center, radius, sideColor,-1);
    }

    ///////////////////////////////////////////////////// Table Graphics over

    //Player 1 and 2 text
    SDL_Color playerTextColor = {.r = 255, .g = 255, .b = 255};
    int texW = 0;
    int texH = 0;
    SDL_Rect dstrect;



    for (int n = 0; n<2; n++) {
        switch (n) {
            case 0: surface = TTF_RenderText_Solid(font, firstPlayerMessage , playerTextColor); break;
            case 1: surface = TTF_RenderText_Solid(font, secondPlayerMessage , playerTextColor); break;
        }

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        dstrect = { SCREEN_WIDTH/2, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (n-1)*texH, texW, texH };
        //release memory
        SDL_FreeSurface(surface);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_DestroyTexture(texture);
    }

    //plot a full and half ball if balls are assigned to the players
    SDL_Color ballIndicatorColor = {.r = 255, .g = 0, .b = 0};
    if (!firstScore){
        if (!firstPlayerIsFull){
            center = {SCREEN_WIDTH/2+texW +2*BALL_RADIUS, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (1-0.5)*texH};
            draw_circle(renderer, center, BALL_RADIUS, ballIndicatorColor, 3);
            center = {SCREEN_WIDTH/2+texW +2*BALL_RADIUS, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (0-0.5)*texH};
            draw_circle(renderer, center, BALL_RADIUS, ballIndicatorColor, 11);
        }
        else if (firstPlayerIsFull){
            center = {SCREEN_WIDTH/2+texW +2*BALL_RADIUS, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (1-0.5)*texH};
            draw_circle(renderer, center, BALL_RADIUS, ballIndicatorColor, 11);
            center = {SCREEN_WIDTH/2+texW +2*BALL_RADIUS, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (0-0.5)*texH};
            draw_circle(renderer, center, BALL_RADIUS, ballIndicatorColor, 3);
        }
    }





    //firstPlayer =false;
    if (firstPlayer) {
        DrawPlayerIndicator(renderer, SCREEN_WIDTH/2-texH, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (0-1)*texH, texH, texH);
    }
    else{
        DrawPlayerIndicator(renderer, SCREEN_WIDTH/2-texH, (CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2)/2 + (1-1)*texH, texH, texH);
    }

    ////////////////////////////////////////////////////// Player indicator over
























    //Plot Balls with the correct colour
    SDL_Color ballColor = {.r = 255, .g = 255, .b = 255};
    SDL_Color scoredBallColor = {.r = 255, .g = 123, .b = 200};
    //cout << "balls.size() = " <<balls.size() << endl;
    for(int n=0; n<balls.size(); n++){
        switch (balls[n].getBallNumber()) {
            case 0: ballColor = {.r = 255, .g = 255, .b = 255}; break;
            case 1:
            case 9: ballColor = {.r = 255, .g = 220, .b = 0}; break;
            case 2:
            case 10: ballColor = {.r = 0, .g = 0, .b = 255}; break;
            case 3:
            case 11: ballColor = {.r = 255, .g = 0, .b = 0}; break;
            case 4:
            case 12: ballColor = {.r = 255, .g = 0, .b = 255}; break;
            case 5:
            case 13: ballColor = {.r = 255, .g = 128, .b = 0}; break;
            case 6:
            case 14: ballColor = {.r = 0, .g = 100, .b = 0}; break;
            case 7:
            case 15: ballColor = {.r = 102, .g = 51, .b = 0}; break;
            case 8: ballColor = {.r = 0, .g = 0, .b = 0}; break;
        }
        if (!balls[n].getHasScored()) {
            center = {balls[n].getPosition()[0], balls[n].getPosition()[1]};
            radius = balls[n].getRadius();
            draw_circle(renderer, center, radius, ballColor, balls[n].getBallNumber());
        }
    }



    //line in shooting direction
    //and line from the cursor to the cue ball

    if (zeroVel) {
        vector<double> relativeVector = {balls[0].getPosition()[0]-mousePos[0] , balls[0].getPosition()[1]-mousePos[1]};
        relativeVector = {relativeVector[0] * (mouseSpeedScaling), relativeVector[1]* (mouseSpeedScaling)};
        double magVec = vectorMagnitude(relativeVector);
        if (magVec > maxVel) {
            relativeVector = {relativeVector[0] * (maxVel/magVec), relativeVector[1]* (maxVel/magVec)};
        }
        relativeVector = {relativeVector[0] * (300/maxVel), relativeVector[1]* (300/maxVel)};

        SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
        SDL_RenderDrawLine(renderer, balls[0].getPosition()[0], balls[0].getPosition()[1], mousePos[0], mousePos[1] );

        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderDrawLine(renderer, balls[0].getPosition()[0], balls[0].getPosition()[1], balls[0].getPosition()[0] + relativeVector[0], balls[0].getPosition()[1] + relativeVector[1] );
    }














    //FPS meter
    char integer_string[32];
    sprintf(integer_string, "%d", FPS);
    char FPStext[64] = "FPS  ";
    strcat(FPStext, integer_string);

    SDL_Color textColor = {.r = 255, .g = 255, .b = 255};
    surface = TTF_RenderText_Solid(font, FPStext , textColor);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    dstrect = { 0, 0, texW, texH };

    //release memory
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);














    SDL_RenderPresent( renderer );
}
