#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************

//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class LinkedListType. 
//***********************************************************

#include "LinkedListType.h"

using namespace std;

template <class Type>
class UnorderedLinkedList : public LinkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list,
	//    otherwise the value false is returned.

	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first_ points to the new list, newItem is
	//    inserted at the beginning of the list, last_ points to
	//    the last_ node, and count_ is incremented by 1.
	//               

	void insertLast(const Type& newItem);
	//Function to insert newItem at the end of the list.
	//Postcondition: first_ points to the new list, newItem is
	//    inserted at the end of the list, last_ points to the
	//    last_ node, and count_ is incremented by 1.

	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem
	//    is deleted from the list. first_ points to the first_ 
	//    node, last_ points to the last_ node of the updated 
	//    list, and count_ is decremented by 1.

	void deleteAll(const Type& deleteItem);
	//Delete all occurences of a given element

	void deleteSmallest();
	//Find and delete the node with the smallest info
};


template <class Type>
bool UnorderedLinkedList<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;

	current = first_; //set current to point to the first_ 
	//node in the list

	while (current != NULL && !found)    //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
	//the next node
	return found;
}//end search

template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;    //store the new item in the node
	newNode->link = first_;      //insert newNode before first_
	first_ = newNode;            //make first_ point to the
	//actual first_ node
	count_++;                    //increment count_

	if (last_ == NULL)   //if the list was empty, newNode is also 
		//the last_ node in the list
		last_ = newNode;
}//end insertFirst

template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node

	newNode = new nodeType<Type>; //create the new node

	newNode->info = newItem;  //store the new item in the node
	newNode->link = NULL;     //set the link field of newNode
	//to NULL

	if (first_ == NULL)  //if the list is empty, newNode is 
		//both the first_ and last_ node
	{
		first_ = newNode;
		last_ = newNode;
		count_++;        //increment count_
	}
	else    //the list is not empty, insert newNode after last_
	{
		last_->link = newNode; //insert newNode after last_
		last_ = newNode; //make last_ point to the actual 
		//last_ node in the list
		count_++;        //increment count_
	}
}//end insertLast


template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if (first_ == NULL)    //Case 1; the list is empty. 
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (first_->info == deleteItem) //Case 2 
		{
			current = first_;
			first_ = first_->link;
			count_--;
			if (first_ == NULL)    //the list has only one node
				last_ = NULL;
			delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first_;  //set trailCurrent to point
			//to the first_ node
			current = first_->link; //set current to point to 
			//the second node

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while

			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				count_--;

				if (last_ == current)   //node to be deleted 
					//was the last_ node
					last_ = trailCurrent; //update the value 
				//of last_
				delete current;  //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else
	}//end else
}//end deleteNode

template <class Type> 
void UnorderedLinkedList<Type>::deleteAll(const Type& deleteItem) {
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *lastItem; //pointer just before current
	nodeType<Type> *temp;
 	if (first_ == NULL) {
		cout << "The list is empty" << endl;
	} else {
 		lastItem = first_;
		current = first_->link;
	
		while (current != NULL) {
			if (current->info == deleteItem){
				temp = current;
				lastItem->link = current->link;
				current = current->link;
				count_--;
				delete temp;
			} else {
				lastItem = current;
				current = current->link;
			}
				
		}

		if (first_->info == deleteItem) {
			deleteNode(first_->info);
  		}


	}

}//end  deleteAll

template <class Type>
void UnorderedLinkedList<Type>::deleteSmallest() {
	nodeType<Type> *current;
	nodeType<Type> *lastItem;
	nodeType<Type> *smallest;
  	if (first_ == NULL) {
		cout << "The list is empty." << endl;
	}
	else {
		lastItem = first_;
		current = first_->link;
		smallest = first_;
		while (current != NULL) {
			if (smallest->info > current->info) {
				smallest = current;
			}
			lastItem = current;
			current = current->link;
			
		}
		if (smallest != NULL) {
			deleteNode(smallest->info);
		}
	}
} //deleteSmallest

#endif
