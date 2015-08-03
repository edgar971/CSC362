#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the node

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

//***********************************************************

//
// This class specifies the members to implement an iterator
// to a linked list.
//***********************************************************

template <class Type>
class LinkedListIterator
{
public:
	LinkedListIterator();
	//Default constructor
	//Postcondition: current_ = NULL;

	LinkedListIterator(nodeType<Type> *ptr);
	//Constructor with a parameter.
	//Postcondition: current_ = ptr;

	Type operator*();
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.

	LinkedListIterator<Type> operator++();
	//Overload the preincrement operator.
	//Postcondition: The iterator is advanced to the next 
	//               node.

	bool operator==(const LinkedListIterator<Type>& right) const;
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to 
	//               the iterator specified by right, 
	//               otherwise it returns the value false.

	bool operator!=(const LinkedListIterator<Type>& right) const;
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not  
	//               equal to the iterator specified by  
	//               right; otherwise it returns the value 
	//               false.
	virtual void deleteAll(const Type& deleteItem) = 0;
	virtual void deleteSmallest() = 0;

private:
	nodeType<Type> *current_; //pointer to point to the current_ 
	//node in the linked list
};

template <class Type>
LinkedListIterator<Type>::LinkedListIterator()
{
	current_ = NULL;
}

template <class Type>
LinkedListIterator<Type>::
LinkedListIterator(nodeType<Type> *ptr)
{
	current_ = ptr;
}

template <class Type>
Type LinkedListIterator<Type>::operator*()
{
	return current_->info;
}

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++()
{
	current_ = current_->link;

	return *this;
}

template <class Type>
bool LinkedListIterator<Type>::operator==
(const LinkedListIterator<Type>& right) const
{
	return (current_ == right.current_);
}

template <class Type>
bool LinkedListIterator<Type>::operator!=
(const LinkedListIterator<Type>& right) const
{
	return (current_ != right.current_);
}

//***********************************************************

//
// This class specifies the members to implement the basic
// properties of a linked list. This is an abstract class.
// We cannot instantiate an object of this class.
//***********************************************************

template <class Type>
class LinkedListType
{
public:
	const LinkedListType<Type>& operator=
		(const LinkedListType<Type>&);
	//Overload the assignment operator.

	void initializeList();
	//Initialize the list to an empty state.
	//Postcondition: first_ = NULL, last_ = NULL, count_ = 0;

	bool isEmptyList() const;
	//Function to determine whether the list is empty. 
	//Postcondition: Returns true if the list is empty,
	//               otherwise it returns false.

	void print() const;
	//Function to output the data contained in each node.
	//Postcondition: none

	int length() const;
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count_ is returned.

	void destroyList();
	//Function to delete all the nodes from the list.
	//Postcondition: first_ = NULL, last_ = NULL, count_ = 0;

	Type front() const;
	//Function to return the first_ element of the list.
	//Precondition: The list must exist and must not be 
	//              empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the first_ 
	//               element of the list is returned.

	Type back() const;
	//Function to return the last_ element of the list.
	//Precondition: The list must exist and must not be 
	//              empty.
	//Postcondition: If the list is empty, the program
	//               terminates; otherwise, the last_  
	//               element of the list is returned.

	virtual bool search(const Type& searchItem) const = 0;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the 
	//               list, otherwise the value false is 
	//               returned.

	virtual void insertFirst(const Type& newItem) = 0;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first_ points to the new list, newItem is
	//               inserted at the beginning of the list,
	//               last_ points to the last_ node in the list, 
	//               and count_ is incremented by 1.

	virtual void insertLast(const Type& newItem) = 0;
	//Function to insert newItem at the end of the list.
	//Postcondition: first_ points to the new list, newItem 
	//               is inserted at the end of the list,
	//               last_ points to the last_ node in the list,
	//               and count_ is incremented by 1.

	virtual void deleteNode(const Type& deleteItem) = 0;
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing 
	//               deleteItem is deleted from the list.
	//               first_ points to the first_ node, last_
	//               points to the last_ node of the updated 
	//               list, and count_ is decremented by 1.

	void updateLength();
	//Function to update length

	//Postcondition: none
	LinkedListIterator<Type> begin();
	//Function to return an iterator at the beginning of the 
	//linked list.
	//Postcondition: Returns an iterator such that current_ is
	//               set to first_.

	LinkedListIterator<Type> end();
	//Function to return an iterator one element past the 
	//last_ element of the linked list. 
	//Postcondition: Returns an iterator such that current_ is
	//               set to NULL.

	LinkedListType();
	//default constructor
	//Initializes the list to an empty state.
	//Postcondition: first_ = NULL, last_ = NULL, count_ = 0; 

	LinkedListType(const LinkedListType<Type>& otherList);
	//copy constructor

	~LinkedListType();
	//destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed. 

protected:
	int count_;   //variable to store the number of 
	//elements in the list
	nodeType<Type> *first_; //pointer to the first_ node of the list
	nodeType<Type> *last_;  //pointer to the last_ node of the list

private:
	void copyList(const LinkedListType<Type>& otherList);
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and
	//               assigned to this list.
};


template <class Type>
bool LinkedListType<Type>::isEmptyList() const
{
	return(first_ == NULL);
}

template <class Type>
LinkedListType<Type>::LinkedListType() //default constructor
{
	first_ = NULL;
	last_ = NULL;
	count_ = 0;
}

template <class Type>
void LinkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;   //pointer to deallocate the memory
	//occupied by the node
	while (first_ != NULL)   //while there are nodes in the list
	{
		temp = first_;        //set temp to the current_ node
		first_ = first_->link; //advance first_ to the next node
		delete temp;   //deallocate the memory occupied by temp
	}
	last_ = NULL; //initialize last_ to NULL; first_ has already
	//been set to NULL by the while loop
	count_ = 0;
}

template <class Type>
void LinkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template <class Type>
void LinkedListType<Type>::print() const
{
	nodeType<Type> *current_; //pointer to traverse the list

	current_ = first_;    //set current_ so that it points to 
	//the first_ node
	while (current_ != NULL) //while more data to print
	{
		cout << current_->info << " ";
		current_ = current_->link;
	}
}//end print

template <class Type>
int LinkedListType<Type>::length() const
{
	return count_;
}  //end length

template <class Type>
Type LinkedListType<Type>::front() const
{
	assert(first_ != NULL);

	return first_->info; //return the info of the first_ node	
}//end front

template <class Type>
Type LinkedListType<Type>::back() const
{
	assert(last_ != NULL);

	return last_->info; //return the info of the last_ node	
}//end back

template <class Type>
LinkedListIterator<Type> LinkedListType<Type>::begin()
{
	LinkedListIterator<Type> temp(first_);

	return temp;
}

template <class Type>
LinkedListIterator<Type> LinkedListType<Type>::end()
{
	LinkedListIterator<Type> temp(NULL);

	return temp;
}

template <class Type>
void LinkedListType<Type>::copyList
(const LinkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current_; //pointer to traverse the list

	if (first_ != NULL) //if the list is nonempty, make it empty
		destroyList();

	if (otherList.first_ == NULL) //otherList is empty
	{
		first_ = NULL;
		last_ = NULL;
		count_ = 0;
	}
	else
	{
		current_ = otherList.first_; //current_ points to the 
		//list to be copied
		count_ = otherList.count_;

		//copy the first_ node
		first_ = new nodeType<Type>;  //create the node

		first_->info = current_->info; //copy the info
		first_->link = NULL;        //set the link field of 
		//the node to NULL
		last_ = first_;              //make last_ point to the
		//first_ node
		current_ = current_->link;     //make current_ point to
		//the next node

		//copy the remaining list
		while (current_ != NULL)
		{
			newNode = new nodeType<Type>;  //create a node
			newNode->info = current_->info; //copy the info
			newNode->link = NULL;       //set the link of 
			//newNode to NULL
			last_->link = newNode;  //attach newNode after last_
			last_ = newNode;        //make last_ point to
			//the actual last_ node
			current_ = current_->link;   //make current_ point 
			//to the next node
		}//end while
	}//end else
}//end copyList

template <class Type>
LinkedListType<Type>::~LinkedListType() //destructor
{
	destroyList();
}//end destructor

template <class Type>
LinkedListType<Type>::LinkedListType
(const LinkedListType<Type>& otherList)
{
	first_ = NULL;
	copyList(otherList);
}//end copy constructor

//overload the assignment operator
template <class Type>
const LinkedListType<Type>& LinkedListType<Type>::operator=
(const LinkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}//end else

	return *this;
}

template <class Type>
void LinkedListType<Type>::updateLength()
{
	nodeType<Type> *current_; //pointer to traverse the list
	count_ = 0;
	current_ = first_;    //set current_ so that it points to 
	//the first_ node
	while (current_ != NULL) //while more data to print
	{
		count_++;
		current_ = current_->link;
	}
}//end print


#endif
