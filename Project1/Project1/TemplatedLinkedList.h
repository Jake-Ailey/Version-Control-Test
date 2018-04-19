#pragma once


template<typename T>
class List
{
public:

	List();
	~List();

	void pushBack(T data);			//Add data to end of list

	void popBack(T data);			//Remove data from end of list

	void pushFront(T data);			//Add data to start of list

	void popFront(T data);			//Remove data from start of list

private:

	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node* begin;
		Node* end;
	};
};