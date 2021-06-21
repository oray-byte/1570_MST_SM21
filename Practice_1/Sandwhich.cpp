// Author: Owen Miller-Fast (oray-byte)
// Date: 06/19/2021

#include <string>
#include "Sandwhich.h"
#include "Tools.h"

const int MAX_OPTIONS = 4;
const std::string ingredients[][MAX_OPTIONS] = 
	{{"Wheat", "White"}, // Types of bread
	{"Bologna", "Ham", "Turkey"}, // Types of meat
	{"Mayo", "Mustard", "BBQ Sauce", "Ketchup"}, // Condiments
	{"Cheese", "Pickle", "Onion", "Lettuce"}}; // Extras
const float prices[][MAX_OPTIONS] = 
	{{1.00, 0.75}, // Prices for the type of bread
	{1.75, 2.25, 2.75}, // Prices for the types of meat
	{0.25, 0.10, 0.50, 0.10}, // Prices for the condiments
	{0.50, 0.25, 0.25, 0.15}}; // Prices for the extras
const std::string SANDWHICH_COMPONENTS[] = {"Bread", "Meat", "Condiment", "Extra"};

sandwhich addSandwhich(int sandwhichNumber)
{
	sandwhich s;
	int userInput;

	// Introduction
	std::cout << "Due to COVID-19, we are short on condiments and extras." << std::endl;
	std::cout << "Therefore, we are sorry to inform you that only one condiment and extra are allowed on each burger." << std::endl;
	std::cout << "Thank you for understanding in these trying times." << std::endl;
	std::cout << std::endl;

	// Goes through each 'component' of a sandwhich. Bread and meat are required. If the user doesn't want an extra or condiment, they 
	// can choose none, no money will be added to the sandwhich's value.
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Please choose one of the following:" << std::endl;
		std::cout << std::endl;
		// Prints options in each component catagory
		for (int j = 0; j < MAX_OPTIONS; j++)
		{
			if (ingredients[i][j] == "")
			{
				break;
			}
			std::cout << "[" << j << "] " << ingredients[i][j] << " ($" << prices[i][j] << ")" << std::endl;
		}
		// Only displays the none option when displaying condiment and extra options
		if (i > 1)
		{
			std::cout << "[5] None" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Your Input: ";
		std::cin >> userInput;
		failedInput(userInput); // Used to handle information of the wrong type
		std::cout << std::endl;

		// Always user to have no condiment or extra
		if ((userInput == 5) && (i > 1))
		{
			s.components[i] = "None";
			continue;
		}
		s.components[i] = ingredients[i][userInput];
		s.total += prices[i][userInput];
	}

	s.components[4] = "Burger " + std::to_string(sandwhichNumber + 1);


	return s;
}

void editSandwhich(sandwhich &userSandwhich)
{
	int userInput, desiredIndex;
	std::string desiredIngredient;
	std::cout << "What part of the sandwhich do you want to edit:" << std::endl;
	std::cout << std::endl;

	while(true)
	{
		for (int i = 0; i < MAX_OPTIONS; i++)
		{
			std::cout << "[" << i << "] " << SANDWHICH_COMPONENTS[i] << std::endl; 
		}
		std::cout << "[4] Done" << std::endl;
		std::cout << std::endl;
		std::cout << "Your input: ";
		std::cin >> userInput;
		failedInput(userInput); // Used to handle information of the wrong type
		std::cout << std::endl;

		if (userInput == 4)
		{
			break;
		}

		switch(userInput)
		{
			case 0:
				// Editing Bread
				std::cout << "Bread options: " << std::endl;
				
				// Displaying options
				for (int i = 0; i < MAX_OPTIONS; i++) 
				{
					if (ingredients[0][i] == "")
					{
						continue;
					}
					std::cout << "[" << i << "] " << ingredients[0][i] << " ($" << prices[0][i] << ")" << std::endl;
				}

				// Input
				std::cout << std::endl;
				std::cout << "Your input: ";
				std::cin >> userInput;
				failedInput(userInput); // Used to handle information of the wrong type
				std::cout << std::endl;
				
				// Index number of current bread component
				desiredIndex = findIndex(ingredients[0], userSandwhich.components[0], MAX_OPTIONS);
				
				// Adjusting prices and changing the sandwhich's extra component
				userSandwhich.total -= prices[0][desiredIndex];
				userSandwhich.total += prices[0][userInput];
				userSandwhich.components[0] = ingredients[0][userInput];
				break;
			case 1:
				// Editing Meat
				std::cout << "Meat options: " << std::endl;
				// Displaying options
				for (int i = 0; i < MAX_OPTIONS; i++) 
				{
					if (ingredients[1][i] == "")
					{
						continue;
					}
					std::cout << "[" << i << "] " << ingredients[1][i] << " ($" << prices[1][i] << ")" << std::endl;
				}

				// Input
				std::cout << std::endl;
				std::cout << "Your input: ";
				std::cin >> userInput;
				failedInput(userInput); // Used to handle information of the wrong type
				std::cout << std::endl;

				// Index number of current meat component
				desiredIndex = findIndex(ingredients[1], userSandwhich.components[1], MAX_OPTIONS);

				// Adjusting prices and changing the sandwhich's meat component
				userSandwhich.total -= prices[1][desiredIndex];
				userSandwhich.total += prices[1][userInput];
				userSandwhich.components[1] = ingredients[1][userInput];
				break;
			case 2:
				// Editing Condiments
				std::cout << "Condiments options: " << std::endl;
				// Displaying options
				for (int i = 0; i < MAX_OPTIONS; i++) 
				{
					if (ingredients[2][i] == "")
					{
						continue;
					}
					std::cout << "[" << i << "] " << ingredients[2][i] << " ($" << prices[2][i] << ")" << std::endl;
				}
				std::cout << "[4] None" << std::endl;

				// Input
				std::cout << std::endl;
				std::cout << "Your input: ";
				std::cin >> userInput;
				failedInput(userInput); // Used to handle information of the wrong type
				std::cout << std::endl;

				// Index number of current condiment component
				desiredIndex = findIndex(ingredients[2], userSandwhich.components[2], MAX_OPTIONS);

				// Handles input if the user wants no condiment
				if (userInput == 4)
				{
					userSandwhich.components[2] = "None";
					userSandwhich.total -= prices[2][desiredIndex];
					break;
				}

				// Adjusting prices and changing the sandwhich's condiment component
				userSandwhich.total -= prices[2][desiredIndex];
				userSandwhich.total += prices[2][userInput];
				userSandwhich.components[2] = ingredients[2][userInput];
				break;
			case 3:
				// Editing Extras
				std::cout << "Extra options: " << std::endl;
				// Displaying options
				for (int i = 0; i < MAX_OPTIONS; i++) 
				{
					if (ingredients[3][i] == "")
					{
						continue;
					}
					std::cout << "[" << i << "] " << ingredients[3][i] << " ($" << prices[3][i] << ")" << std::endl;
				}
				std::cout << "[4] None" << std::endl;

				// Input
				std::cout << std::endl;
				std::cout << "Your input: ";
				std::cin >> userInput;
				failedInput(userInput); // Used to handle information of the wrong type
				std::cout << std::endl;

				// Index number of current extra component
				desiredIndex = findIndex(ingredients[3], userSandwhich.components[3], MAX_OPTIONS);

				// Handles input if the user wants no condiment
				if (userInput == 4)
				{
					userSandwhich.components[3] = "None";
					userSandwhich.total -= prices[3][desiredIndex];
					break;
				}

				// Adjusting prices and changing the sandwhich's extra component
				userSandwhich.total -= prices[3][desiredIndex];
				userSandwhich.total += prices[3][userInput];
				userSandwhich.components[3] = ingredients[3][userInput];
				break;
			default:
				std::cout << "Please enter a valid option..." << std::endl;
				break;
		}

	}
}

void displaySandwhich(const sandwhich userOrder[], const int maxOrder)
{
	int userInput;

	std::cout << "Which sandwhich do you want to see details about:" << std::endl;
	std::cout << std::endl;
	// Displays all available sandwhiches
	for (int i = 0; i < maxOrder; i++)
	{
		if (userOrder[i].components[4] == "") // Checking if it the sandwhich has a name. All sandwhiches must have a name.
		{
			continue;
		}
		std::cout << "[" << i << "] " << userOrder[i].components[4] << std::endl;
	}

	// Input
	std::cout << std::endl;
	std::cout << "Your input: ";
	std::cin >> userInput;
	failedInput(userInput); // Used to handle information of the wrong type
	std::cout << std::endl;

	// Displays selected sandwhich's details
	for (int i = 0; i < 4; i++) 
	{
		if (userOrder[userInput].components[i] == "")
		{
			continue;
		}
		std::cout << SANDWHICH_COMPONENTS[i] << ": " << userOrder[userInput].components[i] << std::endl;
	}
	std::cout << "Price: $" << userOrder[userInput].total << std::endl;
	std::cout << std::endl;

}