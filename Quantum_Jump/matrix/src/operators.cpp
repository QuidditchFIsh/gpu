#include "headers/operators.h"
#include <math.h>




Qmatrix basis(int n, int lvl)
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat (1,_ZERO);
	std::vector<std::vector<std::complex<double> > > mat (n,sub_mat);

	mat[lvl][0] = _ONE;

	return Qmatrix(mat);

}

Qmatrix Id(int n)
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat(n,_ZERO);
	std::vector<std::vector<std::complex<double> > >mat (n,sub_mat);

	for(int i = 0;i<n;i++)
	{
		mat[i][i] = _ONE;
	}

	return Qmatrix(mat);
}

//Vectors for Pauli Matricies
Qmatrix PauliX()
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat (2,_ZERO);
	std::vector<std::vector<std::complex<double> > > pauliX (2,sub_mat);
	pauliX[0][1] = _ONE;
	pauliX[1][0] = _ONE;
	Qmatrix PauliX(pauliX);
	return PauliX;
}

Qmatrix PauliY()
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONEI (0.0,1.0);
	std::vector<std::complex<double> > sub_mat (2,_ZERO);
	std::vector<std::vector<std::complex<double> > > pauliY (2,sub_mat);
	pauliY[1][0] = _ONEI;
	_ONEI*=-1;
	pauliY[0][1] = _ONEI;
	Qmatrix PauliY(pauliY);
	return PauliY;
}

Qmatrix PauliZ()
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat (2,_ZERO);
	std::vector<std::vector<std::complex<double> > > pauliZ (2,sub_mat);
	pauliZ[1][0] = _ONE;
	_ONE*=-1;
	pauliZ[0][1] = _ONE;
	Qmatrix PauliZ(pauliZ);
	return PauliZ;
}

Qmatrix destory(unsigned int n)
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat (n,_ZERO);
	std::vector<std::vector<std::complex<double> > > destory (n,sub_mat);
	for (unsigned int i = 0; i < n - 1; i++)
	{
		_ONE = sqrt((double) i + 1);
		destory[i][i+1] = _ONE;
	}
	Qmatrix Destory(destory);
	return Destory;
}

Qmatrix sigmaP()
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat (2,_ZERO);
	std::vector<std::vector<std::complex<double> > > sPlus (2,sub_mat);
	sPlus[0][1] = _ONE;
	Qmatrix SPlus(sPlus);
	return SPlus;
}
Qmatrix sigmaM()
{
	std::complex<double> _ZERO (0.0,0.0);
	std::complex<double> _ONE (1.0,0.0);
	std::vector<std::complex<double> > sub_mat (2,_ZERO);
	std::vector<std::vector<std::complex<double> > > sMinus (2,sub_mat);
	sMinus[1][0] = _ONE;
	Qmatrix SMinus(sMinus);
	return SMinus;
}