#ifndef H_orderedListType
#define H_orderedListType

//***********************************************************

//
// This class specifies the members to implement the basic
// properties of an ordered linked list. This class is
// derived from the class LinkedListType. 
//***********************************************************

#include "LinkedListType.h"

using namespace std;

template <class Type>
class OrderedLinkedList : public LinkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list, 
	//    otherwise the value false is returned.

	void insert(const Type& newItem);
	//Function to insert newItem in the list.
	//Postcondition: first_ points to the new list, newItem 
	//    is inserted at the proper place in the list, and
	//    count_ is incremented by 1.

	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first_ points to the new list, newItem is
	//    inserted at the beginning of the list, last_ points
	//    to the last_ node in the list, and count_ is incremented
	//    by 1.

	void insertLast(const Type& newItem);
	//Function to insert newItem at the end of the list.
	//Postcondition: first_ points to the new list, newItem 
	//    is inserted at the end of the list, last_ points to the
	//    last_ node in the list, and count_ is incremented by 1.

	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem
	//    is deleted from the list; first_ points to the first_
	//    node of the new list, and count_ is decremented by 1.
	//    If deleteItem is not in the list, an appropriate 
	//    message is printed.
};


template <class Type>
bool OrderedLinkedList<Type>::search(const Type& searchItem) const
{
	bool found = false;
	nodeType<Type> *current; //pointer to traverse the list

	current = first_;  //start the search at the first_ node

	while (current != NULL && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;

	if (found)
		found = (current->info == searchItem); //test for equality

	return found;
}//end search


template <class Type>
void OrderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	nodeType<Type> *newNode;  //pointer to create a node

	bool  found;

	newNode = new nodeType<Type>; //create the node
	newNode->info = newItem;   //store newItem in the node
	newNode->link = NULL;      //set the link field of the node
	//to NULL
	
	if (first_ == NULL)  //Case 1
	{
		first_ = newNode;
		last_ = newNode;
		count_++;
	}
	else
	{
		found = search(newItem);
		if (!found) {
			current = first_;
			found = false;

			while (current != NULL && !found)
				if (current->info >= newItem)
					found = true;
				else
				{
					trailCurrent = current;
					current = current->link;
				}


			if (current == first_)
			{
				newNode->link = first_;
				first_ = newNode;
				count_++;
			}
			else
			{
				trailCurrent->link = newNode;
				newNode->link = current;

				if (current == NULL)
					last_ = newNode;

				count_++;
			}
		}
		else {
			cout << "the item " << newItem << " to be inserted in already in the list" << endl;
		}
	}//end else
}//end insert

template<class Type>
void OrderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}//end insertFirst

template<class Type>
void OrderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}//end insertLast

template<class Type>
void OrderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if (first_ == NULL) //Case 1
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = first_;
		found = false;

		while (current != NULL && !found)  //search the list
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}

		if (current == NULL)   //Case 4
			cout << "The item to be deleted is not in the "
			<< "list." << endl;
		else
			if (current->info == deleteItem) //the item to be 
				//deleted is in the list
			{
				if (first_ == current)       //Case 2
				{
					first_ = first_->link;

					if (first_ == NULL)
						last_ = NULL;

					delete current;
				}
				else                         //Case 3
				{
					trailCurrent->link = current->link;

					if (current == last_)
						last_ = trailCurrent;

					delete current;
				}
				count_--;
			}
			else                            //Case 4
				cout << "The item to be deleted is not in the "
				<< "list." << endl;
	}
}//end deleteNode


#endif