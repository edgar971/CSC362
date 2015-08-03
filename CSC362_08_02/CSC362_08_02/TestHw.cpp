#include "TestHarness.h"
#include "QueueType.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}

TEST(QueueType, integerTestBase) {
	QueueType <typename int> queue1;
	queue1.addQueue(2);
	queue1.addQueue(3);
	queue1.addQueue(6);
	queue1.addQueue(9);
	queue1.addQueue(10);

	LONGS_EQUAL(2, queue1.front());
	LONGS_EQUAL(10, queue1.back());
	queue1.deleteQueue();
	LONGS_EQUAL(3, queue1.front());
	CHECK_EQUAL(false, queue1.isEmptyQueue());
	queue1.moveNthFront(3);
	LONGS_EQUAL(6, queue1.front());

}


TEST(QueueType, stringTest) {
	QueueType <typename string> queue2;

	queue2.addQueue("a");
	queue2.addQueue("b");
	queue2.addQueue("c");
	queue2.addQueue("d");
	queue2.addQueue("e");

	CHECK_EQUAL("a", queue2.front());
	CHECK_EQUAL("e", queue2.back());
	queue2.moveNthFront(5);
	CHECK_EQUAL("e", queue2.front());
	queue2.deleteQueue();
	CHECK_EQUAL("b", queue2.front());
	queue2.initializeQueue();
	CHECK_EQUAL(true, queue2.isEmptyQueue());


}

