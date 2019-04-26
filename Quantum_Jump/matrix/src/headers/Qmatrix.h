#include <vector>
#include <complex>

class Qmatrix 
{
private:
	std::vector<std::vector< complex<double> > > mat;
	unsigned rows;//when no type declaration is used herer int is assumed
	unsigned cols;
public:
	Qmatrix(unsigned int _rows, unsigned int _cols,const complex<double>& _inital);
	Qmatrix(const Qmatrix< complex<double> >& rhs);
	virtual ~Qmatrix();

	//Overload the +,- and * operators to work on matricies
	Qmatrix< complex<double> > operator+(const Qmatrix< complex<double> >& rhs);

	//Access individual elements
	complex<double>& operator()(const unsigned& row, const unsigned& col);

	//Get Methods
	unsigned int getRows() const;
	unsigned int getCols() const;
};