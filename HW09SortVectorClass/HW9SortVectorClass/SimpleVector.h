// Simple Vector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>			//bad_alloc
#include<cstdlib>		//exit
using namespace std;

template <class T>
class SimpleVector {
private:
	T* aptr;			//point to allocated array
	int arraySize;		//num elements in array
	void memError();	//mem allocation errors
	void subError();	//subcripts out of range

public:
	//default constructor
	SimpleVector() {
		aptr = 0; arraySize = 0;
	}

	//const declaration
	SimpleVector(int);

	//copy const decleration
	SimpleVector(const SimpleVector&);

	//Destructor decleration
	~SimpleVector();

	//Accessor to return array size
	int size() const {
		return arraySize;
	}

	//Accessor to return specific element
	T getElementAt(int position);

	//Overloaded [] operator decleration
	T &operator[](int);
};

//*******************************************************
//Constructor for SimpleVector class. Sets size of the array and allocates memory for it.
//*******************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s) {
	arraySize = s;
	//allocate memory for the array
	try {
		aptr = new T[s];
	}
	catch (bad_alloc) {
		memError();
	}

	//Initialize array
	for (int count = 0; count < arraySize; count++) {
		*(aptr + count) = 0;
	}
}

//******************************
//Copy Constructor for SimpleVector class
//******************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj) {
	// Copy the array size
	arraySize = obj.arraySize;

	//Allocate memory for the array
	aptr = new T[arraySize];
	if (aptr == 0) {
		memError();
	}

	//Copy elements of objs array
	for (int count = 0; count < arraySize; count++) {
		*(aptr + count) = *(obj.aptr + count);
	}
}

//**********************************
//Destructor for SimpleVector class
//**********************************

template <class T>
SimpleVector<T>::~SimpleVector() {
	if (arraySize > 0) {
		delete[] aptr;
	}
}

//**************************************************
//memError function, displays err msg and terminates program when memory allocation fails
//***************************************************

template <class T>
void SimpleVector<T>::memError() {
	cout << "Error: Cannot allocate memory. \n";
	exit(EXIT_FAILURE);
}

//**************************************************
//subError function, displays error and terminates program when subscript is out of range
//***************************************************

template <class T>
void SimpleVector<T>::subError() {
	cout << "Error: Subscript out of range. \n";
	exit(EXIT_FAILURE);
}

//***************************************************
//getElementAt function, The arg is a subscript, this funct returns value stored at the subscript in the array
//**************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub) {
	if (sub < 0 || sub >= arraySize) {
		subError();
	}
	return aptr[sub];
}

//***************************************************
//Overloaded [] operator. The argument is a subscript. This func returns reference to the element in the array indexed by subscript
//*************************************************

template <class T>
T &SimpleVector<T>::operator[](int sub) {
	if (sub < 0 || sub >= arraySize) {
		subError();
	}
	return aptr[sub];
}

#endif 