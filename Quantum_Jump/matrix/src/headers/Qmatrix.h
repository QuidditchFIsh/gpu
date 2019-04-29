#include <vector>
#include "Constants.h"

class Qmatrix 
{
private:
	std::vector<std::vector<std::complex<double> > > mat;
	unsigned int rows;//when no type declaration is used herer int is assumed
	unsigned int cols;
public:
	//Constructors
	Qmatrix(unsigned int _rows, unsigned int _cols, const std::complex<double>& _inital);
	Qmatrix(const Qmatrix& rhs);
	Qmatrix(const std::vector<std::vector<std::complex<double> > >& _inital);

	//overloaded operators
	Qmatrix operator+(const Qmatrix& rhs);
	Qmatrix operator+=(const Qmatrix& rhs);
	Qmatrix operator-(const Qmatrix& rhs);
	Qmatrix operator-=(const Qmatrix& rhs);
	Qmatrix operator*(const Qmatrix& rhs);
	

	Qmatrix operator+(const std::complex<double>& rhs);
	Qmatrix operator-(const std::complex<double>& rhs);
	Qmatrix operator*(const std::complex<double>& rhs);

	friend std::ostream& operator<< (std::ostream &out, const Qmatrix &rhs)// what is a friend function???
	{
		//out << "{";
		for (unsigned int i = 0; i<rhs.getRows();i++)
		{
			for(unsigned int j = 0;j<rhs.getCols();j++)
			{
				out << rhs.mat[i][j] << " ";
			}
			out << "\n";
		}
    	return out;
	}

	//Matrix Vector Multiplication
	std::vector<std::complex<double> > operator*(const std::vector<std::complex<double> >& rhs);

	//Matrix Methods 
	Qmatrix transpose();
	Qmatrix conjugate();
	Qmatrix hermitian_conj();//Defined as the transpose of the conjugate

	//Tensor method veryuseful in quantum sims
	Qmatrix tensor(const Qmatrix& _left, const Qmatrix& _right);

	//Access the individual elements of the matrix
	std::complex<double>& operator()(const unsigned int& row,const unsigned int& col);
	const std::complex<double>& operator()(const unsigned int& row,const  unsigned int& col) const;
	//Get Method for rows and cols
	unsigned int getRows() const;
	unsigned int getCols() const;
};