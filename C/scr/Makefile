all: build clean

build: main.o
	gcc main.o -o bin -L../lib/matrix -lmatrix -L../lib/get -lget

main.o: main.c
	gcc -c main.c

clean:
	rm -rf *.o