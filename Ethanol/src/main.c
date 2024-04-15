#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/lexer.h"

void usage(char* argv[]) {
	printf("Usage: %s <name>.etl\n", argv[0]);
	

}

int main(int argc, char* argv[]) {
	test_print();
	char* filepath = NULL;
	FILE* file = NULL;
	int flags = 0;	
	
	// interperets flags
	while ((flags = getopt(argc, argv, "uc:")) != -1) {
		switch (flags) {
			case 'u':
				usage(argv);
				break;
			case 'c':
				filepath = optarg;
				break;
			default:
				return -1;
		}
	}
	
	file = fopen(filepath, "r");     // do not need to modify file
					 // to lex it

	if (file == NULL) {
		puts("error reading file.");
		return -1;
	}

//	lexer(file);


// terminate program

	fclose(file);
	return 0;
}
