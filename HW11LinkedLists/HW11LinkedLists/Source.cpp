//Derek D'Arcy
//11/7/2022
//create linked list class with print function, copy constructor, reverse function, and search function

#include <iostream>
using namespace std;

struct node {
	double data;
	node* next;
};

class LinkedList {
private:
	node* list;
	int listSize;

public:
	LinkedList();
	LinkedList(LinkedList&);
	~LinkedList();
	void add(double);
	void deleteNode(double);
	void print();
	void reverse();
	int search(double);
};

//default const
LinkedList::LinkedList() {
	list = NULL; 
}

//copy const
LinkedList::LinkedList(LinkedList& temp) {
	list = NULL;
	node* current = temp.list;
	node* tail = NULL;
	while (current) {
		node* newTemp = new node;
		newTemp->data = current->data;
		newTemp->next = NULL;
		if (list == NULL) {
			list = tail = newTemp;
		}
		else {
			tail->next = newTemp;
			tail = newTemp;
		}
		current = current->next;
	}
}

//destructor
LinkedList::~LinkedList() {
	while (list) {
		node* temp = list;
		list = list->next;
		delete(temp);
	}
	list = NULL;
}

//add method
void LinkedList::add(double val) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	if (list == NULL) {
		list = temp;
	}
	else {
		temp->next = list;
		list = temp;
	}
}

//delete method
void LinkedList::deleteNode(double val) {
	if (list == NULL) {
		cout << "List is empty" << endl;
	}
	else if (list->next == NULL) {
		if (list->data == val) {
			node* temp = list;
			list = list->next;
			delete(temp);
		}
	}
	else {
		node* current = list;
		while (current->next) {
			if (current->next->data == val) {
				node* temp = current->next;
				current->next = temp->next;

				delete(temp);
				return;
			}
			current = current->next;
		}
	}
	cout << "Target value to delete was not found." << endl;
}

//print method
void LinkedList::print() {
	node* current = list;
	cout << endl << "Printed List: " << endl;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

//reverse method
void LinkedList::reverse() {
	node* current = list;
	node* previous = NULL;
	node* next = NULL;
	if (list == NULL) {
		cout << "Empty List" << endl;
	}
	else {
		while (current->next != NULL) {
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		current->next = previous;
		list = current;
	}
}

//search method
int LinkedList::search(double key) {
	if (list == NULL) {
		return -1;
	}

	int index = 0;
	node* current = list;
	while (current) {
		if (current->data == key) {
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}


int main() {
	LinkedList testList;

	testList.add(6);
	testList.add(9);
	testList.add(3);
	testList.add(2);
	testList.add(5);
	testList.add(7);
	testList.add(21);

	testList.print();

	LinkedList copy(testList);
	copy.print();

	testList.reverse();
	testList.print();

	cout << "Searching for index of 5: " << testList.search(5) << endl;;
	cout << "Searching for index of 300: " << testList.search(300) << endl;
}