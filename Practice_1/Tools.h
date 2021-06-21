// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/19/2021


// This exists because I found these functions to be helpful and the code inside them appeared multiple times
// and I did not think they belonged in Sandwhich.h.

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include "Sandwhich.h"

// Definition: The quit function asks the user if he/she wants to really quit. If yes, it exits with code 0
// Pre: None
// Post: Either continues or exits with code 0 depending on user input
void quit();

// Definition: The figureTotal functions adds all the sandwhich's total and then returns that value.
// Pre: userOrder array of type sandwhich, it contains all the user-created sandwhiches.
// maxOrder of type constant int determines how many times the for loop loops. Must be positive and no higher
// than the length of the userOrder array.
// Post: The total amount of money that the user owes
float figureTotal(const sandwhich userOrder[], const int maxOrder);

// Definition: The findIndex function finds the index of a desired string in a string array.
// Pre: arr array of type constant string contains the available ingredient options
// desiredWord of type string is the ingredient being searched for. When found, i in the for loop is returned
// maxOptions of type int determines how many times the for loop will loop. Must be postive and no greater than the length of arr
// Post: Returns the index of desired word. It is of type int.
int findIndex(const std::string arr[], std::string desiredWord, const int maxOptions);

// Definition: The failedInput function handles discrepancies when the user enter the wrong type of data.
// Pre: userInput of type int that is passed in by reference. It is to change the current userInput of the 
// current operation into the right type.
// Post: userInput of the right type.
void failedInput(int &userInput);

#endif