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
	Qmatrix H = omega * a_dag * a;
	//Define the inital State
	Qmatrix psi0 = basis(2,1);
	//Define a vector of collapse operators
	std::vector<Qmatrix> collapse;
	collapse.push_back(0.3 * a);
	//Define the time stpes 
	double delta_t = 0.1;

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

	//std::cout << H;
	//Define the evolved state 
	Qmatrix Evolved(inital);
	//Evolve the state
	for (int j = 0; j < 300;j++)
	{
		if(j == 0)
		{
			Evolved = Evolved - (_ONEI * dt) * H * inital;
			for (int i = 0; i<Cps.size();i++)
			{
				Evolved =Evolved - ((dt * 0.5) * Cps[i].hermitian_conj()* Cps[i] * inital);
			}
		}
		else
		{
			Evolved = Evolved - (_ONEI * dt) * H * Evolved;
			for (int i = 0; i<Cps.size();i++)
			{
				Evolved = Evolved - ((dt * 0.5) * Cps[i].hermitian_conj()* Cps[i] * Evolved);
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
	    	}
	    }

	    std::cout << Evolved;
	}
}