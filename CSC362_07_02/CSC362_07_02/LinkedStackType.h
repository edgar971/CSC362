//Header File: LinkedStackType.h

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

#include "StackADT.h"

using namespace std;

//*************************************************************
// This class specifies the basic operation on a stack as a 
// linked list.
//*************************************************************

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class LinkedStackType : public StackADT<Type>
{
public:
	const LinkedStackType<Type>& operator=
		(const LinkedStackType<Type>&);
	//Overload the assignment operator.

	bool isEmptyStack() const;
	//Function to determine whether the stack is empty.
	//Postcondition: Returns true if the stack is empty;
	//    otherwise returns false.

	bool isFullStack() const;
	//Function to determine whether the stack is full.
	//Postcondition: Returns false.

	void initializeStack();
	//Function to initialize the stack to an empty state. 
	//Postcondition: The stack elements are removed; 
	//    stackTop_ = NULL;

	void push(const Type& newItem);
	//Function to add newItem to the stack.
	//Precondition: The stack exists and is not full.
	//Postcondition: The stack is changed and newItem is 
	//    added to the top of the stack.

	Type top() const;
	//Function to return the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: If the stack is empty, the program 
	//    terminates; otherwise, the top element of
	//    the stack is returned.

	void pop();
	//Function to remove the top element of the stack.
	//Precondition: The stack exists and is not empty.
	//Postcondition: The stack is changed and the top 
	//    element is removed from the stack.


	void reverseStack(LinkedStackType<Type> & otherStack);
	LinkedStackType();
	//Default constructor
	//Postcondition: stackTop_ = NULL;

	LinkedStackType(const LinkedStackType<Type>& otherStack);
	//Copy constructor

	~LinkedStackType();
	//Destructor
	//Postcondition: All the elements of the stack are removed.

private:
	nodeType<Type> *stackTop_; //pointer to the stack

	void copyStack(const LinkedStackType<Type>& otherStack);
	//Function to make a copy of otherStack.
	//Postcondition: A copy of otherStack is created and
	//    assigned to this stack.
};

//Default constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType()
{
	stackTop_ = NULL;
}

template <class Type>
bool LinkedStackType<Type>::isEmptyStack() const
{
	return(stackTop_ == NULL);
} //end isEmptyStack

template <class Type>
bool LinkedStackType<Type>::isFullStack() const
{
	return false;
} //end isFullStack

template <class Type>
void LinkedStackType<Type>::initializeStack()
{
	nodeType<Type> *temp; //pointer to delete the node

	while (stackTop_ != NULL)  //while there are elements in 
		//the stack
	{
		temp = stackTop_;    //set temp to point to the 
		//current node
		stackTop_ = stackTop_->link;  //advance stackTop_ to the
		//next node
		delete temp;    //deallocate memory occupied by temp
	}
} //end initializeStack


template <class Type>
void LinkedStackType<Type>::push(const Type& newElement)
{
	nodeType<Type> *newNode;  //pointer to create the new node

	newNode = new nodeType<Type>; //create the node

	newNode->info = newElement; //store newElement in the node
	newNode->link = stackTop_; //insert newNode before stackTop_
	stackTop_ = newNode;       //set stackTop_ to point to the 
	//top node
} //end push


template <class Type>
Type LinkedStackType<Type>::top() const
{
	assert(stackTop_ != NULL); //if stack is empty,
	//terminate the program
	return stackTop_->info;    //return the top element 
}//end top

template <class Type>
void LinkedStackType<Type>::pop()
{
	nodeType<Type> *temp;   //pointer to deallocate memory

	if (stackTop_ != NULL)
	{
		temp = stackTop_;  //set temp to point to the top node

		stackTop_ = stackTop_->link;  //advance stackTop_ to the 
		//next node
		delete temp;    //delete the top node
	}
	else
		cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
void LinkedStackType<Type>::copyStack
(const LinkedStackType<Type>& otherStack)
{
	nodeType<Type> *newNode, *current, *last;

	if (stackTop_ != NULL) //if stack is nonempty, make it empty
		initializeStack();

	if (otherStack.stackTop_ == NULL)
		stackTop_ = NULL;
	else
	{
		current = otherStack.stackTop_;  //set current to point
		//to the stack to be copied

		//copy the stackTop_ element of the stack 
		stackTop_ = new nodeType<Type>;  //create the node

		stackTop_->info = current->info; //copy the info
		stackTop_->link = NULL;  //set the link field of the
		//node to NULL
		last = stackTop_;        //set last to point to the node
		current = current->link;    //set current to point to
		//the next node

		//copy the remaining stack
		while (current != NULL)
		{
			newNode = new nodeType<Type>;

			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}//end while
	}//end else
} //end copyStack

//copy constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType(
	const LinkedStackType<Type>& otherStack)
{
	stackTop_ = NULL;
	copyStack(otherStack);
}//end copy constructor

//destructor
template <class Type>
LinkedStackType<Type>::~LinkedStackType()
{
	initializeStack();
}//end destructor

//overloading the assignment operator
template <class Type>
const LinkedStackType<Type>& LinkedStackType<Type>::operator=
(const LinkedStackType<Type>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);

	return *this;
}//end operator=

template <class Type> 

void LinkedStackType<Type>::reverseStack(LinkedStackType<Type> & otherStack) {
	
	nodeType<Type> *current;
	otherStack.initializeStack();

	current = stackTop_->link;
	if (current != NULL) {
		otherStack.push(stackTop_->info);
	}
	while (current != NULL) {

 		otherStack.push(current->info);
 		current = current->link;
		
	}//end while
	
}

#endif