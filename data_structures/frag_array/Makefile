bin/program: obj/main.o obj/frag_arr.o
	gcc obj/main.o obj/frag_arr.o -o bin/program

obj/main.o: src/main.c
	gcc -c src/main.c -o obj/main.o

obj/frag_arr.o: src/frag_arr.c include/frag_arr.h
	gcc -c src/frag_arr.c -o obj/frag_arr.o

clean: 
	rm obj/*.o bin/*

# target: dependencies
	# action
