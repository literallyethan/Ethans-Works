TARGET = bin/final
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC)) # every c in src will become an obj in obj

run: clean default
	#./$(TARGET) -f ./mynewdb.db -n #test to make sure it makes a new db
	#./$(TARGET) -f ./mynewdb.db -n #dupe test

default: $(TARGET) #for build to be complete, target must be complete

clean: # removes all nonsource
	rm -f obj/*.o
	rm -f bin/*
	rm -f *.db

$(TARGET): $(OBJ) #for target to be complete, obj must be complete
	gcc -o $@ $? #$@ means output, $? means list of input files

obj/%.o : src/%.c #for every .c, compile it into a .o
	gcc -c $< -o $@ -Iinclude # $< is input file, $@ is output file
