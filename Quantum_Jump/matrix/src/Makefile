
all: Qmatrix.o operators.o main_test.o
	g++ Qmatrix.o operators.o main_test.o -o Qmatrix

Qmatrix.o: Qmatrix.cpp headers/Qmatrix.h
	g++ -c Qmatrix.cpp
	
operators.o: operators.cpp headers/operators.h
	g++ -c operators.cpp

main_test.o: main_test.cpp headers/main_test.h
	g++ -c main_test.cpp

clean:
	rm *.o Qmatrix