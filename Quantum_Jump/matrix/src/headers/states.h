/*
Author: Aneirin John Baker
Date: 27/04/19
will need to be able to change bra to ket. CUrrently the basis comes as a bra.
*/

#include "Qmatrix.h"

Qmatrix basis(int n, int lvl)
{
	std::vector<std::complex<double> > sub_mat (1,ZERO);
	std::vector<std::vector<std::complex<double> > > mat (n,sub_mat);

	mat[n-1][0] = ONE;

	return Qmatrix(mat);

}
