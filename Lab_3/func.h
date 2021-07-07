// Author: @Owen Miller-Fast (oray-byte)
// Date: 06/21/2021

struct point 
{
	int x = 0, y = 0;
};

// Definition: The swap template swaps two variables of the same type.
// Pre: t1 and t2 of the same type. Must be the same type. 
// Post: t1 and t2 values are swapped.
template <typename T>
void swap(T &t1, T &t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

// Definition: The isPointLarger function returns true if the point passed into the funtion is the largest
// 'seen' by the function. This is done by comparing the point's values to static variables in the function.
// Pre: userPoint of type point. The user point contains two ints, x and y. 
// Post: Returns true if the inputted point is the largest 'seen' by the function, returns false otherwise.
bool isPointLarger(point userPoint);