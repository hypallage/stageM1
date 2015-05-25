CC=g++ 
CFLAGS=-Wall
main: main.o element.o lattin_rectangle.o lattin_check.o parser.o

clean:
	rm -f main main.o element.o lattin_rectangle.o lattin_check.o parser.o
