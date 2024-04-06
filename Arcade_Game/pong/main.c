#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>
#include "init.h"
#include "game.h"
#include "render.h"
#include "constants.h"


int game_is_running = FALSE;
int last_frame_time = 0;


int main(int argc, char* argv[]) {
    game_is_running = initialize_window();

    setup();

    while (game_is_running) {
        process_input();
        update();
        render();
    }

    puts("Game Running...");
    destroy_window();

    return 0;
}
