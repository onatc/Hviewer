#include "dynamic_array_list.h"

#include <stdexcept>
#include <algorithm>

/*
*  Purpose for program
*  This is 0 indexed dynamic array list.
*
*
*  Programmer: Onat Calik
*  Date: November 04, 2016
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

template <typename T>
DynamicArrayList<T>::DynamicArrayList() : data(nullptr), capacity(0), size(0) {}

template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T> &x) {

	capacity = x.capacity;
	size = x.size;
	data = capacity ? new T[capacity] : nullptr;
	std::copy(x.data, x.data + x.size, data);
}

template <typename T> DynamicArrayList<T>::~DynamicArrayList() {
	delete[] data;
}

template <typename T>
DynamicArrayList<T> &DynamicArrayList<T> ::operator=(DynamicArrayList<T> x)
{

	swap(*this, x);
	return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T> &x, DynamicArrayList<T> &y) {
	std::swap(x.capacity, y.capacity);
	std::swap(x.size, y.size);
	std::swap(x.data, y.data);
}

template <typename T> 
bool DynamicArrayList<T>::isEmpty() 
{
	return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
	return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T &item)
{

	if (!(position >= 0 && position <= size))
	{
		throw std::range_error("Position out of range in insert");
	}

	if (size >= capacity) 
	{
		if (capacity == 0)
		{
			capacity = 2;
		}
		if ((capacity & (capacity - 1)) == 0)
		{
			capacity = capacity * 2;
		}
		while ((capacity & (capacity - 1)) != 0)
		{
			capacity++;
		}
		T * temp = new T[capacity];
		std::copy(data, data + size, temp);
		delete[] data;
		data = temp;
	}
	
	long count = size;
	while (count > position)
	{
		data[count] = data[count - 1];
		count--;
	}

	data[position] = item;
	size++;
}


template <typename T> 
void DynamicArrayList<T>::remove(std::size_t position) {
	

	if (!(position >= 0 && position < size))
	{
		throw std::range_error("Position out of range in remove");
	}


	long count = position;

	while (count < size - 1)
	{
		data[count] = data[count + 1];
		count++;
	}

	size--;
	

}

template <typename T> 
void DynamicArrayList<T>::clear() 
{ 
	size = 0; 
}

template <typename T>
T DynamicArrayList<T>:: getEntry(std::size_t position) 
{

	if (!(position >= 0 && position < size))
	{
		throw std::range_error("Position out of range in getEntry");
	}

	return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T &newValue) {

	if (!(position >= 0 && position < size))
	{
		throw std::range_error("Position out of range in setEntry");
	}

	data[position] = newValue;
	
}