//Searchable Vector Class

#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H
#include "SortableVector.h"
#include <algorithm>
#include <iostream>

template <class T>
class SearchableVector : public SortableVector <T>{
public:
	SearchableVector(int i) : SortableVector<T>(i) 
	{}
	SearchableVector(SortableVector<T>& obj) : SortableVector<T>(obj)
	{}

	int searchAndSort(T);
};


// For binary Search
template <class T>
int SearchableVector<T>::searchAndSort(T item) {
	//Sort Vector
	this->sort();

	//binary search
	int start = 0;
	int end = this->size() - 1;
	int middle;

	while (start <= end) {
		middle = (start + end) / 2;
		if (this->operator[](middle) == item) {
			return middle;
		} else if (this->operator[](middle) > item) {
			end = middle - 1;
		} else {
			start = middle + 1;
		}
	}
	return -1;
}

#endif