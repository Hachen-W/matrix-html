all: build clean

build: get.o
	ar r libget.a *.o

get.o: get.c
	gcc -c get.c

clean:
	rm -rf *.o