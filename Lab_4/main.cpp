// Author: @Owen Miller-Fast
// Date: 06/23/2021

#include <iostream>
#include "funcs.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char userInput[999];

	cout << "Give me a string please: " << endl;

	cin.getline(userInput, 998);

	yourUpper(userInput);

	cout << "[U] " << userInput << endl;

	yourLower(userInput);

	cout << "[L] " << userInput << endl;

 
	return 0;
}