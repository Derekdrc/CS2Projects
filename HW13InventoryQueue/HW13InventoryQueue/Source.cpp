//Derek D'Arcy
//11/15/2022
//Modify inventory stack to utilize a queue

//The components of a queue are FIFO, or first in first out. 
//This means that the first item put into a queue will be the first item removed from the queue
//A queue is similar to a line at a grocery store
//A Stack is FILO, or first in last out also LIFO, Last in first our
//This means that the last item put into a stack will be the first item removed
//A stack is similar to a stack of books


#include <iostream>
#include <stack>
#include <queue>
#define SIZE 10
using namespace std;

class Inventory {
public:
	int serialNumber, lotNumber;
	string manufactureDate;

	Inventory() {
		serialNumber = NULL;
		manufactureDate = "";
		lotNumber = NULL;
	}

	Inventory(int serial, string date, int lot) {
		serialNumber = serial;
		manufactureDate = date;
		lotNumber = lot;
	}

	//getters
	int getSerialNumber() {
		return serialNumber;
	}

	string getManufactureDate() {
		return manufactureDate;
	}

	int getLotNumber() {
		return lotNumber;
	}

	void print() {
		cout << endl << "Serial Num: " << serialNumber;
		cout << endl << "Manufacturing Date: " << manufactureDate;
		cout << endl << "Lot Num: " << lotNumber;
	}

};
/* class Stack {
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

			cout << endl << "Removed part details:" << endl;
			cout << endl << "Serial Num: " << inventory[rear].serialNumber;
			cout << endl << "Manufacturing Date: " << inventory[rear].manufactureDate;
			cout << endl << "Lot Num: " << inventory[rear].lotNumber;
			rear--;
			cout << endl << endl;
		}
	}
	void printStack() {
		for (int i = 0; i <= rear; i++) {
			cout << "Serial Number: " << inventory[i].serialNumber << endl;
			cout << "Manufacture Date: " << inventory[i].manufactureDate << endl;
			cout << "Lot Number: " << inventory[i].lotNumber << endl << endl;
		}
	}
};*/

int main()
{
	//Stack stack;
	int choice;

	queue <Inventory> inventoryQueue;

	do {
		cout << "Please enter 1 to store a part" << endl;
		cout << "Please enter 2 to remove a part" << endl;
		cout << "Please enter 3 to exit" << endl << endl;
		cout << "Please enter what you would like to do: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int serial, lot;
			string date;
			cout << "Please Enter Serial Number: ";
			cin >> serial;
			cout << "Please Enter Manufacturing Date(MM/DD/YYYY): ";
			cin >> date;
			cout << "Please Enter Lot Number: ";
			cin >> lot;
			cout << endl;
			inventoryQueue.push(Inventory(serial, date, lot));
			break;
		}
		case 2:
		{
			cout << endl << "Removed part details:" << endl;
			cout << endl << "Serial Num: " << inventoryQueue.front().getSerialNumber();
			cout << endl << "Manufacturing Date: " << inventoryQueue.front().getManufactureDate();
			cout << endl << "Lot Num: " << inventoryQueue.front().getLotNumber() << endl << endl;
			inventoryQueue.pop();
			break;
		}
		case 3:
		{
			cout << endl << "Parts still in inventory stack: " << endl << endl;
			while (inventoryQueue.size()) {
				inventoryQueue.front().print();
				inventoryQueue.pop();
			}
			cout << endl << "Exiting";
			break;
		}
		default:
			cout << endl << "That was not a valid choice, please try again." << endl << endl;
		}
	} while (choice != 3);

	return 0;
}