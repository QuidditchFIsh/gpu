/*
Author: Aneirin John Baker
Date: 27/04/19
*/
#include <iostream>
#include <complex>
#include "Qmatrix.h"

Qmatrix basis(int n, int lvl);

Qmatrix Id(int n);

Qmatrix PauliX();
Qmatrix PauliY();
Qmatrix PauliZ();
Qmatrix sigmaP();
Qmatrix sigmaM();

Qmatrix destory(unsigned int);