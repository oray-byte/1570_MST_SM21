// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/19/2021

#include "Tools.h"

void quit()
{
	char confirmation;

	std::cout << "Are you sure you want to quit [Y/N]: ";

	std::cin >> confirmation;

	if (tolower(confirmation) == 'y')
	{
		exit(0);
	}
}

float figureTotal(const sandwhich userOrder[], const int maxOrder)
{
	float valueToReturn = 0;

	for (int i = 0; i < maxOrder; i++)
	{
		valueToReturn += userOrder[i].total;
	}

	return valueToReturn;
}

int findIndex(const std::string arr[], std::string desiredWord, const int maxOptions)
{
	for(int i = 0; i < maxOptions; i++)
	{
		if(arr[i] == desiredWord)
		{
			return i;
		}
	}

	return -1; // Means that the desired word was not found.
}

void failedInput(int &userInput)
{
	while(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Please enter a valid input: ";
		std::cin >> userInput;
		std::cout << std::endl;
	}
}