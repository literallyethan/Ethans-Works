#include <stdio.h>

#include "../include/lexer.h"

void test_print() {
	puts("Hello, World!");

}

char* lookup(char* token) {
	// start with if else,
	// very slow but we gotta get mvp
	
	if (token == "using") {
		return "[USING]";
	} else {
		return "[ID]"
	}

	return NULL;
}

void lexer(FILE* file) {
	// start at 0 in the file, and tokenize the read word
	// after hitting a whitespace

	// once you hit a whitespace after a letter,
	// look up the token.

	// store visited chars in token[], and when a 
	// whitespace is hit, flush token[]. 
	// token will be passed to lookup().
	
	short n = 21;
	char token[n] = {0};
	
	int ch;
	while ((ch = fgetc(file)) != EOF)  {
		// push char into token[]
		// when hit whitespace,
		// lookup()
	}
		
}
