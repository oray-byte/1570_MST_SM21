// Author: @Owen Miller-Fast (oray-byte)
// Date: 07/07/2021

#include "fraction.h"

Fraction::Fraction(const int newNum, const int newDen)
{
	num = newNum;
	den = newDen;
	(*this).simplify();
}

Fraction& Fraction::simplify()
{
	int divisor = gcd(num, den);

	num /= divisor;
	den /= divisor;

	return (*this);

}

Fraction& Fraction::operator= (const Fraction& rhs)
{
	num = rhs.num;
	den = rhs.den;

	return (*this);
}

Fraction& Fraction::operator*= (const Fraction& rhs)
{
	num *= rhs.num;
	den *= rhs.den;

	return (*this);
}

ostream& operator<< (ostream& out, const Fraction& fraction)
{
	out << "(" << fraction.num << "/" << fraction.den << ")";
	return out;
}

Fraction operator* (const Fraction& lhs, const Fraction& rhs)
{
	Fraction fractionToReturn;

	fractionToReturn.num = lhs.num * rhs.num;
	fractionToReturn.den = lhs.den * rhs.den;

	fractionToReturn.simplify();

	return fractionToReturn;
}

int gcd(const int x, const int y)
{
	if (x % y == 0)
	{
		return y;
	}

	return gcd(y, (x % y));
}


