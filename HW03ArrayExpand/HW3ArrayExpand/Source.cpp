// Derek D'Arcy
// 9/5/22 for cs2

#include <iostream>
using namespace std;

int* doubleArray(int[], const int);

int main() {
	const int SIZE = 5;
	int numArray[SIZE] = { 1,2,3,4,5 };

	int* numsDouble = doubleArray(numArray, SIZE);

	cout << "Orginal Array: " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << numArray[i] << " ";
	}
	cout << endl << endl;

	cout << "Doubled Array: " << endl;
	for (int i = 0; i < (SIZE*2); i++) {
		cout << numsDouble[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

int* doubleArray(int array[], const int SIZE) {
	const int DOUBLED_SIZE = SIZE * 2;
	int* doubledArray = new int[DOUBLED_SIZE];

	for (int i = 0; i < DOUBLED_SIZE; i++) {
		if (i >= SIZE) {
			*(doubledArray + i) = 0;
		}
		else {
			*(doubledArray + i) = array[i];
		}
	}
	return doubledArray;
}