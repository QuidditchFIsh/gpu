#include "headers/main_test.h"

#define PI 3.141592655
#define PI2 2*PI


int main()
{
	
	std::cout << "#####################  Begining Simulation  ####################\n";
	//Define all of the parameters to be used
/*
	//Size of the systems
	int N0 = 8;
	int N1 = 8;
	int N2 = 8;

	//Defining the operators
	Qmatrix q0 = tensor(destory(N0),Id(8));
	q0 = tensor(q0,Id(8));

	Qmatrix q1 = tensor(Id(8),destory(N1));
	q1 = tensor(q1,Id(8));

	Qmatrix q2 = tensor(Id(8),Id(8));
	q2 = tensor(q2,destory(N2));

	//Define the Hamliltonian

	Qmatrix H = (q0 * q1.hermitian_conj() * q2.hermitian_conj() - q0.hermitian_conj() * q1 * q2);
	
	Qmatrix C0 = q0.hermitian_conj() * q0;
	Qmatrix C1 = q1.hermitian_conj() * q1;
	Qmatrix C2 = q2.hermitian_conj() * q2;


	//Damping Rates
	double gamma0 = 0.1;
	double gamma1 = 0.1;
	double gamma2 = 0.4;

	C0 = sqrt(2.0 * gamma0) * q0;
	C1 = sqrt(2.0 * gamma1) * q1;
	C2 = sqrt(2.0 * gamma2) * q2;

	//Define the vector of collapse operators
	std::vector<Qmatrix> cps;
	cps.push_back(C0);
	cps.push_back(C1);
	cps.push_back(C2);


	//Inital state
	Qmatrix psi0 = tensor(basis(N0,0),basis(N1,0));
	psi0 = tensor(psi0,basis(N2,0));

	double dt = 0.05;

	//Begin the Monte Carlo Simulation

	//mcSolve(H,psi0,cps,dt);
*/

	std::complex<double> ONEI (0.0,1.0);

	Qmatrix H = 0.5 * 0.06 * (destory(2) + destory(2).hermitian_conj());
	//- 0.5*0.01*(destory(2)*destory(2).hermitian_conj())

	Qmatrix psi0 = basis(2,1);

	std::vector<Qmatrix> cps;
	cps.push_back(ONEI*0.5*0.01*destory(2).hermitian_conj());

	double dt = 0.1;

	std::cout << H << std::endl;
	std::cout << cps[0] << std::endl;

	mcSolve(H,psi0,cps,dt);


	std::cout << "####################  Simulation Completed  ####################\n";
	//Add timiing of simulation here
	
	return 0;
}

void mcSolve(Qmatrix& H,Qmatrix& inital,std::vector<Qmatrix>& Cps,double dt)
{
	Qmatrix Expt = PauliZ();
	//Define imaginary 1
	std::complex<double> _ONEI (0.0,1.0);

	//std::cout << H;
	//Define the evolved state 
	Qmatrix Evolved(inital);
	//Evolve the state
	for (int j = 0; j < 1000;j++)
	{
		if(j == 0)
		{
			Evolved = Evolved - (_ONEI * dt) * H * inital;
			for (int i = 0; i<Cps.size();i++)
			{
				Evolved = Evolved - ((_ONEI * dt * 0.5) * Cps[i].hermitian_conj()* Cps[i] * inital);
			}
		}
		else
		{
			Evolved = Evolved - (_ONEI * dt) * H * Evolved;
			for (int i = 0; i<Cps.size();i++)
			{
				Evolved = Evolved - ((_ONEI * dt * 0.5) * Cps[i].hermitian_conj()* Cps[i] * Evolved);
			}	
		}
		//Now to calculate the different collapse probabilities
		std::vector<double> cps_prob;

		for (int i = 0; i < Cps.size();i++)
		{
			Qmatrix dpm = (Evolved.hermitian_conj() * Cps[i].hermitian_conj() * Cps[i] * Evolved);
			//std::cout << dpm(0,0).real();
			cps_prob.push_back(dpm(0,0).real() * dt);
		}
		double deltaP = std::accumulate(cps_prob.begin(),cps_prob.end(),0.0);

		//Now produce the random number ( not using Rand as i needed a better psudeo random number henerator here)
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
	    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	    std::uniform_real_distribution<> dis(0.0, 1.0);
	    //std::cout << dis(gen) << ' ';
	    double r = dis(gen);
	    // Now need to test weather ot not a jump wil occur.
	    
	    //std::cout << deltaP << std::endl;
	    if (deltaP < r) // No Jump has Occured
	    {
	    	// The state is now normalized and the whole process will start again
	    	Evolved  = Evolved * (1/sqrt(1 - deltaP));
	    
	    }
	    else // A Jump has therfore occured
	    {
	    	//The A jump will now occur and the new jumped state will be produced and normalised.
	    	if (cps_prob.size() > 1)
	    	{
	    		//check that there is more than one collapse operator
	    	}
	    	else
	    	{
	    		// if there is only 1 then we dont need to work out which jump occured
	    		Evolved = Cps[0] *  Evolved * sqrt(dt / deltaP);
	    		std::cout << "welp";
	    	}
	    }

	    std::cout << expect(Evolved,Expt).imag() << std::endl;
	}
}