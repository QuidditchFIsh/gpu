#include "operators.h"
#include <iostream>
#include <stdio.h>
#include <numeric>
#include <random> 
#include <math.h>
#include <complex>


void mcSolve(Qmatrix& H,Qmatrix& psi0,std::vector<Qmatrix>& Cps,double dt);
