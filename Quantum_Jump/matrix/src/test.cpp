#include <iostream>
#include <stdio.h>
#include <random> 
#include <math.h>


//using forward declaration
struct H_part;

//typedef of the structure
typedef struct H_part H_part;

//defines the name of the general pointer to a function i will use in the struct
typedef double (*H_func_ptr_t)(double t);

struct H_part
{
	double H0;
	H_func_ptr_t H_func_ptr;
};

double two_times(double t)
{
	return 2*t;
}

double three_times(double t)
{
	return 3*t;
}

int main()
{
	H_part H1 = {.H0 = 1, .H_func_ptr = &two_times};
	H_part H2 = {.H0 = 1, .H_func_ptr = &three_times};
	std::cout<< H2.H_func_ptr(5.0) << std::endl;

	return 0;
}