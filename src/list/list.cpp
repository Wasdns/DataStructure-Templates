/* data structure: list */

#include <cstdio>
#include <iostream>
using namespace std;

struct list {
	int entry;
	list* next;
};

list* listInit(int* variables, int size) {
	list* head = NULL;
	list* newp = NULL;
	list* p = NULL;

	p = new list;
	p->entry = variables[0];
	newp = new list;
	p->next = newp;
	head = p;
	p = newp;

	for (int i = 1; i < size; i++) {
		p->entry = variables[i];
		newp = new list;
		if (i == size-1) {
			p->next = NULL;
		} else {
			p->next = newp;
			p = newp;
		}
	}

	return head;
}

bool isListEmpty(list* l) {
	bool flag = true;

	return flag;
}

int listLength(list* l) {
	int length = 0;

	return length;
}

int listItem(list* l, int index) {
	int value = -1;

	return value;
}

int findItem(list* l, int item) {
	int index = -1;

	return index;
}

bool insertItem(list* l, int index) {
	bool insertSuccess = false;

	return insertSuccess;
}

bool deleteItem(list* l, int index) {
	bool deleteSuccess = false;

	return deleteSuccess;
}

void printList(list* l, int size) {
	// help information
	cout << "printList: print the whole list entries" << endl;

	list* p = l;
	while (p != NULL) {
		cout << p->entry << " ";
		p = p->next;
	}
	cout << endl;
	return;
}

void test() {
	int variables[100];

	// for user input
	int size = -1;
	cout << "Enter the list size (less than 100): ";
	cin >> size;
	if (size <= 0 || size > 100) {
		cout << "Error: You have to indicate the list size between 0 and 100!" << endl;
		return;
	}
	cout << "Enter the list entries: ";
	for (int i = 0; i < size; i++) {
		cin >> variables[i];
	}

	// create the list using the input variables
	list* mylist = listInit(variables, size);
	printList(mylist, size);

	return;
}

int main() {
	test();
	return 0;
}
