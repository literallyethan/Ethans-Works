#include <stdio.h>
#include <stdlib.h>

typedef  struct __attribute__((__packed__)) {
    int x;
    char str[10];
} my_struct;

int main(int argc, *argv[]) {
    my_struct type = {5, "Hello"};
    printf("size of my_struct: %ld\n", sizeof(type));

    //create and free an array of my_structs
    my_struct* arr = (my_struct*)malloc(sizeof(my_struct) * 5);

    free(arr);
    arr = NULL; //set to NULL to avoid dangling pointer

    //current wd: /home/ethan/Documents/C codes/low_level_edu/scratch/build



    return 0;
}
