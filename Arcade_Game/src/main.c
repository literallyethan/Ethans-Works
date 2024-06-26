#include <stdio.h>
#include <SDL2/SDL.h>
#include "./constants.h"

int game_is_running = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int last_frame_time = 0;

struct ball {
    float x, y, width, height;
} ball;

int initialize_window(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    ); //null means no title

    if(!window) {
        fprintf(stderr, "Error creating an SDL window.\n");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1, //default display driver
        0 //no special flags
    );

    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return FALSE;
    }

    return TRUE;
}

void process_input() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        //SDL_QUIT is the x button on window
        case SDL_QUIT:
            game_is_running = FALSE;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                game_is_running = FALSE;
            }
            break;
            
    }       
}

void update() {
    //dont use while loop, cruel to cpu
    //while(
    //    !SDL_TICKS_PASSED(SDL_GetTicks(), 
    //    last_frame_time + FRAME_TARGET_TIME)
    // ); //hit target time, release execution

    //multiply by this to think per second rather than per frame

    //use SDL_Delay to cap framerate, uncapped atm

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    
    last_frame_time = SDL_GetTicks();

    ball.x += 70 * delta_time; //70 pixels per second
    ball.y += 50 * delta_time;
}

void setup() {
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}

void render() {
    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        0,
        255
    );
    SDL_RenderClear(renderer);

    //TODO: draw objects here
    
    SDL_Rect ball_rect = {
        (int)ball.x,
        (int)ball.y,
        (int)ball.width, 
        (int)ball.height
    };

    SDL_SetRenderDrawColor(
        renderer,
        255,
        255,
        255,
        255
    );

    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_RenderPresent(renderer);
}

void destroy_window() {
    //everything is destroyed in reverse
    //creation order

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(void)
{
    game_is_running = initialize_window();

    setup();

    while(game_is_running) {
        process_input();
        update();
        render();
    }

    puts("Game Running...");
    destroy_window();

    return 0;
}



