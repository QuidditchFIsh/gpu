#include "headers/main_test.h"

#define PI 3.141592655
#define PI2 2*PI


int main()
{
	
	std::cout << "#####################  Begining Simulation  ####################\n";
	//Define all of the parameters to be used
	std::complex<double> ONEI (0.0,1.0);

	std::vector<H_part> H;

	H_part H1 = {.H0 = 0.5*destory(2), .H_func_ptr = &q1};
	H_part H2 = {.H0 = 0.5*destory(2).hermitian_conj(), .H_func_ptr = &q1d};

	H.push_back(H1);
	H.push_back(H2);

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

	mcSolve(H,psi0,cps,dt,gamma,runs,steps);

	printf("Time Taken: %.5fs\n", (double)(clock() - tstart)/CLOCKS_PER_SEC);

	//print out results

	std::ofstream file;
	file.open("Data.dat");
/*
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
*/	
	
	
	return 0;
}

std::complex<double> q1(double t)
{
	double w1 = 0;
	double w = 0;
	const std::complex<double> i(0,1);
	return cos(w*t) * std::exp(i * w1 * t);
}

std::complex<double> q1d(double t)
{
	double w1 = 0;
	double w = 0;
	const std::complex<double> im(0,-1);
	return cos(w*t) * std::exp(im * w1 * t);
}
