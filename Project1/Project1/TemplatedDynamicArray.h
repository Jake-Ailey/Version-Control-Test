#pragma once

template<typename T>
class DynamicArray
{
public:
	//--------------------------------------------------------------------------------------------------|
	//										CONSTRUCTOR													|
	//	When a new Dynamic Array is created, the user will need to input the array type and the initial |
	//	size of the array. Example: DynamicArray<int> myArray(10);										|
	//--------------------------------------------------------------------------------------------------|

	DynamicArray(int size)
	{
		data = new T[size];
		m_nArraySize = size;
		m_nUsedElements = 0;

	}
	
	~DynamicArray()
	{
		delete[] data;
	}

	//-----------------------------------------------------------------------------------------------|
	//										SEARCH ARRAY											 |
	// A function which searches the array for the specfied target of any given element, and returns |
	// the target and what index it was at in the array												 |
	//-----------------------------------------------------------------------------------------------|
	void SearchArray(T target)
	{
		for (int i = 0; i < m_nUsedElements; i++)
		{
			if (target == data[i])
			{
				std::cout << "The target " << target << " was found at index " << i << std::endl;
				return;																					//'return' will break the loop if the target is found
			}
		}

		std::cout << "The target could not be found within the array" << std::endl;
	}
	//_______________________________________________________________________________________________|

	//-----------------------------------------------------------|
	//						SORT ARRAY							 |
	// This function takes in a boolean value, where true sorts	 |
	// the array from highest to lowest, and false sorts in from |
	// lowest to highest.										 |
	//															 |
	//Sorts using a bubble sort									 |
	//-----------------------------------------------------------|
	void SortArrayHighest(bool result)
	{
		T temp;													//Create a temperary variable of type T
		if (result == true)					//Sort by highest
		{
			for (int i = 1; i < m_nUsedElements; i++)
			{
				for (int i = 1; i < m_nUsedElements; i++)
				{
					if (data[i - 1] < data[i])
					{
						temp = data[i - 1];							//Do a simple swamp, similar to what is done in a bubble sort
						data[i - 1] = data[i];
						data[i] = temp;
					}
				}
			}
		}
		
		else // false, or sort by lowest
		{
			for (int i = 1; i < m_nUsedElements; i++)			//Exact same as above, except sorts by lowest to highest
			{
				for (int i = 1; i < m_nUsedElements; i++)
				{
					if (data[i - 1] > data[i])
					{
						temp = data[i - 1];
						data[i - 1] = data[i];
						data[i] = temp;
					}
				}
			}
		}
	}

	//--------------------------------------------------------------------------------------------------|
	//										RESIZE ARRAY												|
	//	A function to resize the array by twice it's original size. Primarily called inside other		|
	//	functions.																						|
	//--------------------------------------------------------------------------------------------------|
															
	void ResizeArray()										
	{														
		T* newData = new T[(m_nArraySize * 2)];					//Creates a new array with twice the size as the original one
		memcpy(newData, data, m_nArraySize * sizeof(T));		//'memcpy' copies all data from the original array into the new one
		delete data;											//Deletes the old array
		data = newData;											//Copies the new, bigger array into the original data variable
		m_nArraySize *= 2;										//Doubles the ArraySize variable to match the new array size.
	}														
															
	//--------------------------------------------------------------------------------------------------|
	//										ADD TO ARRAY END											|
	//	Function to add elements to the end of the array and resize it if already full					|
	//--------------------------------------------------------------------------------------------------|
	void AddToArrayEnd(T newdata)
	{	
		if (m_nUsedElements == m_nArraySize)						
		{
			ResizeArray();
		}

		data[m_nUsedElements] = newdata;							
		m_nUsedElements += 1;										
	}
			
	//--------------------------------------------------------------------------------------------------|
	//										PRINT ARRAY													|
	//	Prints out a visual representation of what your array looks like. Primarily for testing purposes|
	//--------------------------------------------------------------------------------------------------|
	void PrintArray()										
															
	{
		std::cout << "{";
		for (int i = 1; i < m_nUsedElements + 1; i++)
		{
			std::cout << data[i - 1] << ", ";
		}
		std::cout << "\b\b}";
	}

	//--------------------------------------------------------------------------------------------------|
	//									PRINT ARRAY SINGLE												|
	//	Prints out a single piece of data from the array, at a point specified by the user				|
	//--------------------------------------------------------------------------------------------------|
	void PrintArraySingle(int index)							
	{															
		std::cout << data[index - 1] << std::endl;
	}
	
	//--------------------------------------------------------------------------------------------------|
	//									REMOVE FROM END													|
	//	A function to remove a number of entities from the end of the array, specified in the parameter |
	//	We don't need to worry about deleting what's inside the array, because it will be overwritten   |
	//	as the array gets filled up again																|
	//--------------------------------------------------------------------------------------------------|
	void RemoveFromEnd(int number)							
	{
		m_nUsedElements -= number;
	}

	//--------------------------------------------------------------------------------------------------|
	//									INSERT IN MIDDLE												|
	//	Function to insert the data at a point in the array specified by the user. Takes two parameters,|
	//	one being the actual data you want inserted into the array, and the index for which you want    |
	//	the data to be inserted.																		|
	//--------------------------------------------------------------------------------------------------|
	void InsertInMiddle(T newData, int index)				
	{
		if (m_nUsedElements == m_nArraySize)				
		{
			ResizeArray();
		}

		for (int i = m_nUsedElements; i > (index); i--)
		{
				data[i] = data[i - 1];
		}
		data[index] = newData;
		m_nUsedElements += 1;
	}

	//--------------------------------------------------------------------------------------------------|
	//									REMOVE INDEX													|
	//  Function to remove the piece of data at the specified index. Takes 2 values, one being the      |
	//	index you wish to remove data at, the other being a bool to decide whether or not you wish to	|
	//	keep the data in their current order															|
	//--------------------------------------------------------------------------------------------------|
	void RemoveIndex(int index, bool ordered)			
	{													
		if (ordered == true)								
		{
			for (int i = index; i < m_nUsedElements; i++)
			{
				data[i] = data[i + 1];
			}
		}
		else if (ordered == false)
		{
			data[index] = data[m_nUsedElements - 1];
		}
		m_nUsedElements -= 1;
	}

	//--------------------------------------------------------------------------------------------------|
	//									CLEAR ARRAY														|
	//	Acts as a "reset" for the array, clearing everything inside it.									|
	//--------------------------------------------------------------------------------------------------|
	void ClearArray()
	{
		for (int i = 0; i < m_nUsedElements; i++)
		{
			data[i] = NULL;
		}
	}

private:

	T * data;
	int m_nArraySize;
	int m_nUsedElements;

	//Challenging additions:
	//A function for concatenating two dynamic arrays together
	//A function for randomly shuffling the array
	//A function for rotating the array by a given amount
	// - Rotating an array means to shift elements in a direction
	//		- Any element that would fall off the end wrap back around to the start
	//		- eg: rotating the array {1,2,3,4,5,6,7,8,9} by 2 would give {8,9,1,2,3,4,5,6,7}
	//			  and rotating the array by -4 would give {5,6,7,8,9,1,2,3,4}
};

