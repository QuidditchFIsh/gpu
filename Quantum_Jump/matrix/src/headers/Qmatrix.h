#include <vector>
#include <complex>



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

	//overloaded operators
	Qmatrix operator+(const Qmatrix& rhs);
	Qmatrix operator+=(const Qmatrix& rhs);
	Qmatrix operator-(const Qmatrix& rhs);
	Qmatrix operator-=(const Qmatrix& rhs);
	Qmatrix operator*(const Qmatrix& rhs);
	

	Qmatrix operator+(const std::complex<double>& rhs);
	Qmatrix operator-(const std::complex<double>& rhs);
	Qmatrix operator*(const std::complex<double>& rhs);

	//Matrix Vector Multiplication
	std::vector<std::complex<double> > operator*(const std::vector<std::complex<double> >& rhs);
	//Matrix Methods 
	Qmatrix transpose();
	//Access the individual elements of the matrix
	std::complex<double>& operator()(const unsigned int& row,const unsigned int& col);
	const std::complex<double>& operator()(const unsigned int& row,const  unsigned int& col) const;
	//Get Method for rows and cols
	unsigned int getRows() const;
	unsigned int getCols() const;
};