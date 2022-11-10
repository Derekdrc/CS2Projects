//Derek D'Arcy
//10/19/22

#include <iostream>
#include "SimpleVector.h"
#include "SortableVector.h"
#include "SearchableVector.h"
using namespace std;

int main() {
	cout << "For demonstration of #10 (sortable vector without search) press 1," << endl << 
		"For demonstration of #11 (vector search and sort) press 2: ";
	int userInput = 0; 
	cin >> userInput;
	while (userInput != 1 && userInput != 2) {
		cout << "Invalid input, try again." << endl;
		cout << "For demonstration of #10 (sortable vector without search) press 1," << endl << 
			"For demonstration of #11 (vector search and sort) press 2: ";
		cin >> userInput;
	}

	if (userInput == 1) {
		//Question 10, sort without search
		const int SIZE = 5;
		SortableVector<int> intVector(SIZE);
		SortableVector<double> doubleVector(SIZE);

		int intArray[SIZE] = { 12, 9, 17, 4, 2 };
		double doubleArray[SIZE] = { 12.1, 9.8, 17.5, 4.4, 2.0 };

		//Put array values in the vectors
		for (int i = 0; i < SIZE; i++) {
			intVector[i] = intArray[i];
			doubleVector[i] = doubleArray[i];
		}

		//print int vector
		cout << "These are the values in the int vector:" << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << intVector[i] << " ";
		}
		cout << endl;

		//print double vector
		cout << "These are the values in the double vector: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << doubleVector[i] << " ";
		}
		cout << endl;

		//sort both vectors
		intVector.sort();
		doubleVector.sort();

		//print sorted int vector
		cout << "These are the values in the sorted int vector: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << intVector[i] << " ";
		}
		cout << endl;

		//print sorted double vector
		cout << "These are the values in the sorted double vector: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << doubleVector[i] << " ";
		}
		cout << endl;

		system("pause");
		return 0;
	}
	else if (userInput == 2) {
		// Question 11, Search and sort
		const int SIZE = 5;
		SearchableVector<int> intVector(SIZE);
		SearchableVector<double> doubleVector(SIZE);

		int intArray[SIZE] = { 12, 9, 17, 4, 2 };
		double doubleArray[SIZE] = { 12.1, 9.8, 17.5, 4.4, 2.0 };

		//Put array values in the vectors
		for (int i = 0; i < SIZE; i++) {
			intVector[i] = intArray[i];
			doubleVector[i] = doubleArray[i];
		}

		//print int vector
		cout << "These are the values in the int vector:" << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << intVector[i] << " ";
		}
		cout << endl;

		//Run sort and search for user requested integer
		int userSearchInt = 0;
		cout << "What number would you like to search the vector for? ";
		cin >> userSearchInt;
		int intResult = intVector.searchAndSort(userSearchInt);
		if (intResult == -1) {
			cout << "Number was not found in the vector." << endl;
		}
		else {
			cout << "Vector was sorted, and number was found at subscript: " << intResult << endl;
		}

		//print sorted int vector
		cout << "These are the values in the sorted int vector: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << intVector[i] << " ";
		}
		cout << endl;

		//print double vector
		cout << "These are the values in the double vector: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << doubleVector[i] << " ";
		}
		cout << endl;

		//Run sort and search for user requested double
		double userSearchDouble = 0;
		cout << "What number would you like to search the vector for? ";
		cin >> userSearchDouble;
		int doubleResult = doubleVector.searchAndSort(userSearchDouble);
		if (doubleResult == -1) {
			cout << "Number was not found in the vector." << endl;
		}
		else {
			cout << "Vector was sorted, and number was found at subscript: " << doubleResult << endl;
		}

		//print sorted double vector
		cout << "These are the values in the sorted double vector: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << doubleVector[i] << " ";
		}
		cout << endl;

		system("pause");
		return 0;
	}
}
