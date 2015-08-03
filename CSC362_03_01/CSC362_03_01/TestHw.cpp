#include "TestHarness.h"
#include "ArrayListType.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}
TEST(ArrayListType, initialTest) //test numbers insertAt(i,X), listSize, maxListSize, remove(x)
{
	ArrayListType<int> intList(100);

	intList.insertAt(0, 25);
	intList.insertAt(1, 25);
	intList.insertAt(2, 125);
	intList.insertAt(3, 36);
	intList.insertAt(4, 20);
	intList.insertAt(5, 125);
	intList.insertAt(6, 8);
	LONGS_EQUAL(7, intList.listSize());
	LONGS_EQUAL(100, intList.maxListSize());

	intList.remove(125);
	LONGS_EQUAL(6, intList.listSize());

	intList.remove(25);
	LONGS_EQUAL(5, intList.listSize());

}

TEST(ArrayListType, stringTest) //test string insertAt(i,X), listSize, maxListSize, remove(x)
{
	ArrayListType<string> stringList;

	stringList.insertAt(0, "aaa");
	stringList.insertAt(1, "ccc");
	stringList.insertAt(2, "125");
	stringList.insertAt(3, "ddd");
	stringList.insertAt(4, "ddd");
	stringList.insertAt(5, "bbb");
	stringList.insertAt(6, "ddd");

	LONGS_EQUAL(7, stringList.listSize());
	LONGS_EQUAL(100, stringList.maxListSize());

	stringList.remove("ddd");
	LONGS_EQUAL(6, stringList.listSize());

}
TEST(ArrayListType, removeAllIntTest) // Test removeAll for specific occurrence of numeric values
{
	ArrayListType<int> intList(100);

	intList.insertAt(0, 25);
	intList.insertAt(1, 25);
	intList.insertAt(2, 125);
	intList.insertAt(3, 36);
	intList.insertAt(4, 20);
	intList.insertAt(5, 125);
	intList.insertAt(6, 8);
	LONGS_EQUAL(7, intList.listSize());
	LONGS_EQUAL(100, intList.maxListSize());

	intList.removeAll(125);
	LONGS_EQUAL(5, intList.listSize());

	intList.removeAll(25);
	LONGS_EQUAL(3, intList.listSize());

}

TEST(ArrayListType, removeAllStringTest)// Test removeAll for specific occurrence of string values
{
	ArrayListType<string> stringList;

	stringList.insertAt(0, "aaa");
	stringList.insertAt(1, "ccc");
	stringList.insertAt(2, "125");
	stringList.insertAt(3, "ddd");
	stringList.insertAt(4, "ddd");
	stringList.insertAt(5, "bbb");
	stringList.insertAt(6, "ddd");

	LONGS_EQUAL(7, stringList.listSize());
	LONGS_EQUAL(100, stringList.maxListSize());

	stringList.removeAll("ddd");
	LONGS_EQUAL(4, stringList.listSize());

}
