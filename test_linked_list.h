#include <string>
#include <cxxtest/TestSuite.h>

#include "linked_list.h"

#include <cstdlib>
#include <stack>



class LinkedListTests : public CxxTest::TestSuite
{
public:
	void testCopyConst(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 2);
		a.insert(2, 3);

		LinkedList<int> b = a;

		TS_ASSERT_EQUALS(a.getLength(), b.getLength());
		TS_ASSERT_EQUALS(a.getEntry(0), b.getEntry(0));
		TS_ASSERT_EQUALS(a.getEntry(1), b.getEntry(1));
		TS_ASSERT_EQUALS(a.getEntry(2), b.getEntry(2));

	}

	void testInsert(void)
	{
		LinkedList<std::string> a;

		a.insert(0, "hi");
		a.insert(1, "dog");


		TS_ASSERT_EQUALS(a.getEntry(0), "hi");
		TS_ASSERT_EQUALS(a.getEntry(1), "dog");

	}

	void testIsEmpty1(void)
	{
		LinkedList<std::string> a;

		TS_ASSERT_EQUALS(a.isEmpty(), true);
	}

	void testIsEmpty2(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);

		TS_ASSERT_EQUALS(a.isEmpty(), false);
	}

	void testGetLength(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 5);
		a.remove(0);

		TS_ASSERT_EQUALS(a.getLength(), 1);
	}

	void testRemove1(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 2);
		a.insert(2, 3);
		a.remove(1);

		TS_ASSERT_EQUALS(a.getEntry(0), 1);
		TS_ASSERT_EQUALS(a.getEntry(1), 3);
		TS_ASSERT_EQUALS(a.getLength(), 2);
	}

	void testRemove2(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 2);
		a.insert(2, 3);
		a.remove(2);
		a.remove(0);

		TS_ASSERT_EQUALS(a.getEntry(0), 2);
		TS_ASSERT_EQUALS(a.getLength(), 1);
	}

	void testClear(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 2);
		a.insert(2, 3);
		a.clear();

		TS_ASSERT_EQUALS(a.getLength(), 0);
	}

	void testGetEntry(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 19);
		a.insert(2, 25);


		TS_ASSERT_EQUALS(a.getEntry(2), 25);
	}

	void testSetEntry(void)
	{
		LinkedList<int> a;

		a.insert(0, 1);
		a.insert(1, 19);
		a.insert(2, 25);
		a.setEntry(1, 125);


		TS_ASSERT_EQUALS(a.getEntry(1), 125);
	}
};
