#pragma once
#include <assert.h>

template<typename T>
class DynamicArray
{
public:
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

	void ResizeArray()
	{
		T* newData = new T[(m_nArraySize * 2)];					//Creates a new array with twice the size as the original one
		memcpy(newData, data, m_nArraySize * sizeof(T));		//'memcpy' copies all data from the original array into the new one
		delete data;											//Deletes the old array
		data = newData;											//Copies the new, bigger array into the original data variable
		m_nArraySize *= 2;										//Doubles the ArraySize variable to match the new array size.
	}

	//Function to add to the array and resize it if it is already full
	void AddToArrayEnd(T newdata)
	{
		if (m_nUsedElements == m_nArraySize)						//Checks to see if the array is already full
		{
			ResizeArray();
		}

		data[m_nUsedElements] = newdata;							//Adds the new data into the array, then increments the Used Elements variable
		m_nUsedElements += 1;										//Increments the UseElements variable so we know where we're up to		
	}

	//void ResizeArrayManual(char operation, int size)				//Function to resize the array
	//{
	//	if (operation == '*')									//Switch statement to find which operator the user specified
	//	{														//Multiplies the array size by the given amount
	//		T* newData = new T[m_nArraySize * size];
	//		memcpy(newData, data, m_nArraySize * sizeof(T));
	//		delete data;
	//		data = newData;
	//		m_nArraySize *= size;
	//	}

	//	else if (operation == '/')											//Divides the array size by the given amount
	//	{
	//		T* newData = new T[m_nArraySize / size];
	//		memcpy(newData, data, m_nArraySize / sizeof(T));
	//		delete data;
	//		data = newData;
	//		m_nArraySize /= size;
	//	}
	//	else if (operation == '+')											//Adds onto the array size by the given amount
	//	{
	//		T* newData = new T[m_nArraySize + size];
	//		memcpy(newData, data, m_nArraySize + sizeof(T));
	//		delete data;
	//		data = newData;
	//		m_nArraySize += size;
	//	}
	//	else if (operation == '-')											//Subtracts from the array size by the given amount
	//	{
	//		T* newData = new T[m_nArraySize - size];
	//		memcpy(newData, data, m_nArraySize - sizeof(T));
	//		delete data;
	//		data = newData;
	//		m_nArraySize -= size;
	//	}
	//	else
	//	{
	//		assert("Incorrect or no operator in use");
	//	}
	//}
		
	void PrintArray()											//Function to print out a visual representation of the array in it's entirety
																//Purely for testing purposes
	{
		std::cout << "{";
		for (int i = 1; i < m_nUsedElements + 1; i++)
		{
			std::cout << data[i - 1] << ", ";
		}
		std::cout << "\b\b}" << std::endl;
	}

	void PrintArraySingle(int index)							//Function to print out a single piece of data, indexed by the user
	{															//May not ever be needed, but can't hurt to include anyway
		std::cout << data[index - 1] << std::endl;
	}
	
	void RemoveFromEnd(int number)								//Number of entities to remove from the end of the array
	{
		for (int i = 0; i < number; i++)
		{
			m_nUsedElements -= 1;								//Lowers UsedElements, so that the next time it is written to, it will simply be
		}														//overwrittten with the new data
	}

	void InsertInMiddle(T newData, int index)					//Inserts the data at a specified point, adjusts array to make room
	{
		if (m_nUsedElements == m_nArraySize)					//Checks to see if the array is already full
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

private:

	T * data;
	int m_nArraySize;
	int m_nUsedElements;



	//FUNCTIONS FOR ADDING 1 OR MORE ELEMENTS FROM THE MIDDLE OF THE ARRAY

	//FUNCTIONS FOR REMOVING FROM THE MIDDLE OF THE ARRAY, WITH BOTH ORDERED AND UNORDERED REMOVAL

	//A FUNCTION FOR CLEARING THE ARRAY
		

};

