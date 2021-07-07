// Author: @Owen Miller-Fast (oray-byte)
// Date: 07/02/2021

#include "fraction.h"

void Fraction::print() const
{
	cout << "(" << num << "/" << den << ")" << endl;
}

Fraction Fraction::recip()
{
	Fraction recipToReturn;

	if (!recipToReturn.setDen(num))
	{
		cout << "Numerator is zero, unable to return reciprical..." << endl << "Returning fraction (1/1)..." << endl;
		cout << endl;
		recipToReturn.setDen(1);
		recipToReturn.setNum(1);
	}
	else
	{
		recipToReturn.setNum(den);
	}

	return recipToReturn;

}

bool Fraction::setDen(int newDen)
{
	bool isNotZero = true;
	if (newDen == 0)
	{
		cout << "Denominator cannot be zero..." << endl << "Denominator has not been set..." << endl;
		cout << endl;
		isNotZero = false;
		return isNotZero;
	}

	den = newDen;
	return isNotZero;
}