//Derek D'Arcy
//Created 9/9/22 for CS2

#include <iostream>
#include <string>
using namespace std;

void reverseString(string);


int main() {
	string userInput;

	cout << "Please enter the string you would like to reverse: " << endl;
	getline(cin, userInput);

	cout << "Your string reversed is: " << endl;
	reverseString(userInput);
	cout << endl << endl;

	system("pause");
	return 0;
}

void reverseString(string startString) {
	if (startString.size() == 0) {
		return;
	}

	reverseString(startString.substr(1));
	cout << startString[0];
}
