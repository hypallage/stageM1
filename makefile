CC=g++ 
CFLAGS=-Wall
main: main.o lattin_check.o lattin_rectangle.o

clean:
	rm -f main main.o lattin_check.o lattin_rectangle.o