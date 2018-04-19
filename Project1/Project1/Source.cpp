#include <iostream>
#include "TemplatedDynamicArray.h"
#include "TemplatedLinkedList.h"


int main()
{

//-----------------------------------------|
//			Dynamic Array Example		   |
//-----------------------------------------|
										   
	DynamicArray<int> Array(10);

	for (int i = 0; i <= 10 ; i++)
	{
		Array.AddToArrayEnd(i);
	}

	Array.PrintArray();
								
	Array.RemoveIndex(8, true);	

	Array.PrintArray();

	Array.ClearArray();

	Array.PrintArray();
//_________________________________________|

	
	system("pause");
 	return 0;
}