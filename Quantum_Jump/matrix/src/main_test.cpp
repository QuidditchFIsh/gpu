#include "headers/main_test.h"

#define PI 3.141592655
#define PI2 2*PI

int main()
{
	std::cout << "#####################  Begining Simulation  ####################\n";
	//Define all of the parameters to be used
	Qmatrix a = destory(2);
	Qmatrix a_dag = a.hermitian_conj();
	double omega = 5;
	//Define the hamiltonian
	Qmatrix H = 5 * a * a_dag;
	//Define the inital State
	Qmatrix psi0 = basis(2,0);
	//Define a vector of collapse operators
	std::vector<Qmatrix> collapse;
	collapse.push_back(0.3 * a);
	//Define the time stpes 
	double delta_t = 0.01;

	//Evolve with the Monte carlo function
	mcSolve(H,psi0,collapse,delta_t);

	std::cout << "####################  Simulation Completed  ####################\n";
	//Add timiing of simulation here
	return 0;
}

void mcSolve(Qmatrix& H,Qmatrix& inital,std::vector<Qmatrix>& Cps,double dt)
{
	//Define imaginary 1
		std::complex<double> _ONEI (0.0,1.0);
	//Define the evolved state 
	Qmatrix Evolved(inital);
	//Evolve the state
	Evolved = Evolved - (_ONEI * dt) * H * inital;
}