#include "headers/Qmatrix.h"
#include "headers/Constants.h"
#include <iostream>

//consturctors
Qmatrix::Qmatrix(unsigned int _rows, unsigned int _cols, const std::complex<double>& _inital)
{
	mat.resize(_rows);
	for (unsigned int i = 0; i<mat.size();i++)
	{
		mat[i].resize(_cols,_inital);
	}
	rows = _rows;
	cols = _cols;

}

Qmatrix::Qmatrix(const Qmatrix& rhs)
{
	mat = rhs.mat;
	rows = rhs.getRows();
	cols = rhs.getCols();
}
//Overloaded methods
Qmatrix Qmatrix::operator+(const Qmatrix& rhs)
{
	Qmatrix result(rows,cols,ZERO);
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			result(i,j) = this->mat[i][j] + rhs(i,j);
		}
	}
	return result;
}

Qmatrix Qmatrix::operator+=(const Qmatrix& rhs)
{
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			this->mat[i][j] += rhs(i,j);
		}
	}
	return *this;
}

Qmatrix Qmatrix::operator-(const Qmatrix& rhs)
{
	Qmatrix result(rows,cols,ZERO);
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			result(i,j) = this->mat[i][j] - rhs(i,j);
		}
	}
	return result;
}
Qmatrix Qmatrix::operator-=(const Qmatrix& rhs)
{
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			this->mat[i][j] -= rhs(i,j);
		}
	}
	return *this;
}

Qmatrix Qmatrix::operator*(const Qmatrix& rhs)
{
	Qmatrix result(rows,cols,ZERO);

	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			for(unsigned int k = 0; k<rows;k++)
			{
				result(i,j) += this->mat[i][k] * rhs(k,j);
			}
		}
	}
	
	return result;
}

Qmatrix Qmatrix::operator+(const std::complex<double>& rhs)
{
	Qmatrix result(rows,cols,ZERO);
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			result(i,j) = this->mat[i][j] + rhs;
		}
	}
	return result;
}
Qmatrix Qmatrix::operator-(const std::complex<double>& rhs)
{
	Qmatrix result(rows,cols,ZERO);
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			result(i,j) = this->mat[i][j] - rhs;
		}
	}
	return result;
}
Qmatrix Qmatrix::operator*(const std::complex<double>& rhs)
{
	Qmatrix result(rows,cols,ZERO);
	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			result(i,j) = this->mat[i][j] * rhs;
		}
	}
	return result;
}

//Matrix Vector Methods
std::vector<std::complex<double> > Qmatrix::operator*(const std::vector<std::complex<double> >& rhs)
{
	std::vector<std::complex<double> > result(rhs.size(),ZERO);

	for (unsigned int i = 0; i< rhs.size();i++)
	{
		for( unsigned int j =0;j<cols;j++)
		{
			result[i] += this->mat[i][j] * rhs[j];
		}
	}
	
	return result;
}
//Matrix Methods 
Qmatrix Qmatrix::transpose()
{

	Qmatrix result(rows,cols,ZERO);

	for(unsigned int i = 0;i<rows;i++)
	{
		for(unsigned int j = 0;j<cols;j++)
		{
			result(i,j) = this->mat[j][i];
		}
	}
	return result;
}
//Access methods
std::complex<double>& Qmatrix::operator()(const unsigned int& row,const unsigned int& col)
{
	return this->mat[row][col];
}
const std::complex<double>& Qmatrix::operator()(const unsigned int& row,const unsigned int& col) const
{
	return this->mat[row][col];
}
//get methods
unsigned int Qmatrix::getRows() const
{
	return this-> rows;
}
unsigned int Qmatrix::getCols() const
{
	return this-> cols;
}

int main()
{
	
}