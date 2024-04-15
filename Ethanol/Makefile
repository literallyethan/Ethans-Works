bin/program : obj/main.o obj/lexer.o
	gcc obj/main.o obj/lexer.o -o bin/compiler

obj/main.o: src/main.c
	gcc -c src/main.c -o obj/main.o

obj/lexer.o: src/lexer.c include/lexer.h
	gcc -c src/lexer.c -o obj/lexer.o

clean:
	rm obj/*.o bin/*
