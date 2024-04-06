#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
}

int main(int argc, char* argv[]) {
    struct stat dbStat = {0};
    // fstat to get file metadata

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    //argc is always at least 1
    //argv[0] is always the name of the program
    //argv[1] is first argument
    //bitwise or means it combines the flags of both, using both values
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644); //0 for octal, 6 for me read write,
        //4 for groupies to read, 4 for outsiders to read
    if (fd == -1) {
        perror("open");
        return -1;
    }

    char* mydata = "hello there file!\n";
    write(fd, mydata, strlen(mydata));

    close(fd);
    //should probably close fd's like freeing malloc

    return 0;
}
