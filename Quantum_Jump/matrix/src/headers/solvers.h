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

typedef double (*H_func_ptr_t)(double* t);

struct H_part
{
	double H0;
	H_func_ptr_t H_func_ptr
};

void mcSolve(Qmatrix& H,Qmatrix& psi0,std::vector<Qmatrix>& Cps,double dt,double gamma);

void mcSolce_alt(Qmatrix& H,Qmatrix& psi0,std::vector<Qmatrix>& Cps,double dt,double gamma);