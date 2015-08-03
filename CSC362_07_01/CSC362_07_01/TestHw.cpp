#include "TestHarness.h"
#include "StackType.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}

TEST(StackType, integerTestBase) // test integers with top 
{
	StackType<int> stack1;
	StackType<int> stack2;

	stack1.push(23);
	stack1.push(45);
	stack1.push(38);

	LONGS_EQUAL(38, stack1.top());
	stack1.pop();
	LONGS_EQUAL(45, stack1.top());
	stack1.pop();
	LONGS_EQUAL(23, stack1.top());
	stack1.pop();

}

TEST(StackType, stringTestBase) // test strings with top
{
	StackType<string> stack1;
	StackType<string> stack2;

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


TEST(StackType, integerTest ) // test integers with reverseStack
{
StackType<int> stack1;
StackType<int> stack2;

stack1.push(23);
stack1.push(45);
stack1.push(38);

stack1.reverseStack(stack2);
LONGS_EQUAL(38 , stack1.top());
stack1.pop();
LONGS_EQUAL(45 , stack1.top());
stack1.pop();
LONGS_EQUAL(23 , stack1.top());
stack1.pop();

LONGS_EQUAL(23 , stack2.top());
stack2.pop();
LONGS_EQUAL(45 , stack2.top());
stack2.pop();
LONGS_EQUAL(38 , stack2.top());
stack2.pop();

}

TEST(StackType, stringTest ) // test string with reverseStack
{
StackType<string> stack1;
StackType<string> stack2;

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
