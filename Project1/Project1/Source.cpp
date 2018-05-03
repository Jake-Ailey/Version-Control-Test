#include <iostream>
#include "TemplatedDynamicArray.h"
#include "TemplatedLinkedList.h"


int main()
{

//--------------------------------------------------------------------------|
//							Dynamic Array Example					        |
//--------------------------------------------------------------------------|
										   
	DynamicArray<int> Array(10);

	for (int i = 0; i <= 10 ; i++)
	{
		Array.AddToArrayEnd(i);
	}

	Array.PrintArray();
	std::cout << "   Adding 1 through 10 into the array" << std::endl;
								
	Array.RemoveIndex(8, true);	

	Array.PrintArray();
	std::cout << "      Removing '8' from the array" << std::endl;

	Array.SortArrayHighest(true);
	Array.PrintArray();
	std::cout << "      Sorted from highest to lowest" << std::endl;	

	Array.SortArrayHighest(false);
	Array.PrintArray();
	std::cout << "      Sorted from lowest to highest" << std::endl << std::endl;

	Array.SearchArray(3);
	std::cout << "   (Searching the array for the target of '3')" << std::endl << std::endl;

	Array.SearchArray(8);
	std::cout << "   (Searching the array for the target of '8')" << std::endl << std::endl;

	Array.ClearArray();

	Array.PrintArray();
	std::cout << "       Clearing everything from the array" << std::endl;
//__________________________________________________________________________|

	
	system("pause");
 	return 0;
}