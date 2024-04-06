#include "render.h"
#include "game.h"
#include "constants.h"

extern SDL_Renderer* renderer;
extern Object ball;
extern Object paddle1;
extern Object paddle2;

void vertical_dotted_line(
    int seg_length,
    int seg_width, 
    int top_bound, 
    int bottom_bound) 
{
    //x, y, width, height
    SDL_Rect line_segment = {
        (WINDOW_WIDTH / 2) - (seg_width / 2),
        top_bound, //length to be changed in loop
        seg_width,
        seg_length
    };

    for(int i = top_bound; i <= WINDOW_HEIGHT; i += 2 * seg_length) {
        SDL_RenderFillRect(renderer, &line_segment);
        line_segment.y = i;
    }    
}

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect ball_rect = {
        (int)ball.x,
        (int)ball.y,
        (int)ball.width, 
        (int)ball.height
    };

    SDL_Rect paddle1_rect = {
        (int)paddle1.x,
        (int)paddle1.y,
        (int)paddle1.width,
        (int)paddle1.height
    };

    SDL_Rect paddle2_rect = {
        (int)paddle2.x,
        (int)paddle2.y,
        (int)paddle2.width,
        (int)paddle2.height
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball_rect);
    SDL_RenderFillRect(renderer, &paddle1_rect);
    SDL_RenderFillRect(renderer, &paddle2_rect);

    //try to render dotted line
    
    vertical_dotted_line(
        WINDOW_HEIGHT / 15,
        (WINDOW_HEIGHT / 10) / 4,
        (WINDOW_HEIGHT / 15),
        WINDOW_WIDTH
    );

    

    SDL_RenderPresent(renderer);
}
