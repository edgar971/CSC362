#include "TestHarness.h"
#include "OrderedLinkedList.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}
TEST(OrderedLinkedList, initialTest)
{
	OrderedLinkedList<int> intList;

	intList.insert(25);
	intList.insert(25);
	intList.insert(125);
	intList.insert(36);
	intList.insert(20);
	intList.insert(125);
	intList.insert(8);
	LONGS_EQUAL(5, intList.length());


	intList.insert(125);
	intList.updateLength();
	LONGS_EQUAL(5, intList.length());

	intList.insert(25);
	intList.updateLength();
	LONGS_EQUAL(5, intList.length());

}

TEST(OrderedLinkedList, stringTest)
{
	OrderedLinkedList<string> stringList;

	stringList.insert("aaa");
	stringList.insert("ccc");
	stringList.insert("125");
	stringList.insert("ddd");
	stringList.insert("ddd");
	stringList.insert("bbb");
	stringList.insert("ddd");

	LONGS_EQUAL(5, stringList.length());


	stringList.insert("aaa");
	stringList.updateLength();
	LONGS_EQUAL(5, stringList.length());

	stringList.insert("ddd");
	stringList.updateLength();
	LONGS_EQUAL(5, stringList.length());

}
