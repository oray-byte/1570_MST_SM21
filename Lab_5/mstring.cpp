// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/28/2021

#include "mstring.h"


void strcat(vector<char> &dest, vector<char> &src)
{
	for (char letter : src)
	{
		dest.push_back(letter);
	}
}