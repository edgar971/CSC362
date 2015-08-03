#ifndef H_arrayListType
#define H_arrayListType


#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class ArrayListType
{
public:

	const ArrayListType<elemType>& operator=
		(const ArrayListType<elemType>&);
	//Overloads the assignment operator
	bool isEmpty() const;
	//Function to determine whether the list_ is empty
	//Postcondition: Returns true if the list_ is empty; 
	//    otherwise, returns false.
	bool isFull() const;
	//Function to determine whether the list_ is full.
	//Postcondition: Returns true if the list_ is full; 
	//    otherwise, returns false.
	int listSize() const;
	//Function to determine the number of elements in the list_
	//Postcondition: Returns the value of length_.
	int maxListSize() const;
	//Function to determine the size of the list_.
	//Postcondition: Returns the value of maxSize_.
	void print() const;
	//Function to output the elements of the list_
	//Postcondition: Elements of the list_ are output on the 
	//   standard output device.
	bool isItemAtEqual(int location, const elemType& item) const;
	//Function to determine whether the item is the same 
	//as the item in the list_ at the position specified by
	//Postcondition: Returns true if the list_[location] 
	//    is the same as the item; otherwise, 
	//               returns false.
	void insertAt(int location, const elemType& insertItem);
	//Function to insert an item in the list_ at the 
	//position specified by location. The item to be inserted 
	//is passed as a parameter to the function.
	//Postcondition: Starting at location, the elements of the
	//    list_ are shifted down, list_[location] = insertItem;,
	//    and length_++;. If the list_ is full or location is
	//    out of range, an appropriate message is displayed.
	void insertEnd(const elemType& insertItem);
	//Function to insert an item at the end of the list_. 
	//The parameter insertItem specifies the item to be inserted.
	//Postcondition: list_[length_] = insertItem; and length_++;
	//    If the list_ is full, an appropriate message is 
	//    displayed.
	void removeAt(int location);
	//Function to remove the item from the list_ at the 
	//position specified by location 
	//Postcondition: The list_ element at list_[location] is removed
	//    and length_ is decremented by 1. If location is out of 
	//    range,an appropriate message is displayed.
	void retrieveAt(int location, elemType& retItem) const;
	//Function to retrieve the element from the list_ at the  
	//position specified by location. 
	//Postcondition: retItem = list_[location] 
	//    If location is out of range, an appropriate message is
	//    displayed.
	void replaceAt(int location, const elemType& repItem);
	//Function to replace the elements in the list_ at the 
	//position specified by location. The item to be replaced 
	//is specified by the parameter repItem.
	//Postcondition: list_[location] = repItem 
	//    If location is out of range, an appropriate message is
	//    displayed.
	void clearList();
	//Function to remove all the elements from the list_. 
	//After this operation, the size of the list_ is zero.
	//Postcondition: length_ = 0;
	int seqSearch(const elemType& item) const;
	//Function to search the list_ for a given item. 
	//Postcondition: If the item is found, returns the location 
	//    in the array where the item is found; otherwise,
	//    returns -1.
	void insert(const elemType& insertItem);
	//Function to insert the item specified by the parameter 
	//insertItem at the end of the list_. However, first the
	//list_ is searched to see whether the item to be inserted 
	//is already in the list_. 
	//Postcondition: list_[length_] = insertItem and length_++
	//     If the item is already in the list_ or the list_
	//     is full, an appropriate message is displayed.
	void remove(const elemType& removeItem);
	//Function to remove an item from the list_. The parameter 
	//removeItem specifies the item to be removed.
	//Postcondition: If removeItem is found in the list_,
	//      it is removed from the list_ and length_ is 
	//      decremented by one.


	ArrayListType(int size = 100);
	//constructor
	//Creates an array of the size specified by the 
	//parameter size. The default array size is 100.
	//Postcondition: The list_ points to the array, length_ = 0, 
	//    and maxSize_ = size

	ArrayListType(const ArrayListType<elemType>& otherList);
	//copy constructor

	~ArrayListType();
	//destructor
	//Deallocates the memory occupied by the array.

	//
	elemType max() const;

protected:
	elemType *list_;  //array to hold the list_ elements
	int length_;      //to store the length_ of the list_
	int maxSize_;     //to store the maximum size of the list_
};

template <class elemType>
bool ArrayListType<elemType>::isEmpty() const
{
	return (length_ == 0);
}

template <class elemType>
bool ArrayListType<elemType>::isFull() const
{
	return (length_ == maxSize_);
}

template <class elemType>
int ArrayListType<elemType>::listSize() const
{
	return length_;
}

template <class elemType>
int ArrayListType<elemType>::maxListSize() const
{
	return maxSize_;
}

template <class elemType>
void ArrayListType<elemType>::print() const
{
	for (int i = 0; i < length_; i++)
		cout << list_[i] << " ";

	cout << endl;
}

template <class elemType>
bool ArrayListType<elemType>::isItemAtEqual
(int location, const elemType& item) const
{
	return (list_[location] == item);
}

template <class elemType>
void ArrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
	if (location < 0 || location >= maxSize_)
		cerr << "The position of the item to be inserted "
		<< "is out of range" << endl;
	else
		if (length_ >= maxSize_)  //list_ is full
			cerr << "Cannot insert in a full list_" << endl;
		else
		{
			for (int i = length_; i > location; i--)
				list_[i] = list_[i - 1];   //move the elements down

			list_[location] = insertItem;  //insert the item at the 
			//specified position

			length_++;     //increment the length_
		}
} //end insertAt

template <class elemType>
void ArrayListType<elemType>::insertEnd(const elemType& insertItem)
{

	if (length_ >= maxSize_)  //the list_ is full
		cerr << "Cannot insert in a full list_" << endl;
	else
	{
		list_[length_] = insertItem;   //insert the item at the end
		length_++;   //increment the length_
	}
} //end insertEnd

template <class elemType>
void ArrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length_)
		cerr << "The location of the item to be removed "
		<< "is out of range" << endl;
	else
	{
		for (int i = location; i < length_ - 1; i++)
			list_[i] = list_[i + 1];

		length_--;
	}
} //end removeAt

template <class elemType>
void ArrayListType<elemType>::retrieveAt
(int location, elemType& retItem) const
{
	if (location < 0 || location >= length_)
		cerr << "The location of the item to be retrieved is "
		<< "out of range." << endl;
	else
		retItem = list_[location];
} //end retrieveAt


template <class elemType>
void ArrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
	if (location < 0 || location >= length_)
		cerr << "The location of the item to be replaced is "
		<< "out of range." << endl;
	else
		list_[location] = repItem;

} //end replaceAt

template <class elemType>
void ArrayListType<elemType>::clearList()
{
	length_ = 0;
} //end clearList


template <class elemType>
int ArrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length_; loc++)
		if (list_[loc] == item)
		{
			found = true;
			break;
		}

	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template <class elemType>
void ArrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;

	if (length_ == 0)   //list_ is empty
		list_[length_++] = insertItem;    //insert the item and 
	//increment the length_
	else if (length_ == maxSize_)
		cerr << "Cannot insert in a full list_." << endl;
	else
	{
		loc = seqSearch(insertItem);

		if (loc == -1)    //the item to be inserted 
			//does not exist in the list_
			list_[length_++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
			<< "the list_. No duplicates are allowed." << endl;
	}
} //end insert

template<class elemType>
void ArrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;

	if (length_ == 0)
		cerr << "Cannot delete from an empty list_." << endl;
	else
	{
		loc = seqSearch(removeItem);

		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list_."
			<< endl;
	}
} //end remove

template <class elemType>
ArrayListType<elemType>::ArrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 100. " << endl;

		maxSize_ = 100;
	}
	else
		maxSize_ = size;

	length_ = 0;

	list_ = new elemType[maxSize_];
	assert(list_ != NULL);
}

template <class elemType>
ArrayListType<elemType>::~ArrayListType()
{
	delete[] list_;
}


template <class elemType>
ArrayListType<elemType>::ArrayListType
(const ArrayListType<elemType>& otherList)
{
	maxSize_ = otherList.maxSize_;
	length_ = otherList.length_;
	list_ = new elemType[maxSize_]; //create the array
	assert(list_ != NULL);         //terminate if unable to allocate
	//memory space

	for (int j = 0; j < length_; j++)  //copy otherList
		list_[j] = otherList.list_[j];
} //end copy constructor

template <class elemType>
const ArrayListType<elemType>& ArrayListType<elemType>::operator=
(const ArrayListType<elemType>& otherList)
{
	if (this != &otherList)   //avoid self-assignment
	{
		delete[] list_;
		maxSize_ = otherList.maxSize_;
		length_ = otherList.length_;

		list_ = new elemType[maxSize_];  //create the array
		assert(list_ != NULL);   //if unable to allocate memory 
		//space, terminate the program 
		for (int i = 0; i < length_; i++)
			list_[i] = otherList.list_[i];
	}

	return *this;
}


template <class elemType>
elemType ArrayListType<elemType>::max() const {
	//set the first item of the array as the max value to start
	elemType max = list_[0];
	//compare all of the other values
	for (int counter = 1; counter < length_; counter++) {
		//if the value in the loop bigger then 
		if (max < list_[counter]) {
			//assign it to max
			max = list_[counter];
		} 
		
	}
		

 	return max;
}



#endif
