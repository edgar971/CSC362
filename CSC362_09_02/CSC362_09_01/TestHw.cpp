#include "TestHarness.h"
#include "OrderedArrayListType.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}

TEST(OrderedArrayListType, integerTestBase) {
	OrderedArrayListType<typename int> listA;
	listA.insertOrd(1);
	listA.insertOrd(5);
	listA.insertOrd(23);
	listA.insertOrd(21);
	listA.insertOrd(20);
	listA.insertOrd(25);

	LONGS_EQUAL(1, listA.seqOrdSearch(1));
	LONGS_EQUAL(2, listA.seqOrdSearch(5));
	LONGS_EQUAL(1, listA.seqOrdSearch(1));


}


TEST(OrderedArrayListType, stringTest) {
	OrderedArrayListType <typename string> listB;

	listB.insertOrd("a");
	listB.insertOrd("b");
	listB.insertOrd("c");
	listB.insertOrd("d");
	listB.insertOrd("e");

	LONGS_EQUAL(3, listB.seqOrdSearch("c"));
	LONGS_EQUAL(1, listB.seqOrdSearch("a"));
	LONGS_EQUAL(5, listB.seqOrdSearch("e"));


}

