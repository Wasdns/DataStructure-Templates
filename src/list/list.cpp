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
	// cout << "isListEmpty: check if the list is empty (head->next is NULL)" << endl;

	bool flag = true;
	if (l->next != NULL) {
		flag = false;
	}
	return flag;
}

int listLength(list* l) {
	// cout << "listLength: return the length of a given list" << endl;

	if (isListEmpty(l)) {
		cout << "Error: the given list is empty, return -1" << endl;
		return -1;
	}

	int length = 0;
	list* p = l;
	while (p != NULL) {
		p = p->next;
		length++;
	}

	return length;
}

int getItem(list* l, int index) {
	// cout << "listItem: return an item of the list based on a given index" << endl;

	int value = -1;
	int length = listLength(l);
	if (length < index+1) {
		cout << "Error: the index used by listItem is overflowed!" << endl;
	} else {
		list* p = l;
		for (int i = 0; i < index; i++) {
			p = p->next;
		}
		value = p->entry;
	}

	return value;
}

int findItem(list* l, int item) {
	// cout << "findItem: search a given item in the list;" << endl;
	// cout << "if found, return the first index of the item;" << endl;
	// cout << "otherwise, return -1." << endl;

	int index = 0;
	bool foundItem = false;

	list* p = l;
	while (p != NULL) {
		if (p->entry == item) {
			foundItem = true;
			break;
		}
		p = p->next;
		index++;
	}

	if (!foundItem) {
		index = -1;
	}

	return index;
}

bool insertItem(list* l, int index) {
	// cout << "insertItem: insert a given item to the list based on a given index" << endl;

	bool insertSuccess = false;

	int length = listLength(l);
	if (length < index) {
		cout << "Error: the index used by insertItem is overflowed!" << endl;
		return insertSuccess;
	} else {
		// list* p = l;
		// for (int i = 0; i < index; i++) {
		// 	p = p->next;
		// }
		// value = p->entry;
	}

	return insertSuccess;
}

bool deleteItem(list* l, int index) {
	bool deleteSuccess = false;

	return deleteSuccess;
}

void printList(list* l, int size) {
	// cout << "printList: print the whole list entries" << endl;

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
	cout << "mylist:";
	printList(mylist, size);

	int length = listLength(mylist);
	cout << "The length of mylist:" << length << endl;
	cout << "The first item of mylist:" << getItem(mylist, 0) << endl;
	cout << "The last item of mylist:" << getItem(mylist, length-1) << endl;

	cout << "Does 520 exist in mylist?" << endl;
	int index = findItem(mylist, 520);
	if (index == -1) {
		cout << "No, 520 doesn't exist in mylist" << endl;
	} else {
		cout << "Sure, the index of 520 is " << index << endl;
	}

	return;
}

int main() {
	test();
	return 0;
}
