// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/21/2021

#include <iostream>
#include "func.h"

using std::cout;
using std::endl;
using std::string;

// swap function could swap all primative types and strings. I was surprised when it could swap two of my point structs.
// The swap function (obviously) could not swap two arrays of any type. 

int main()
{
	point point1, point2, point3;
	int number1 = 5, number2 = 7;
	string word1 = "Hello", word2 = "Bye";

	int int_arr1[2] = {2,3}, int_arr2[2] = {4, 5};

	point2.x = 5;
	point2.y = 5;

	point3.x = 4;
	point3.y = 7;

	(isPointLarger(point1) ? cout << "True" << endl : cout << "False" << endl);
	(isPointLarger(point2) ? cout << "True" << endl : cout << "False" << endl);
	(isPointLarger(point3) ? cout << "True" << endl : cout << "False" << endl);

	cout << "Number 1 [Before Swap]: " << number1 << endl;
	cout << "Number 2 [Before Swap]: " << number2 << endl;

	swap(number1, number2);

	cout << "Number 1 [After Swap]: " << number1 << endl;
	cout << "Number 2 [After Swap]: " << number2 << endl;

	cout << endl;

	cout << "Word 1 [Before Swap]: " << word1 << endl;
	cout << "Word 2 [Before Swap]: " << word2 << endl;	

	swap(word1, word2);

	cout << "Word 1 [After Swap]: " << word1 << endl;
	cout << "Word 2 [After Swap]: " << word2 << endl;

	cout << endl;

	cout << "Point 1's x [Before Swap]: " << point1.x << endl;
	cout << "Point 1's y [Before Swap]: " << point1.y << endl;
	cout << "Point 2's x [Before Swap]: " << point2.x << endl;
	cout << "Point 2's y [Before Swap]: " << point2.y << endl;

	swap(point1, point2);

	cout << "Point 1's x [After Swap]: " << point1.x << endl;
	cout << "Point 1's y [After Swap]: " << point1.y << endl;
	cout << "Point 2's x [After Swap]: " << point2.x << endl;
	cout << "Point 2's y [After Swap]: " << point2.y << endl;	

	cout << endl;

	return 0;
}