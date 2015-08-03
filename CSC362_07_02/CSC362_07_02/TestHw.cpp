#include "TestHarness.h"
#include "LinkedStackType.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
    return SimpleString(value.c_str());
}

TEST(LinkedStackType, integerTestBase )// test integers added and removed  to stack.
{
    LinkedStackType<int> stack1;
    LinkedStackType<int> stack2;

    stack1.push(23);
    stack1.push(45);
    stack1.push(38);

    LONGS_EQUAL(38 , stack1.top());
    stack1.pop();
    LONGS_EQUAL(45 , stack1.top());
    stack1.pop();
    LONGS_EQUAL(23 , stack1.top());
    stack1.pop();

}

TEST(LinkedStackType, stringTestBase )// test strings added and removed to stack.
{
    LinkedStackType<string> stack1;
    LinkedStackType<string> stack2;

    stack1.push("aaa");
    stack1.push("bbb");
    stack1.push("ccc");

    CHECK_EQUAL("ccc", stack1.top());
    stack1.pop();
    CHECK_EQUAL("bbb", stack1.top());
    stack1.pop();
    CHECK_EQUAL("aaa", stack1.top());
    stack1.pop();
}

TEST(LinkedStackType, integerTest)// test integers add and removed to stack with reverseStack
{
	LinkedStackType<int> stack1;
	LinkedStackType<int> stack2;

	stack1.push(23);
	stack1.push(45);
	stack1.push(38);
	stack1.reverseStack(stack2);

	LONGS_EQUAL(38, stack1.top());
	stack1.pop();
	LONGS_EQUAL(45, stack1.top());
	stack1.pop();
	LONGS_EQUAL(23, stack1.top());
	stack1.pop();

	LONGS_EQUAL(23, stack2.top());
	stack2.pop();
	LONGS_EQUAL(45, stack2.top());
	stack2.pop();
	LONGS_EQUAL(38, stack2.top());
	stack2.pop();
}

TEST(LinkedStackType, stringTest)// test strings add and removed to stack with reverseStack
{
	LinkedStackType<string> stack1;
	LinkedStackType<string> stack2;

	stack1.push("aaa");
	stack1.push("bbb");
	stack1.push("ccc");
	stack1.reverseStack(stack2);

	CHECK_EQUAL("ccc", stack1.top());
	stack1.pop();
	CHECK_EQUAL("bbb", stack1.top());
	stack1.pop();
	CHECK_EQUAL("aaa", stack1.top());
	stack1.pop();

	CHECK_EQUAL("aaa", stack2.top());
	stack2.pop();
	CHECK_EQUAL("bbb", stack2.top());
	stack2.pop();
	CHECK_EQUAL("ccc", stack2.top());
	stack2.pop();
}

