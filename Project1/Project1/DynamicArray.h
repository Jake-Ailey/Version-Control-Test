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


	//Function to add to the array and resize it if it is already full
	void AddToArrayEnd(T newdata)
	{
		if (m_nUsedElements == m_nArraySize)			//Checks to see if the array is already full
		{
			T* newData = new T[m_nArraySize * 2];		//Creates a new array with twice the size as the original one
			memcpy(newData, data, m_nArraySize * 2);	//'memcpy' copies all data from the original array into the new one
			delete data;								//Deletes the old array
			data = newData;								//Copies the new, bigger array into the original data variable
			m_nArraySize *= 2;							//Doubles the ArraySize variable to match the new array size.

		}

		data[m_nUsedElements] = newdata;				//Adds the new data into the array, then increments the Used Elements variable
		m_nUsedElements += 1;							//Increments the UseElements variable so we know where we're up to		
	}

	void ResizeArray(char operation, int size)				//Function to resize the array
	{
		if (operation == '*')									//Switch statement to find which operator the user specified
		{											//Multiplies the array size by the given amount
			T* newData = new T[m_nArraySize * size];
			memcpy(newData, data, m_nArraySize * size);
			delete data;
			data = newData;
			m_nArraySize *= size;
		}

		else if (operation == '/')											//Divides the array size by the given amount
		{
			T* newData = new T[m_nArraySize / size];
			memcpy(newData, data, m_nArraySize / size);
			delete data;
			data = newData;
			m_nArraySize /= size;
		}
		else if (operation == '+')											//Adds onto the array size by the given amount
		{
			T* newData = new T[m_nArraySize + size];
			memcpy(newData, data, m_nArraySize + size);
			delete data;
			data = newData;
			m_nArraySize += size;
		}
		else if (operation == '-')											//Subtracts from the array size by the given amount
		{
			T* newData = new T[m_nArraySize - size];
			memcpy(newData, data, m_nArraySize - size);
			delete data;
			data = newData;
			m_nArraySize -= size;
		}
		else
		{
			assert("Incorrect or no operator in use");
		}
	}
		
	void PrintArray()											//Function to print out the array in it's entirety, primarily for testing purposes
	{
			std::cout << data[m_nUsedElements - 1] << std::endl;
	}
	

private:

	T * data;
	int m_nArraySize;
	int m_nUsedElements;


	//FUNCTION FOR REMOVING FROM THE END OF THE ARRAY

	//FUNCTIONS FOR ADDING 1 OR MORE ELEMENTS FROM THE MIDDLE OF THE ARRAY

	//FUNCTIONS FOR REMOVING FROM THE MIDDLE OF THE ARRAY, WITH BOTH ORDERED AND UNORDERED REMOVAL

	//A FUNCTION FOR CLEARING THE ARRAY
		

};

