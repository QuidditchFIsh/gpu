
all: Qmatrix.o main_test.o
	g++ Qmatrix.o main_test.o -o Qmatrix

Qmatrix.o: Qmatrix.cpp headers/Qmatrix.h
	g++ -c Qmatrix.cpp
	
main_test.o: main_test.cpp headers/main_test.h
	g++ -c main_test.cpp

clean:
	rm *.o Qmatrix