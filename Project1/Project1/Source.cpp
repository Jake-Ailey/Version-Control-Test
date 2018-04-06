#include <iostream>
#include "DynamicArray.h"


int main()
{
	DynamicArray<int> Array(10);

	for (int i = 0; i < 10; i++)
	{
		Array.AddToArrayEnd(i);
	}

	Array.ResizeArray('*', 2);

	system("pause");
	return 0;
}