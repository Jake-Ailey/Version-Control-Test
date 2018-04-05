#pragma once

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
	}	//destructor


	void AddToArrayEnd(T newdata)
	{
		if (m_nUsedElements == m_nArraySize)
		{

		}
	}

	void ResizeArray
	{

	}

private:

	T * data;
	int m_nArraySize;
	int m_nUsedElements;

	// I believe that all functions for this class now need to be in the Source.ccp file

	//RESIZE FUNCTION

	//COPY CONSTRUCTOR:
	
	//FUNCTIONS FOR ADDING AND REMOVING FROM THE END OF THE ARRAY

	//FUNCTIONS FOR ADDING 1 OR MORE ELEMENTS FROM THE MIDDLE OF THE ARRAY

	//FUNCTIONS FOR REMOVING FROM THE MIDDLE OF THE ARRAY, WITH BOTH ORDERED AND UNORDERED REMOVAL

	//FUNCTIONS FOR CHANGING HOW MUCH SPACE IS ALLOCATED FOR THE ARRAY

	//A FUNCTION FOR CLEARING THE ARRAY


	

};

