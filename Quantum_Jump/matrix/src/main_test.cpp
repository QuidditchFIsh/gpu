#include "headers/main_test.h"

#define PI 3.141592655
#define PI2 2*PI


int main()
{
	
	std::cout << "#####################  Begining Simulation  ####################\n";
	//Define all of the parameters to be used

	std::complex<double> ONEI (0.0,1.0);

	//Qmatrix H = 0.6*destory(2).hermitian_conj()*destory(2) + (destory(2) + destory(2).hermitian_conj());
	Qmatrix H =  0.6*(destory(2) + destory(2).hermitian_conj());
	//- 0.5*0.01*(destory(2)*destory(2).hermitian_conj())

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
	//Add timiing of simulation here
	
	return 0;
}

std::vector<double> mcSolve(Qmatrix& H,Qmatrix& inital,std::vector<Qmatrix>& Cps,double dt,double gamma,int runs,int steps)
{

	Qmatrix Expt = PauliZ();
	//Define imaginary 1
	std::complex<double> _ONEI (0.0,1.0);

	Qmatrix norm(inital.hermitian_conj() * inital);

	//create vector to store states
	std::vector<double> data;
	std::vector<double>res;

	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);

	double r  = 0;
	double deltaP = 0;

	for(int k = 0; k< runs;k++)
	{
		//Define the evolved state 
		Qmatrix current(inital); // |phi(t)>
		Qmatrix current_one(inital); //|phi^(1)(t + dt)>
		Qmatrix Evolved(inital); //|phi(t + dt)>

		for (int j = 0; j < steps;j++)
		{

			//Step one Evolve the state forward in time dt
			current_one = current - ((_ONEI * dt) * H * current);

			for (int i = 0; i<Cps.size();i++)
			{
				current_one = current_one - ((dt*0.5) * Cps[i].hermitian_conj() * Cps[i] * current);
			}	
			//calculate the different collapse probabilities
			std::vector<double> cps_prob;
			for (int i = 0; i < Cps.size();i++)
			{
				Qmatrix dpm = (current.hermitian_conj() * Cps[i].hermitian_conj() * Cps[i] * current);
				cps_prob.push_back(dpm(0,0).real() * dt);
			}

			deltaP = std::accumulate(cps_prob.begin(),cps_prob.end(),0.0);

			//Now produce the random number ( not using Rand as i needed a better psudeo random number henerator here)
		    r = dis(gen);
		    // Now need to test weather ot not a jump wil occur.	
		    norm = current_one.hermitian_conj() * current_one;
		    
		    if (deltaP < r) // No Jump has Occured
		    {
		    	// The state is now normalized and the whole process will start again
		    	
		    	Evolved  = current_one * (1/sqrt(norm(0,0).real()));
		    	
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
		    		Evolved = Cps[0] *  current * sqrt(dt/deltaP);	

		    	}
		    }
		    
		    data.push_back(expect(Evolved,Expt).real());
		    current = 1 * Evolved;
		}
	}

	return data;
}