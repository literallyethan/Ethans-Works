#include "game.h"
#include "constants.h"
#include "objects.h"

float delta_time = 0;

void process_input() {
//TODO: fix paddle choppiness with GetKeyboardState

    SDL_Event event1;
    SDL_PollEvent(&event1);    

    switch(event1.type) {
        case SDL_QUIT:
            game_is_running = FALSE;
        break;
        case SDL_KEYDOWN:
            switch(event1.key.keysym.sym) {
                case SDLK_ESCAPE:
                    game_is_running = FALSE;
                break;
                case SDLK_w:
                case SDLK_a:
                    paddle1.y -= paddle1.vertical_speed * delta_time;
                break;
                case SDLK_s:
                case SDLK_d:
                break;
            }
/*
            if(event1.key.keysym.sym == SDLK_ESCAPE) {
                game_is_running = FALSE;
            }
*/
        break;    
    }       
}

void update() {
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();

    bounce_wall(delta_time);

    ball.x += ball.horizontal_speed * delta_time;
    ball.y += ball.vertical_speed * delta_time;
}

void setup() { 
    ball.width = 15;
    ball.height = 15;
    ball.x = 20;
    ball.y = 20;
    ball.horizontal_speed = 200; //original speed is 70 for both
    ball.vertical_speed = 200;

    paddle1.width = 15;
    paddle1.height = WINDOW_HEIGHT / 4;
    paddle1.x = WINDOW_WIDTH / 10;
    paddle1.y = (WINDOW_HEIGHT / 2) - (paddle1.height / 2);
    paddle1.vertical_speed = PADDLE_SPEED;

    paddle2.width = 15;
    paddle2.height = WINDOW_HEIGHT / 4;
    paddle2.x = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
    paddle2.y = (WINDOW_HEIGHT / 2) - (paddle1.height / 2);
    paddle2.vertical_speed = PADDLE_SPEED;
}

void bounce_wall(float delta_time) {
    /*
        if the ball hits the top or bottom border, invert polarity
        of the ball's Y axis movement.
    */   

    //checks to see if ball is hitting anything
    if (ball.y + ball.vertical_speed * delta_time >= WINDOW_HEIGHT - 1 &&
        ball.vertical_speed > 0)
    {
        ball.vertical_speed = -ball.vertical_speed; //negates speed
    } else if (
        ball.y + ball.vertical_speed * delta_time <= 1 &&
        ball.vertical_speed < 0)
    {
        ball.vertical_speed = -ball.vertical_speed;
    }
}
