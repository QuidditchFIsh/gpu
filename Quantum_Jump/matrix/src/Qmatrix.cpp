#include "headers/Qmatrix.h"
#include <iostream>

//basic matrix consturctor
Qmatrix< complex<double> >::Qmatrix(unsigned int _rows, unsigned int _cols, const T& _inital)
{
	mat.resize(_rows);
	for (unsigned int i = 0; i < mat.size();i++)
	{
		mat[i].resize(_cols,_inital);
	}
	rows = _rows;
	cols = _cols;
}
//matrix copy constructor
Qmatrix<T>::Qmatrix(const Qmatrix<T>& rhs)
{
	mat = rhs.mat;
	rows = getRows();
	cols = getCols();
}

// matrix destructor
Qmatrix<T>::~Qmatrix() {}

//overloaded Operators

Qmatrix<T> Qmatrix<T>::operator+(const Qmatrix<T>& rhs)
{
	Qmatrix result(rows,cols,0.0);

	for (unsigned int i = 0; i<rows ; i++){
		for( unsigned int j = 0; j<cols;j++){
			result(i,j) = this->mat[i][j] + rhs(i,j);
		}
	}

	return result;
	
}
//access particular values in a matrix
T& Qmatrix<T>::operator()(const unsigned& row, const unsigned& col)
{
	return this->mat[row][col];
}

//Get number of rows in the matrix
unsigned int Qmatrix<T>::getRows() const
{
	return this->rows;
}

//Get number of colums in the matrix
unsigned int Qmatrix<T>::getCols() const
{
	return this->cols;
}

int main()
{
	
	return 0;
}