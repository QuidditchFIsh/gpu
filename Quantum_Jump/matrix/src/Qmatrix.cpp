#include "headers/Qmatrix.h"
#include "headers/Constants.h"

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

Qmatrix::Qmatrix(const std::vector<std::vector<std::complex<double> > >& _inital)
{
	mat = _inital;
	rows = _inital.size();
	cols = _inital[0].size();
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

	Qmatrix result(rows,rhs.getCols(),ZERO);

	for (unsigned int i = 0; i< rows;i++)
	{
		for( unsigned int j =0;j<rhs.getCols();j++)
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

Qmatrix Qmatrix::conjugate()
{
	Qmatrix result(rows,cols,ZERO);

	for(unsigned int i = 0;i<rows;i++)
	{
		for(unsigned int j = 0;j<cols;j++)
		{
			result(i,j) = std::conj(this->mat[i][j]);
		}
	}
	return result;
}
Qmatrix Qmatrix::hermitian_conj()
{
	Qmatrix result(rows,cols,ZERO);

	for(unsigned int i = 0;i<rows;i++)
	{
		for(unsigned int j = 0;j<cols;j++)
		{
			result(i,j) = std::conj(this->mat[j][i]);
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

//non-member function

Qmatrix bra2ket(const Qmatrix& rhs)
{
	unsigned int _rows = rhs.getRows();
	unsigned int _cols = rhs.getCols();
	Qmatrix result(_cols,_rows,ZERO);

	for(unsigned int i = 0;i<_cols;i++)
	{
		for(unsigned int j = 0; j<_rows;j++)
		{
			result(i,j) = rhs(j,i);
		}
	}
	return result;
}
Qmatrix ket2bra(const Qmatrix& rhs)
{
	unsigned int _rows = rhs.getRows();
	unsigned int _cols = rhs.getCols();
	Qmatrix result(_cols,_rows,ZERO);

	for(unsigned int i = 0;i<_cols;i++)
	{
		for(unsigned int j = 0; j<_rows;j++)
		{
			result(i,j) = rhs(j,i);
		}
	}
	return result;
}


Qmatrix tensor(const Qmatrix& _left, const Qmatrix& _right)
{
	unsigned int _rows = _left.getRows() * _right.getRows();
	unsigned int _cols = _left.getCols() * _right.getCols();
	Qmatrix result(_rows,_cols,ZERO);
	// i loops till rowas 
    for (int i = 0; i < _left.getRows(); i++) 
    { 
        // k loops till rowb 
        for (int k = 0; k < _left.getCols(); k++)
        { 
            // j loops till cola 
            for (int j = 0; j < _right.getRows(); j++) 
            { 
                // l loops till colb 
                for (int l = 0; l < _right.getCols(); l++)
                { 
                	result((_left.getRows() * i) + j,(_left.getCols() * k) + l) = _left(i,k) * _right(j,l);
                } 
            } 
        } 
    } 
    return result;
}