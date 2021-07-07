// Author: @Owen Miller-Fast (oray-byte)
// Date: 07/07/2021

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <vector>

using namespace std;

class Fraction
{
	public:
	// Constructor
	Fraction(const int newNum = 1, const int newDen = 1);

	// Accessors
	int getNum() const {return num;} 
	int getDen() const {return den;}

	// Mutators
	void setNum(int newNum) {num = newNum;}
	bool setDen(int newDen);

	// Operator Overloading
	Fraction& operator= (const Fraction& rhs);
	Fraction& operator*= (const Fraction& rhs);
	friend ostream& operator<< (ostream& out, const Fraction& fraction);
	friend Fraction operator* (const Fraction& lhs, const Fraction& rhs);

	private:
	Fraction& simplify();
	int num, den;
};

int gcd(const int x, const int y);




#endif