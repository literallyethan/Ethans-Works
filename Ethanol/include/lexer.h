#ifndef LEXER_H
#define LEXER_H

void test_print();

// given a file with a .etl extension,
// the lexer will iterate the file word by word
// separated by whitespace. The lexer will check is word
// and symbol, and if the word or symbol has a corresponding
// token, the token is printed. Else, the program terminates
// with an error.


// each call to lexer finds the next word and tokenizes it if it
// can be tokenized. If it cannot be tokenized, close fd of 
// src file and return error.
void lexer(const int* fdptr);




#endif
