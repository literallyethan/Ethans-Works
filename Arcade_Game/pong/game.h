#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "./objects.h"

extern int game_is_running;
extern int last_frame_time;

void process_input();
void update();
void setup();

void bounce_wall(float delta_time); //if this name makes problems, change it

#endif // GAME_H
