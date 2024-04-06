#ifndef OBJECTS_H
#define OBJECTS_H

//struct strutures
typedef struct obj {
    float x, y, width, height;
    int horizontal_speed;
    int vertical_speed;
} Object;

//use balls for paddles
/*typedef struct paddle {
    float x, y, width, height;

} Paddle;
*/

//all of these are declared in the .c
extern Object ball;
extern Object paddle1;
extern Object paddle2;


#endif // OBJECTS_H
