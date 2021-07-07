// Author: @Owen Miller-Fast
// Date: 06/23/2021

#include "funcs.h"

void yourUpper(char arr[])
{
	int i = 0;
	while(arr[i] != '\0')
	{
		arr[i] = toupper(arr[i]);
		i++;
	}
}

void yourLower(char arr[])
{
	int i = 0;
	while (arr[i] != '\0')
	{
		arr[i] = tolower(arr[i]);
		i++;
	}
}