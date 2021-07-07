// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/28/2021

#ifndef MSTRING_H
#define MSTRING_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;


// Definition: The strcat takes the source mstring data and copies over to the back of dest
// Pre: two m-strings are passed as parameters
// Post: characters of source get appended to dest, source remains unchanged
void strcat(vector<char> &dest, vector<char> &src);

#endif