// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/16/2021

#include <iostream>
#include <typeinfo>

// Description: The getYearsOld function asks the user for their age and returns a valid age.
// Pre: None.
// Post: The user age of type int is returned. It must be positive and between 18 and 100.
int getYearsOld();

// Description: The getYearBorn function calculates an estimate for the year the user was born
// by subtracting user age from the current year.
// Pre: Both parameters, currentYear and userAge, must be positive values. userAge must be
// between 18 and 100.
// Post: Returns an estimate on what year the user was born. It is of type int. 
int getYearBorn(int currentYear, int userAge);

int main() 
{
	const int CURRENT_YEAR = 2021;
	int yearBorn = getYearBorn(CURRENT_YEAR, getYearsOld());
	
	std::cout << "You might have been born in " << yearBorn << "!" << std::endl;
	return 0;
}

int getYearsOld()
{
	int userAge = 0;

	while ((userAge < 18) || (userAge > 99)) 
	{
		// NOTE: Any value larger than 2147483647 will result in the loop running infinetly
		// I think this is due to the userAge becoming a long after the user enters a number
		// larger than 2147483647. A possible fix could be to ensure userAge is of type int.
		std::cout <<  "Please enter your age: ";
		std::cin >> userAge;
	}

	return userAge;
}

int getYearBorn(int currentYear, int userAge)
{
	return currentYear - userAge;
}