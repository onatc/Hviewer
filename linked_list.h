#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "abstract_list.h"

template <typename T> class LinkedList : public AbstractList<T> {
public:

	LinkedList(); //constructor

	LinkedList(const LinkedList &x); //copy constructor

	~LinkedList(); //destructor

	LinkedList &operator=(LinkedList x); //copy-assignment operator

	bool isEmpty(); //checks if the list is empty

	std::size_t getLength(); //returns the size of the list

	void insert(std::size_t position, const T &item); // insert an item at the list

	void remove(std::size_t position);  //remove an item from the list

	void clear(); //clear the whole list

	T getEntry(std::size_t position); //get the item at a specified position

	void setEntry(std::size_t position, const T &newValue); //set the item to a specified value

	void swap(LinkedList &x, LinkedList &y); //swap two lists

private:
	
	template<typename U>
	struct Node {    
		U data;
		Node<U> * next;
		Node<U> * prev;

		Node() : next(nullptr), prev(nullptr) {};
		Node(const U& d) : data(d), next(nullptr), prev(nullptr) {};
	};

	Node<T> * head;
	std::size_t size;

};

#include "linked_list.txx"

#endif // _LINKED_LIST_H_

