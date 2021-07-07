// Author: @Owen Miller-Fast (oray-byte)
// Date: 07/02/2021

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using std::cout;
using std::endl;

class Fraction
{
	public:
	// Definition: The print function prints out the fraction in the following form: (num/den). Does not change anything.
	// Pre: Nothing.
	// Post: '(num/den)' streamed to output.
	void print () const;

	// Definition: The recip function returns the reciprical of the fraction. 
	// Pre: Numerator must be non-zero since it will return (1/1) if it is not
	// Post: The fraction's recip
	Fraction recip();

	// Accessor
	inline int getNum () const {return num;}

	// Accessor
	inline int getDen () const {return den;}

	// Mutator
	inline void setNum (int newNum) {num = newNum;};

	// Mutator
	bool setDen (int newDen);

	private:
	int num, den;

};

#endif