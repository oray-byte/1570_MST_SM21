// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/28/2021

#include <iostream>
#include <vector>
#include <string>
#include "mstring.h"

using std::vector;
using std::cout;
using std::endl;
using std::operator<<;


std::ostream& operator<< (std::ostream &out, vector<char> mstring)
{
	for (char letter : mstring)
	{
		out << letter;
	}
	return out;
};

int main()
{
	vector<char> mstring1;
	vector<char> mstring2;
	std::string tempString;

	cout << "Enter string: " << endl;
	std::getline(std::cin, tempString, '\n');

	for (char letter : tempString)
	{
		mstring1.push_back(letter);
	}

	cout << "Enter string: " << endl;
	std::getline(std::cin, tempString, '\n');

	for (char letter : tempString)
	{
		mstring2.push_back(letter);
	}
	cout << "mstring1: " << mstring1 << endl;
	cout << "mstring2: " << mstring2 << endl;
	strcat(mstring1, mstring2);
	cout << "mstring1: " << mstring1 << endl;
	cout << "mstring2: " << mstring2 << endl;

	return 0;
}