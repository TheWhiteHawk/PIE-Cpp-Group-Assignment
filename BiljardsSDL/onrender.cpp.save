#include"game.h"
#include"drawcircle.h"

void game::OnRender()
{
    //Clear Render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Render gray filled quad
    SDL_Rect fillRect1 = { CORNER_X-CORNER_BALL_RATIO*BALL_RADIUS*2, CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS*2, TABLE_WIDTH+CORNER_BALL_RATIO*BALL_RADIUS*4, TABLE_HEIGHT+CORNER_BALL_RATIO*BALL_RADIUS*4 };
	SDL_SetRenderDrawColor( renderer, 120, 120, 120, 255 );
	SDL_RenderFillRect( renderer, &fillRect1 );

    //Render green filled quad
    SDL_Rect fillRect = { CORNER_X, CORNER_Y, TABLE_WIDTH, TABLE_HEIGHT };
	SDL_SetRenderDrawColor( renderer, 0, 140, 0, 255 );
	SDL_RenderFillRect( renderer, &fillRect );

    //Draw blue horizontal line
	//SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
	//SDL_RenderDrawLine( renderer,140+ time/10, 30, 140+45, 60+time/10 );




    //Test Corner Radius
    SDL_Point center = {CORNER_X+CORNER_CORNER, CORNER_Y-CORNER_BALL_RATIO*BALL_RADIUS};
    int radius = CORNER_BALL_RATIO*BALL_RADIUS;
    SDL_Color color = {.r = 255, .g = 255, .b = 255};
    draw_circle(renderer, center, radius, color);



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
        draw_circle(renderer, center, radius, sideColor);
    }







//    SDL_Point center = {200+time/5, 200};
//    int radius = time/10;
//    SDL_Color color = {.r = 255, .g = 255, .b = 255};
//    draw_circle(renderer, center, radius, color);





    SDL_RenderPresent( renderer );
}
