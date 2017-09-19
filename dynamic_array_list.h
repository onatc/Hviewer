#ifndef _DYNAMIC_ARRAY_LIST_H_
#define _DYNAMIC_ARRAY_LIST_H_

#include "abstract_list.h"

template <typename T> class DynamicArrayList : public AbstractList<T> {
public:

	DynamicArrayList();

	DynamicArrayList(const DynamicArrayList &x);

	~DynamicArrayList();

	DynamicArrayList &operator=(DynamicArrayList x);

	bool isEmpty();

	std::size_t getLength();

	void insert(std::size_t position, const T &item);

	void remove(std::size_t position);

	void clear();

	T getEntry(std::size_t position);

	void setEntry(std::size_t position, const T &newValue);

	void swap(DynamicArrayList &x, DynamicArrayList &y);

private:

	T *data;
	std::size_t capacity;
	std::size_t size;

};

#include "dynamic_array_list.txx"

#endif // _DYNAMIC_ARRAY_LIST_H_
