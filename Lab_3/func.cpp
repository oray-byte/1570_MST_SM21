// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/21/2021

#include "func.h"

bool isPointLarger(point userPoint)
{
	static int largestPoint_x = 0, largestPoint_y = 0;

	if ((userPoint.x > largestPoint_x) && (userPoint.y > largestPoint_y))
	{
		largestPoint_x = userPoint.x;
		largestPoint_y = userPoint.y;
		return true;
	}

	return false;
}