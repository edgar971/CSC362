//Header file QueueType

#ifndef H_QueueType
#define H_QueueType

#include <iostream>
#include <vector>
#include <cassert>

#include "QueueADT.h"

using namespace std;

//*************************************************************
// This class specifies the basic operation on a queue as an 
// array.
//*************************************************************

template <class Type>
class QueueType : public QueueADT<Type>
{
public:
	const QueueType<Type>& operator=(const QueueType<Type>&);
	//Overload the assignment operator.

	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	//    otherwise returns false.

	bool isFullQueue() const;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	//    otherwise returns false.

	void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: count_ = 0; queueFront_ = 0;
	//    queueRear_ = maxQueueSize_ – 1

	Type front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program 
	//    terminates; otherwise, the first element of
	//    the queue is returned.  
	Type back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program 
	//    terminates; otherwise, the last element of  
	//    the queue is returned.



	void addQueue(const Type& queueElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement
	//    is added to the queue.

	void deleteQueue();
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first 
	//    element is removed from the queue.

	void moveNthFront(int item);

	QueueType(int queueSize = 100);
	//Constructor

	QueueType(const QueueType<Type>& otherQueue);
	//Copy constructor

	~QueueType();
	//Destructor



private:
	int maxQueueSize_; //variable to store the maximum queue size
	int count_;        //variable to store the number of
	//elements in the queue
	int queueFront_;   //variable to point to the first
	//element of the queue
	int queueRear_;    //variable to point to the last
	//element of the queue
	Type *list_;       //pointer to the array that holds 
	//the queue elements 
};

template <class Type>
bool QueueType<Type>::isEmptyQueue() const
{
	return (count_ == 0);
} //end isEmptyQueue

template <class Type>
bool QueueType<Type>::isFullQueue() const
{
	return (count_ == maxQueueSize_);
} //end isFullQueue

template <class Type>
void QueueType<Type>::initializeQueue()
{
	queueFront_ = 0;
	queueRear_ = maxQueueSize_ - 1;
	count_ = 0;
} //end initializeQueue

template <class Type>
Type QueueType<Type>::front() const
{
	assert(!isEmptyQueue());
	return list_[queueFront_];
} //end front

template <class Type>
Type QueueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list_[queueRear_];
} //end back




template <class Type>
void QueueType<Type>::addQueue(const Type& newElement)
{
	if (!isFullQueue())
	{
		queueRear_ = (queueRear_ + 1) % maxQueueSize_; //use mod
		//operator to advance queueRear_  
		//because the array is circular
		count_++;
		list_[queueRear_] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
} //end addQueue

template <class Type>
void QueueType<Type>::deleteQueue()
{
	if (!isEmptyQueue())
	{
		count_--;
		queueFront_ = (queueFront_ + 1) % maxQueueSize_; //use the
		//mod operator to advance queueFront_ 
		//because the array is circular 
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue

//move nth item to front 

template <class Type>
void QueueType<Type>::moveNthFront(int item) {
	
	//set the first to the nth value 
	if (!isEmptyQueue()) {
		Type& prev = list_[item - 1];
		Type current;
		for (int i = 0; i < item; i++) {

			current = list_[i];
			list_[i] = prev;
			prev = current;
			
		
		}
	}
	else {
		cout << "List is empty" << endl;
	}
	
	

}

//Constructor
template <class Type>
QueueType<Type>::QueueType(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxQueueSize_ = 100;
	}
	else
		maxQueueSize_ = queueSize;   //set maxQueueSize_ to 
	//queueSize

	queueFront_ = 0;                 //initialize queueFront_
	queueRear_ = maxQueueSize_ - 1;   //initialize queueRear_
	count_ = 0;
	list_ = new Type[maxQueueSize_];  //create the array to
	//hold the queue elements
} //end constructor

//Destructor
template <class Type>
QueueType<Type>::~QueueType()
{
	delete[] list_;
} //end destructor

template <class Type>
const QueueType<Type>& QueueType<Type>::operator=
(const QueueType<Type>& otherQueue)
{
	cout << "Write the definition of the function "
		<< "to overload the assignment operator." << endl;
} //end assignment operator

template <class Type>
QueueType<Type>::QueueType(const QueueType<Type>& otherQueue)
{
	cout << "Write the definition of the copy constructor."
		<< endl;
} //end copy constructor





#endif
