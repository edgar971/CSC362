//Header file: myStack.h

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

#include "StackADT.h"

using namespace std;

//*************************************************************

// This class specifies the basic operation on a stack as an 
// array.
//*************************************************************

template <class Type>
class StackType : public StackADT<Type>
{
public:
	const StackType<Type>& operator=(const StackType<Type>&);
	//Overload the assignment operator.

	void initializeStack();
	//Function to initialize the stack to an empty state.
	//Postcondition: stackTop_ = 0;

	bool isEmptyStack() const;
	//Function to determine whether the stack is empty.
	//Postcondition: Returns true if the stack is empty,
	//    otherwise returns false.

	bool isFullStack() const;
	//Function to determine whether the stack is full.
	//Postcondition: Returns true if the stack is full,
	//    otherwise returns false.

	void push(const Type& newItem);
	//Function to add newItem to the stack.
	//Precondition: The stack exists and is not full.
	//Postcondition: The stack is changed and newItem is
	//    added to the top of the stack.

	Type top() const;
	//Function to return the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: If the stack is empty, the program 
	//    terminates; otherwise, the top element of the stack
	//    is returned.

	void pop();
	//Function to remove the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: The stack is changed and the top element is
	//    removed from the stack.

	void reverseStack(StackType<Type> &otherStack);

	StackType(int stackSize = 100);
	//Constructor
	//Create an array of the size stackSize to hold 
	//the stack elements. The default stack size is 100.
	//Postcondition: The variable list_ contains the base address 
	//   of the array, stackTop_ = 0, and maxStackSize_ = stackSize

	StackType(const StackType<Type>& otherStack);
	//Copy constructor

	~StackType();
	//Destructor
	//Remove all the elements from the stack.
	//Postcondition: The array (list_) holding the stack 
	//    elements is deleted.

private:
	int maxStackSize_; //variable to store the maximum stack size
	int stackTop_;     //variable to point to the top of the stack
	Type *list_; //pointer to the array that holds the stack elements

	void copyStack(const StackType<Type>& otherStack);
	//Function to make a copy of otherStack.
	//Postcondition: A copy of otherStack is created and assigned
	//    to this stack.
};

template <class Type>
void StackType<Type>::initializeStack()
{
	stackTop_ = 0;
}//end initializeStack

template <class Type>
bool StackType<Type>::isEmptyStack() const
{
	return(stackTop_ == 0);
}//end isEmptyStack

template <class Type>
bool StackType<Type>::isFullStack() const
{
	return(stackTop_ == maxStackSize_);
} //end isFullStack

template <class Type>
void StackType<Type>::push(const Type& newItem)
{
	if (!isFullStack())
	{
		list_[stackTop_] = newItem;   //add newItem to the 
		//top of the stack
		stackTop_++; //increment stackTop_
	}
	else
		cout << "Cannot add to a full stack." << endl;
}//end push

template <class Type>
Type StackType<Type>::top() const
{
	assert(stackTop_ != 0);          //if stack is empty, 
	//terminate the program
	return list_[stackTop_ - 1];      //return the element of the
	//stack indicated by 
	//stackTop_ - 1
}//end top

template <class Type>
void StackType<Type>::pop()
{
	if (!isEmptyStack())
		stackTop_--;                 //decrement stackTop_ 
	else
		cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
StackType<Type>::StackType(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxStackSize_ = 100;
	}
	else
		maxStackSize_ = stackSize;   //set the stack size to 
	//the value specified by
	//the parameter stackSize

	stackTop_ = 0;                   //set stackTop_ to 0
	list_ = new Type[maxStackSize_];  //create the array to
	//hold the stack elements
}//end constructor

template <class Type>
StackType<Type>::~StackType() //destructor
{
	delete[] list_; //deallocate the memory occupied 
	//by the array
}//end destructor

template <class Type>
void StackType<Type>::copyStack(const StackType<Type>& otherStack)
{
	delete[] list_;
	maxStackSize_ = otherStack.maxStackSize_;
	stackTop_ = otherStack.stackTop_;

	list_ = new Type[maxStackSize_];

	//copy otherStack into this stack
	for (int j = 0; j < stackTop_; j++)
		list_[j] = otherStack.list_[j];
} //end copyStack


template <class Type>
StackType<Type>::StackType(const StackType<Type>& otherStack)
{
	list_ = NULL;

	copyStack(otherStack);
}//end copy constructor

template <class Type>
const StackType<Type>& StackType<Type>::operator=
(const StackType<Type>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);

	return *this;
} //end operator=         

template <class Type>

void StackType<Type>::reverseStack(StackType<Type> &otherStack) {
	//empty the stack if its not already
	otherStack.initializeStack();
	//for each item in the current stack
	for (int current = 0; current < stackTop_; current++) {
		//push each item into the other stack
		Type item = list_[(stackTop_ - 1) - current];
		otherStack.push(item);
	}
	

}

#endif