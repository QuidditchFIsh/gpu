
all: main.o
	g++ main.o -o QuantJump

main.o: main.cpp headers/main.h
	g++ -c main.cpp

clean:
	rm *.o QuantJump