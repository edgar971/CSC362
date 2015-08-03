#include "TestHarness.h"
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

SimpleString StringFrom(const string& value) {

	return SimpleString(value.c_str());

}

TEST(BSearchTreeType, integerTestBase){
	BSearchTreeType<typename int> treeList;
	const int testNumSize = 13;
	int testNums[testNumSize] = { 34, 77, 26, 51, 39, 8, 12, 67, 4, 98, 123, 10, 42 };
	for (int i = 0; i < testNumSize; i++) {
		//insert item to list
		treeList.insert(testNums[i]);

	}

	LONGS_EQUAL(13, treeList.treeNodeCount());
	LONGS_EQUAL(5, treeList.treeHeight());
	LONGS_EQUAL(5, treeList.treeLeavesCount());
	CHECK_EQUAL(true, treeList.search(77));




};

TEST(BSearchTreeType, stringTest) {
	BSearchTreeType<typename string> treeListA;
	const int testListNum = 7;
	string testStrings[testListNum] = { "F", "B", "D", "A", "C", "E", "G" };
	for (int i = 0; i < testListNum; i++) {
		treeListA.insert(testStrings[i]);
	}
	
	LONGS_EQUAL(7, treeListA.treeNodeCount());
	LONGS_EQUAL(4, treeListA.treeHeight());
	LONGS_EQUAL(4, treeListA.treeLeavesCount());
	CHECK_EQUAL(false, treeListA.search("I"));

}