#include "TestHarness.h"
#include "UnorderedLinkedList.h"
#include <string>
using namespace std;
bool FALSE = 0;
bool TRUE = 1;
SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}

TEST(UnorderedLinkedList, initialTest)//test numbers insertLast(x)/length()
{
	UnorderedLinkedList<int> intList;

	intList.insertLast(25);
	intList.insertLast(25);
	intList.insertLast(125);
	intList.insertLast(36);
	intList.insertLast(20);
	intList.insertLast(125);
	intList.insertLast(8);
	LONGS_EQUAL(7, intList.length());
	//search and remove  smallest 8 
	LONGS_EQUAL(TRUE, intList.search(8));
	intList.updateLength();
	LONGS_EQUAL(7, intList.length());
	LONGS_EQUAL(TRUE, intList.search(8));

}

TEST(UnorderedLinkedList, stringTest) //test string insertLast(x)/length(), deleteSmallest()
{
	UnorderedLinkedList<string> stringList;
	stringList.insertLast("ccc");
	stringList.insertLast("125");
	stringList.insertLast("aaa");
	stringList.insertLast("ddd");
	stringList.insertLast("ddd");
	stringList.insertLast("bbb");
	stringList.insertLast("ddd");
	LONGS_EQUAL(7, stringList.length());
	//search 
	LONGS_EQUAL(TRUE, stringList.search("125"));
	stringList.updateLength();
	LONGS_EQUAL(7, stringList.length());
	LONGS_EQUAL(TRUE, stringList.search("125"));
}


TEST(UnorderedLinkedList, initialTest1)//test numbers insertLast(x)/length(), deleteSmallest()
{
UnorderedLinkedList<int> intList;

intList.insertLast(25);
intList.insertLast(25);
intList.insertLast(125);
intList.insertLast(36);
intList.insertLast(20);
intList.insertLast(125);
intList.insertLast(8);
LONGS_EQUAL(7, intList.length());
//search and remove  smallest 8
LONGS_EQUAL(TRUE, intList.search(8));
intList.deleteSmallest();
intList.updateLength();
LONGS_EQUAL(6, intList.length());
LONGS_EQUAL(FALSE, intList.search(8));
}

TEST(UnorderedLinkedList, initialTest2)//test numbers insertLast(x)/length(), deleteAll()
{
UnorderedLinkedList<int> intList;
intList.insertLast(25);
intList.insertLast(25);
intList.insertLast(125);
intList.insertLast(36);
intList.insertLast(20);
intList.insertLast(125);
intList.insertLast(8);
LONGS_EQUAL(7, intList.length());

//search and remove all "ddd"
LONGS_EQUAL(1, intList.search(25));
intList.deleteAll(25);
intList.updateLength();
LONGS_EQUAL(5, intList.length());
LONGS_EQUAL(0, intList.search(25));
}

TEST(UnorderedLinkedList, stringTest1) //test string insertLast(x)/length(), deleteSmallest()
{
UnorderedLinkedList<string> stringList;
stringList.insertLast("ccc");
stringList.insertLast("125");
stringList.insertLast("aaa");
stringList.insertLast("ddd");
stringList.insertLast("ddd");
stringList.insertLast("bbb");
stringList.insertLast("ddd");
LONGS_EQUAL(7, stringList.length());
//search and remove  smallest "125"
LONGS_EQUAL(TRUE, stringList.search("125"));
stringList.deleteSmallest();
stringList.updateLength();
LONGS_EQUAL(6, stringList.length());
LONGS_EQUAL(FALSE, stringList.search("125"));
}

TEST(UnorderedLinkedList, stringTest2) //test string insertLast(x)/length(), deleteAll)
{
UnorderedLinkedList<string> stringList;
stringList.insertLast("ccc");
stringList.insertLast("125");
stringList.insertLast("aaa");
stringList.insertLast("ddd");
stringList.insertLast("ddd");
stringList.insertLast("bbb");
stringList.insertLast("ddd");
LONGS_EQUAL(7, stringList.length());
//search and remove all "ddd"
LONGS_EQUAL(TRUE, stringList.search("ddd"));
stringList.deleteAll("ddd");
stringList.updateLength();
LONGS_EQUAL(4, stringList.length());
LONGS_EQUAL(FALSE, stringList.search("ddd"));
}
