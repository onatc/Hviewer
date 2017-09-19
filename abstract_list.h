// DO NOT MODIFY THIS FILE
#ifndef _ABSTRACT_LIST_H_
#define _ABSTRACT_LIST_H_

template <typename T>
class AbstractList
{
public:
  // determine if a list is empty
  virtual bool isEmpty() = 0;

  // return current lenght of the list
  virtual std::size_t getLength() = 0;

  // insert item at position in the list using 0-based indexing
  virtual void insert(std::size_t position, const T& item) = 0;

  // remove item at position in the list using 0-based indexing
  virtual void remove(std::size_t position) = 0;

  // remove all items from the list
  virtual void clear() = 0;

  // get a copy of the item at position using 0-based indexing
  virtual T getEntry(std::size_t position) = 0;

  // set the value of the item at position using 0-based indexing
  virtual void setEntry(std::size_t position, const T& newValue) = 0;
};

#endif // _ABSTRACT_LIST_H_
