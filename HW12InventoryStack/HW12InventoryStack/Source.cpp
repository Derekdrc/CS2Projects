//Derek D'Arcy
//11/15/2022
//Create inventory stack

#include <iostream>
#include <stack>
#define SIZE 10
using namespace std;

class Inventory {
public:
	int serialNumber, lotNumber;
	string manufactureDate;
};
class Stack {
	Inventory inventory[SIZE];
	int rear;
public:
	Stack()
	{
		rear = -1;
	}
	void push()
	{
		if (rear >= SIZE)
		{
			cout << "Stack is full" << endl;
		}
		else
		{
			rear++;
			cout << "Please Enter Serial Number: ";
			cin >> inventory[rear].serialNumber;
			cout << "Please Enter Manufacturing Date(MM/DD/YYYY): ";
			cin >> inventory[rear].manufactureDate;
			cout << "Please Enter Lot Number: ";
			cin >> inventory[rear].lotNumber;
			cout << endl;
		}
	}
	void pop()
	{
		if (rear < 0)
		{
			cout << "Stack is empty" << endl;
		}
		else
		{

			cout << endl <<"Removed part details:" << endl;
			cout << endl << "Serial Num: " << inventory[rear].serialNumber;
			cout << endl << "Manufacturing Date: " << inventory[rear].manufactureDate;
			cout << endl << "Lot Num: " << inventory[rear].lotNumber;
			rear--;
			cout << endl;
		}
	}
	void printStack() {
		for (int i = 0; i <= rear; i++) {
			cout << "Serial Number: " << inventory[i].serialNumber << endl;
			cout << "Manufacture Date: " << inventory[i].manufactureDate << endl;
			cout << "Lot Number: " << inventory[i].lotNumber << endl << endl;
		}
	}
};
int main()
{
	Stack stack;
	int choice;

	do {
		cout << "Please enter 1 to store a part" << endl;
		cout << "Please enter 2 to remove a part" << endl;
		cout << "Please enter 3 to exit" << endl << endl;
		cout << "Please enter what you would like to do: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			stack.push();
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			cout << endl << "Parts still in inventory stack: " << endl << endl;
			stack.printStack();
			cout << endl << "Exiting";
			break;
		default:
			cout << endl << "That was not aa valid choice, please try again." << endl << endl;
		}
	} while (choice != 3);

	return 0;
}