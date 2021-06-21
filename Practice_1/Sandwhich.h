// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/19/2021

#ifndef SANDWHICH_H
#define SANDWHICH_H

#include <iostream>

struct sandwhich
{
	// Index 0: Bread
	// Index 1: Meat
	// Index 2: Condiment
	// Index 3: Extra
	// Index 4: Name
	std::string components[5];
	float total = 0;
};

// Definition: The function addSandwhich adds a customized sandwhich to the user's order.
// Pre: sandwhichNumber is of type int which is passed in to create unique names for each burger.
// Post: A user-customized sandwhich of type sandwhich is returned and stored in their order.
sandwhich addSandwhich(int sandwhichNumber);

// Definition: The function editSandwhich allows the user to edit a desired sandwhich.
// Pre: A valid userSandwhich of type sandwhich, which is passed by reference.
// Post: The user's existing sandwhich is modified/editted.
void editSandwhich(sandwhich &userSandwhich);

// Definition: The function displaySandwhich displays the details of the desired sandwhich in the user's order.
// Pre: The userOrder that is an array of type sandwhich. maxOrder of type int determines how many sandwhiches can
// be in one order, it must be positive.
// Post: The details of a desired sandwhich are outputted in the console.
void displaySandwhich(const sandwhich userOrder[], const int maxOrder);

#endif