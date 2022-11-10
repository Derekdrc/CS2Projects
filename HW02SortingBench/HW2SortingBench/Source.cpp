//Derek D'Arcy
//created 9/5/22 for CS2

#include <iostream>
using namespace std;

int bubbleSort(int*, int);
int selectionSort(int*, int);
void swap(int &, int &);



int main() {
	int bubbleArray[] = { 1,3,2,5,4,7,6,8,10,11,45,63,0,55,17,29,34,67,98,65};
	int selectionArray[] = { 1,3,2,5,4,7,6,8,10,11,45,63,0,55,17,29,34,67,98,65};
	int size = 20; 

	cout << "Unsorted integer array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << bubbleArray[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Number of swaps for bubbleSort: ";
	cout << bubbleSort(bubbleArray, size) << endl;
	cout << "Array Sorted by bubble sort: " << endl;
	for (int i = 0; i < size; i++) {
		cout << bubbleArray[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Number of swaps for selectionSort: ";
	cout << selectionSort(selectionArray, size) << endl;
	cout << "Array Sorted by Selection sort: " << endl;
	for (int i = 0; i < size; i++) {
		cout << selectionArray[i] << " ";
	}
	cout << endl;
	cout << endl;

}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int bubbleSort(int* array, int size) {
	int count = 0;
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				count++;
			}
		}
	}
	return count;
}

int selectionSort(int* array, int size) {
	int minIndex;
	int count = 0;

	for (int i = 0; i < size - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(array[minIndex], array[i]);
			count++;
		}
	}
	return count;
}