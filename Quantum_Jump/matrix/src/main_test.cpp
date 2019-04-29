#include "headers/main_test.h"

int main()
{
	Qmatrix x = basis(2,0);
	Qmatrix y = basis(2,0);
	x = bra2ket(x);
	std::cout << x << "\n";
	std::cout << y << "\n";
	std::cout << x * y << "\n";
	return 0;
}

void mcSolve()
{

}