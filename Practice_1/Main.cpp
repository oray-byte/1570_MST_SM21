// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/19/2021


// NOTE TO PROFESSOR: Sorry, some of my functions take arrays as arguements. I did not see the prohibition of array passing 
// in the assignment description until after I built everything on it. To show that the arrays are not being manipulated, I 
// made each array arguement const. I am using arrays as an argument because majority of the information I am accessing is in
// arrays, mainly the array declared in the sandwhich struct. I apologize for the mistake.

#include <iostream>
#include "Sandwhich.h"
#include "Tools.h"

int main()
{
	const int MAX_ORDER = 3;
	int userInput = -1, numOfSandwhiches = 0;
	float userTotal = 0;
	sandwhich userOrder[MAX_ORDER];

	// Introduction
	std::cout << "Hello, thank you for using our sandwhich-building console application today." << std::endl;
	std::cout << "Each customer is only allowed three sandwhiches for each order." << std::endl;
	std::cout << "How may we assist you?" << std::endl;

	// 'Main' menu
	while (true)
	{
		// Options
		std::cout << std::endl << "[1] Build-a-sandwhich" <<
		std::endl << "[2] View a sandwhich" <<
		std::endl << "[3] View your total" <<
		std::endl << "[4] Edit a sandwhich" << 
		std::endl << "[5] Purchase" <<
		std::endl << "[6] Exit" << std::endl;
		std::cout << std::endl;

		// Input
		std::cout << "Your input: ";
		std::cin >> userInput;
		failedInput(userInput); // Used to handle information of the wrong type
		std::cout << std::endl;

		switch(userInput)
		{
			case 1:
				// Build sandwhich
				if (numOfSandwhiches >= MAX_ORDER)
				{
					// Ensures there is no more than MAX_ORDER of burgers
					std::cout << "You already of three sandwhiches in your order." << std::endl;
					std::cout << "That is the max amount of sandwhiches." << std::endl;
					break;
				}
				userOrder[numOfSandwhiches] = addSandwhich(numOfSandwhiches);
				numOfSandwhiches++; // User is only allowed three sandwhiches each order
				break;
			case 2:
				// View sandwhich
				std::cout << std::endl;
				if (numOfSandwhiches == 0)
				{
					std::cout << "You have no sandwhiches..." << std::endl;
					break;
				}
				displaySandwhich(userOrder, MAX_ORDER);
				break;
			case 3:
				// View total
				std::cout << "Your total: $" << figureTotal(userOrder, MAX_ORDER) << std::endl;
				break;
			case 4:
				// Edit sandwhich
				if (numOfSandwhiches == 0)
				{
					std::cout << "You have no sandwhiches..." << std::endl;
					break;
				}
				std::cout << "Which sandwhich do you want to edit:" << std::endl;
				
				// Displays user's burgers to choose from
				for (int i = 0; i < MAX_ORDER; i++)
				{
					if (userOrder[i].components[4] == "") // Checking if it the sandwhich has a name. All sandwhiches must have a name.
					{
						continue;
					}
					std::cout << "[" << i << "] " << userOrder[i].components[4] << std::endl; // Printing out burger names
				}
				
				// Input
				std::cout << std::endl;
				std::cout << "Your input: ";
				std::cin >> userInput;
				failedInput(userInput); // Used to handle information of the wrong type
				std::cout << std::endl;

				editSandwhich(userOrder[userInput]);
				break;
			case 5:
				// Purchasing
				if (numOfSandwhiches == 0)
				{
					std::cout << "You must add a sandwhich to purchase..." << std::endl;
					break;
				}
				std::cout << "Thank you for your purchase!" << std::endl;
				exit(0);
			case 6:
				// Exiting
				quit();
				break;
			default:
				std::cout << "Please enter a valid option..." << std::endl;
				break;
		}
	}
	
	return 0;
}