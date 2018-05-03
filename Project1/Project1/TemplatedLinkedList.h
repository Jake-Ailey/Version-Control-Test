//#pragma once
//
//
//template<typename T>		// I believe you may have to consult some youtube tutorials to fully grasp this
//class List
//{
//public:
//
//	List();
//	~List();
//
//
//	void pushBack(T data);			//Add data to end of list
//
//	void popBack(T data);			//Remove data from end of list
//
//	void pushFront(T data);			//Add data to start of list
//
//
//	void popFront(T data);			//Remove data from start of list
//		//psuedocode example
//	//set iterator to first node (list.first)
//	//if list.first.next is not null (ie. if the next node in the list isn't the end of the list), then
//	//	set list.first.next.previous to list.first.previous (ie. set the node after the firsts' previous pointer to equal the beggining of the list)
//	//set list.first to list.first.next (ie. Chane the 'first' pointer from the node being removed to the new first pointer)
//protected:
//
//	struct Node
//	{
//		T data;
//		Node* next;
//		Node* prev;
//		
//	};
//
//	Node* begin;
//	begin = 0;
//	Node* end = NULL;
//
//	bool isEmpty() { return (begin->next == NULL) };
//	int listSize;
//};