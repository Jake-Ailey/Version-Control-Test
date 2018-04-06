#include <iostream>
#include "DynamicArray.h"


int main()
{
	DynamicArray<int> Array(10);

	for (int i = 0; i <= 15 ; i++)
	{
		Array.AddToArrayEnd(i);
	}

	Array.PrintArray();

	Array.InsertInMiddle(43, 6);
	Array.InsertInMiddle(73, 2);

	Array.PrintArray();

	
	system("pause");
 	return 0;
}