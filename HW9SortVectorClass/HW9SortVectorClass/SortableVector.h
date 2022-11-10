//Sortable Vector class template

#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H
#include "SimpleVector.h"
#include <algorithm>
#include <iostream>

template <class T>
class SortableVector : public SimpleVector <T>{
public:
	SortableVector(int i) : SimpleVector<T>(i) 
	{}
	SortableVector(SimpleVector<T> &obj) : SimpleVector<T>(obj)
	{}
	void sort();
};

template <class T>
void SortableVector<T>::sort() {
	bool Swap;
	do {
		Swap = false;
		for (int i = 0; i < (this->size() - 1); i++) {
			if (this->operator[](i) > this->operator[](i + 1)) {
				swap(this->operator[](i), this->operator[](i + 1));
				Swap = true;
			}
		}
	} while (Swap);
}



#endif