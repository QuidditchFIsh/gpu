#include "headers/main_test.h"

#define PI 3.141592655
#define PI2 2*PI


int main()
{
	
	std::cout << "#####################  Begining Simulation  ####################\n";
	//Define all of the parameters to be used
	std::complex<double> ONEI (0.0,1.0);

	Qmatrix H =  0.6*(destory(2) + destory(2).hermitian_conj());

	Qmatrix psi0 = basis(2,1);

	std::vector<Qmatrix> cps;
	cps.push_back(destory(2));

	double dt = 0.01;
	double gamma = 0.1*0.1;

	//Timing
	clock_t tstart = clock();

	mcSolve(H,psi0,cps,dt,gamma);

	printf("Time Taken: %.5fs\n", (double)(clock() - tstart)/CLOCKS_PER_SEC);

	std::cout << "####################  Simulation Completed  ####################\n";
	
	return 0;
}

