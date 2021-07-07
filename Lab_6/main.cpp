// Author: @Owen Miller-Fast (oray-byte)
// Date: 07/02/2021

#include <iostream>
#include "fraction.h"

using std::cout;
using std::endl;

int main () 
{
	Fraction myFrac;
	Fraction myFrac2;
	Fraction myFrac3;
	Fraction myFrac4;

	myFrac.setNum(0);
	myFrac.setDen(2);

	myFrac2 = myFrac.recip();

	cout << "myFrac: ";
	myFrac.print();
	cout << endl;
	cout << "myFrac2: ";
	myFrac2.print();
	cout << endl;

	myFrac3.setNum(39845);
	myFrac3.setDen(0);

	cout << "myFrac3: ";
	myFrac3.print();

	cout << "myFrac3 denominator should be a random number since it was never set..." << endl << "Could even be 0, which is bad..." << endl;
	cout << endl;

	myFrac3.setDen(293219);

	cout << "myFrac3: ";
	myFrac3.print();
	cout << endl;

	myFrac4 = myFrac3.recip();

	cout << "myFrac4: ";
	myFrac4.print();

	return 0;
}