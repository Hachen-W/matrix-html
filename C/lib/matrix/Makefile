all: build clean

build: matrix.o
	ar r libmatrix.a *.o

matrix.o: matrix.c
	gcc -c matrix.c -L../lib/get -lget

clean:
	rm -rf *.o