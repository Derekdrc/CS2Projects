//Derek D'Arcy
// 10/10/22

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string fileName;
	cout << "Please enter file name: ";
	cin >> fileName;
	ifstream input;
	input.open(fileName.c_str());
	if (input.is_open()) {
		string currentLine;
		int counter = 0;
		while (getline(input, currentLine)) {
			cout << currentLine << endl;
			counter++;
			if (counter % 24 == 0) {
				counter = 0;
				system("pause");
			}
		}
		input.close();
	}
	else {
		cout << fileName << " does not exist." << endl;
	}
	return 0;
}
