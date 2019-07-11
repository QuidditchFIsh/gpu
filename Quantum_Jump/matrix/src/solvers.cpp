#include "headers/solvers.h"


void mcSolve(Qmatrix& H,Qmatrix& inital,std::vector<Qmatrix>& Cps,double dt,double gamma)
{

	std::ofstream file;
	file.open("Data.dat");
	Qmatrix Expt = PauliZ();
	file << std::setprecision(10) <<  0 << " " << expect(inital,Expt).real() <<"\n"; 
	//Define imaginary 1
	std::complex<double> _ONEI (0.0,1.0);

	Qmatrix norm(inital.hermitian_conj() * inital);

	//std::cout << H;
	//Define the evolved state 
	Qmatrix Evolved(inital);
	//Evolve the state
	for (int j = 0; j < 2000;j++)
	{
		//calculate the different collapse probabilities
		std::vector<double> cps_prob;
		for (int i = 0; i < Cps.size();i++)
		{
			Qmatrix dpm = (Evolved.hermitian_conj() * Cps[i] * Cps[i].hermitian_conj() * Evolved);

			cps_prob.push_back(dpm(0,0).real() * dt * gamma);

		}
		double deltaP = std::accumulate(cps_prob.begin(),cps_prob.end(),0.0);

		//Now calulate the probabilities a specific collapse operator will be used
		for(int i =0; i<Cps.size();i++)
		{
			cps_prob[i] = cps_prob[i]/deltaP;
		}

		if(j == 0)
		{
			Evolved = Evolved - ((_ONEI * dt) * H * inital);
			for (int i = 0; i<Cps.size();i++)
			{
				Evolved = Evolved - ((dt*0.5*gamma) * Cps[i]* Cps[i].hermitian_conj() * inital);
			}
		}
		else
		{
			Evolved = Evolved - ((_ONEI * dt) * H * Evolved);
			for (int i = 0; i<Cps.size();i++)
			{
				Evolved = Evolved - ((dt*0.5*gamma) * Cps[i]* Cps[i].hermitian_conj() * Evolved);
			}	
		}

		//Now produce the random number ( not using Rand as i needed a better psudeo random number henerator here)
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
	    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	    std::uniform_real_distribution<> dis(0.0, 1.0);
	    std::uniform_int_distribution<> dis_cps(0,Cps.size()-1);
	    //std::cout << dis(gen) << ' ';
	    double r = dis(gen);
	    // Now need to test weather ot not a jump wil occur.	
	    
	    if (deltaP < r) // No Jump has Occured
	    {
	    	// The state is now normalized and the whole process will start again
	    	norm = Evolved.hermitian_conj() * Evolved;
	    	Evolved  = Evolved * (1/sqrt(norm(0,0).real()));
	    	
	    }
	    else // A Jump has therfore occured
	    {
	    	//The A jump will now occur and the new jumped state will be produced and normalised.
	    	if (cps_prob.size() > 1)
	    	{
	    		//check that there is more than one collapse operator
	    		//Now pick a random number between 0 and NO collapse operators
	    		double r_cps = dis_cps(gen);
	    		Evolved = Cps[r_cps] *  Evolved * ((gamma * dt)/sqrt(deltaP));
	    	}
	    	else
	    	{
	    		// if there is only 1 then we dont need to work out which jump occured
	    		Evolved = Cps[0] *  Evolved * ((gamma * dt)/sqrt(deltaP));
	    	}
	    }
	    //std::cout << 1.0 - deltaP << "\n" << norm(0,0).real() << "\n------------\n";
	    file << std::setprecision(10) <<  j << " " <<expect(Evolved,Expt).real() <<"\n"; 
	}
}

void mcSolce_alt(Qmatrix& H,Qmatrix& psi0,std::vector<Qmatrix>& Cps,double dt,double gamma)
{
	//Solver with alternate algorithm applied
	
}