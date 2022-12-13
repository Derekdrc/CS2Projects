//Derek D'Arcy
//12/12/2022
//Code for CS2 Final Exam

#include <iostream>
#include "Header.h"

using namespace std;


int main() {
	string message = "I am about to take my final exam.";
	vector<char> msgVect(message.begin(), message.end());

	Email testEmail(msgVect, "12/12/2022", "8:31pm", "ddarcy@ltu.edu", "reciever@ltu.edu", "Final Exam");

	cout << testEmail.getComposedMessage("FileName.txt") << endl;

	string appendedMessage = "Hopefully the final exam went well.";
	vector<char> appVct(appendedMessage.begin(), appendedMessage.end());

	testEmail.appendToMessage(appVct);

	cout << testEmail.getComposedMessage("FileName.txt") << endl;

	return 0;
}