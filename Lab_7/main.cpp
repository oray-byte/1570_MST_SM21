// Author: @Owen Miller-Fast (oray-byte)
// Date: 07/07/2021

#include <iostream>
#include <vector>
#include "fraction.h"

using namespace std;

int main ()
{
	Fraction frac1(81, 27);
	Fraction frac2;
	Fraction frac3;

	frac2 = frac1 * 3;

	cout << "frac1: " << frac1 << endl;
	cout << "frac2: " << frac2 << endl;
	cout << "frac3: " << frac3 << endl;
	return 0;
}