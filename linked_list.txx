#include "linked_list.h"

#include <utility>
#include <stdexcept>

/*
*  Purpose for program
*  This is a 0 indexed doubly linked list.
*
*
*  Programmer: Onat Calik
*  Date: November 04, 2016
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while (head != nullptr)
	{
		Node<T> * temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x) : head(nullptr), size(0)
{
	Node<T> * x_curr = x.head;
	Node<T> * this_prev = nullptr;

	while (x_curr != nullptr)
	{
		Node<T> * this_curr = new Node<T>(x_curr->data);
		this_curr->prev = this_prev;
		if (this_prev != nullptr) this_prev->next = this_curr;
		else head = this_curr;
		this_prev = this_curr;
		x_curr = x_curr->next;
		size++;
	}
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
	std::swap(x.head, y.head);
	std::swap(x.size, y.size);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
	swap(*this, x);
	return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return ( head==nullptr );
}

template <typename T>
std::size_t LinkedList<T>::getLength()
{
	
	return size;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item)
{
	if ((position < 0) || (position > size)) throw std::range_error("Invalid position in insert");

	
	
	Node<T> * temp1 = new Node<T>(item);
	
	if (position == 0)
	{
		temp1->next = head;
		head = temp1;

	}
	else
	{
		Node<T> * temp2 = head;
		for (int i = 0; i < position - 1; i++)
		{
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}

	size++;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
	if ((position < 0) || (position >= size)) throw std::range_error("Invalid position in insert");

	Node<T> * temp1 = head;

	if (position == 0)
	{
		head = temp1->next;
		delete temp1;
	}

	else
	{
		for (int i = 0; i < position - 1; i++)
		{
			temp1 = temp1->next;
		}

		Node<T>* temp2 = temp1->next;

		temp1->next = temp2->next;
		delete temp2;
	}

	size--;

}

template <typename T>
void LinkedList<T>::clear()
{
	delete head;
	head = new Node<T>();
	size = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position)
{
	if ((position < 0) || (position >= size)) throw std::range_error("Invalid position in insert");
	
	
	Node<T> * temp = head;

	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}

	return temp->data;
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
	if ((position < 0) || (position >= size)) throw std::range_error("Invalid position in insert");

	Node<T> * temp = head;

	for (int i = 0; i < position; i++)
	{
		temp = temp->next;
	}

	temp->data = newValue;
}
