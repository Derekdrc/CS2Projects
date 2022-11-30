//Derek D'Arcy
//11/29/22
//CS2 Binary Tree for Employee Class

#include <string>
#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	EmployeeInfo infoTree[8];
	binaryTree* biTree = new binaryTree();

	infoTree[0].employeeId = 1021;
	infoTree[0].employeeName = "John Williams";
	infoTree[1].employeeId = 1057;
	infoTree[1].employeeName = "Bill witherspoon";
	infoTree[2].employeeId = 2487;
	infoTree[2].employeeName = "Jennifer Twain";
	infoTree[3].employeeId = 3769;
	infoTree[3].employeeName = "Sophia Lancaster";
	infoTree[4].employeeId = 1017;
	infoTree[4].employeeName = "Debbie Reece";
	infoTree[5].employeeId = 1275;
	infoTree[5].employeeName = "George McMullan";
	infoTree[6].employeeId = 1899;
	infoTree[6].employeeName = "Ashley Smith";
	infoTree[7].employeeId = 4218;
	infoTree[7].employeeName = "Josh Plemmons";

	for (int i = 0; i < 8; i++) {
		biTree->insert(infoTree[i]);
	}
	bool run = true;

	while (run) {

		int employeeId;
		cout << "Please enter an ID number: ";
		cin >> employeeId;

		if (biTree->search(employeeId) == NULL) {
			cout << employeeId << " ID not found " << endl;
		}
		else {
			cout << employeeId << " ID found. " << endl << "Employee name is: " << (biTree->search(employeeId))->info.employeeName << endl;
		}

		char response;
		cout << "Would you like to search again? ('y' for yes, 'n' to end program): ";
		cin >> response;
		if (response == 'n') {
			cout << "Goodbye" << endl;
			run = false;
		}
		else if (response == 'y') {
			run = true;
		}
		else {
			cout << "That was not a valid response. Please enter 'y' to continue searching or 'n' to end program. " << endl;
			cin >> response;
			if (response != 'y') {
				cout << "Still an invalid response. Goodbye. " << endl;
				break;
			}
		}
	}

	system("pause");
	return 0;
}