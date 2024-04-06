build:
	gcc -Wall ./*.c -o game -lSDL2

cross_build:
	x86_64-w64-mingw32-gcc -Wall -I/usr/x86_64-w64-mingw32/include/SDL2 -L/usr/x86_64-w64-mingw32/lib ./*.c -o yourapp.exe -lSDL2main -lSDL2 -static-libgcc -static-libstdc++
	
run:
	./game

clean:
	rm game
