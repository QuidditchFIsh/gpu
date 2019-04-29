/*
Author: Aneirin John Baker
Date: 27/04/19
*/

#include "Qmatrix.h"

//vectors for the pauli matricies 

std::vector<std::complex<double> > sub_mat (2,ZERO);
std::vector<std::vector<std::complex<double> > > pauliX (2,sub_mat);
std::vector<std::vector<std::complex<double> > > pauliY (2,sub_mat);
std::vector<std::vector<std::complex<double> > > pauliZ (2,sub_mat);
//Will need to make this into a method to produce a general destruction operator
std::vector<std::vector<std::complex<double> > > destroy (2,sub_mat);


pauliX[0][1] = ONE;
pauliX[1][0] = ONE;

pauliY[0][1] = -1 * ONEI; 
pauliY[1][0] = ONEI;

pauliZ[0][0] = ONE; 
pauliZ[0][0] = -1 * ONE;

destroy[0][1] = ONE;

Qmatrix PauliX(pauliX);
Qmatrix PauliY(pauliY);
Qmatrix PauliZ(pauliZ);
Qmatrix Destroy(destroy);




