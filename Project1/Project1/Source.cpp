#include <iostream>
#include "DynamicArray.h"


int main()
{
	DynamicArray<int> Array(11);

	for (int i = 0; i < 10; i++)
	{
		Array.AddToArrayEnd(i);
		Array.PrintArray();
	}


	system("pause");
	return 0;
}