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
	cps.push_back(sqrt(0.1) * destory(2));

	double dt = 0.01;
	double gamma = 1.0;

	int runs = 500;
	int steps = 2000;

	std::vector<double> result;

	//Timing
	clock_t tstart = clock();

	result = mcSolve(H,psi0,cps,dt,gamma,runs,steps);

	printf("Time Taken: %.5fs\n", (double)(clock() - tstart)/CLOCKS_PER_SEC);

	//print out results

	std::ofstream file;
	file.open("Data.dat");

	double temp = 0;
	for(int k = 0;k < steps;k++)
	{
		for(int j = 0;j < runs;j++)
		{
			temp += result[(j*steps) + k];
		}
		file << std::setprecision(10) << temp/runs <<"\n"; 
		temp = 0;
	}
	std::cout << "####################  Simulation Completed  ####################\n";
	
	return 0;
}