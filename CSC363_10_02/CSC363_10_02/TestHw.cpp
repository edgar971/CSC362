#include "TestHarness.h"
#include <iostream>
#include <string>
#include "ArrayListType.h"

SimpleString StringFrom(const string& value) {

	return SimpleString(value.c_str());

}

TEST(ArrayListType, integerTestBase) {
	ArrayListType<typename int> ListA;
	const int testNumSize = 13;
	int testNums[testNumSize] = { 34, 77, 26, 51, 39, 8, 12, 67, 4, 98, 123, 10, 42 };
	for (int i = 0; i < testNumSize; i++) {
		//insert item to list
		ListA.insert(testNums[i]);

	}

	//sort list
	ListA.quickSort();
	CHECK_EQUAL(true, ListA.isItemAtEqual(0, 4));
	CHECK_EQUAL(true, ListA.isItemAtEqual(12, 123));
	LONGS_EQUAL(13, ListA.listSize());


}

TEST(ArrayListType, stringTest) {
	ArrayListType<typename string> ListB;
	const int testListNum = 5;
	string testStrings[testListNum] = { "aaa", "ccc", "eee", "fff", "ttt"};
	for (int i = 0; i < testListNum; i++) {
		ListB.insert(testStrings[i]);
	}
	
	CHECK_EQUAL(true, ListB.isItemAtEqual(0, "aaa"));
	CHECK_EQUAL(true, ListB.isItemAtEqual(4, "ttt"));

}