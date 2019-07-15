#include "operators.h"
#include <iostream>
#include <stdio.h>
#include <numeric>
#include <random> 
#include <math.h>
#include <complex>
#include <fstream>
#include <iomanip>
#include <time.h>

//using forward declaration
struct H_part;

//typedef of the structure
typedef struct H_part H_part;

typedef std::complex<double> (*H_func_ptr_t)(std::complex<double> t);

struct H_part
{
	Qmatrix H0;
	H_func_ptr_t H_func_ptr;

	Qmatrix H_timeDep(std::complex<double> t) {return H0*H_func_ptr(t);}
};

void mcSolve(Qmatrix& H,Qmatrix& ,std::vector<Qmatrix>& Cps,double dt,double gamma,int,int);

void mcSolve(std::vector<H_part> H,Qmatrix& ,std::vector<Qmatrix>& Cps,double dt,double gamma,int,int);

void mcSolce_alt(Qmatrix& H,Qmatrix& ,std::vector<Qmatrix>& Cps,double dt,double gamma,int,int);