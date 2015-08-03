#ifndef H_Orderedlist_Type
#define H_Orderedlist_Type

#include <iostream>
#include "ArrayListType.h"

using namespace std;

template<class elemType>
class OrderedArrayListType : public ArrayListType<elemType>
{
public:
	void insertOrd(const elemType&);

	int binarySearch(const elemType& item) const;

	OrderedArrayListType(int size = 100);
	int seqOrdSearch(const elemType& item) const;

};


template <class elemType>
void OrderedArrayListType<elemType>::insertOrd(const elemType& item)
{
	int first = 0;
	int last = length_ - 1;
	int mid;

	bool found = false;

	if (length_ == 0)   //the list_ is empty
	{
		list_[0] = item;
		length_++;
	}
	else if (length_ == maxSize_)
		cerr << "Cannot insert into a full list_." << endl;
	else
	{
		while (first <= last && !found)
		{
			mid = (first + last) / 2;

			if (list_[mid] == item)
				found = true;
			else if (list_[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}//end while

		if (found)
			cerr << "The insert item is already in the list_. "
			<< "Duplicates are not allowed." << endl;
		else
		{
			if (list_[mid] < item)
				mid++;

			insertAt(mid, item);
		}
	}
}//end insertOrd

template<class elemType>
int OrderedArrayListType<elemType>::binarySearch(const elemType& item) const
{
	int first = 0;
	int last = length_ - 1;
	int mid;
	int notFound = -1;
	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;

		if (list_[mid] == item)
			found = true;
		else if (list_[mid] > item)
			last = mid - 1;
		else
			first = mid + 1;
	}

	if (found)
		return mid;
	else
		return notFound;
}//end binarySearch

template<class elemType>
OrderedArrayListType<elemType>::OrderedArrayListType(int size)
	: ArrayListType<elemType>(size)
{
}

template<class elemType>
int OrderedArrayListType<elemType>::seqOrdSearch(const elemType& item) const {
	int notFound = -1;
	bool found = false;
	
	int first = 0;
	int current = 0;
	bool search = true;
	int last = length_ - 1;
	//if the list is not empty
	if (length_ != 0) {

		if ((item < list_[first]) || (item > list_[last])) {
			found = false;
			
		}
		else {
			while (!found) {
				if (item == list_[current]) {
					found = true;					
				}
				else {
					current++;
				}
			}
		}
	}
	else {
		found = false;

	}

	if (found) {
		return current + 1;
	}
	else {
		return notFound;
	}
	
}

#endif

