CC=g++ 
CFLAGS=-Wall
main: main.o element.o lattin_rectangle.o

clean:
	rm -f main main.o element.o lattin_rectangle.o
