/* leetcode2: add-two-numbers */
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head;
	ListNode* beforeHead;
	beforeHead = new ListNode(0);
	ListNode* newp = beforeHead;

	ListNode* p1 = l1;
	ListNode* p2 = l2;
	int carryBit = 0;
	int base = 0;

	// First, update the common sequence. 

	while (p1 != NULL && p2 != NULL) {
		ListNode* newNode;
		newNode = new ListNode(0);

		// calculate the node value
		int twoNumSum = p1->val+p2->val+carryBit;
		if (twoNumSum >= 10) {
			base = twoNumSum%10;
			carryBit = 1;
		} else {
			base = twoNumSum;
			carryBit = 0;
		}
		newNode->val = base;

		// update the new linked list
		newp->next = newNode;
		newp = newp->next;

		// move the pointers
		p1 = p1->next;
		p2 = p2->next;
	}

	// Second, determine whether the two sequences have the same length.
	// If so, check the carryBit to determine whether to add a new final node.
	// Otherwise, using the following nodes of the longest sequence as the tail nodes.
	if (p1 == NULL && p2 == NULL) {
		// if carryBit is not 0, add a new node in the end 
		if (carryBit == 1) {
			ListNode* finalNode;
			finalNode = new ListNode(1);
			newp->next = finalNode;
		} else {
			newp->next = NULL;
		}
	} else if (p1 == NULL || p2 == NULL) {
		ListNode* finalp; 
		if (p1 == NULL) {
			finalp = p2;
		} else {
			finalp = p1;
		}

		newp->next = finalp;

		// if carryBit is not 0, add 1
		if (carryBit == 1) {
			while (finalp->next != NULL && carryBit == 1) {
				finalp->val += 1;
				if (finalp->val >= 10) {
					finalp->val %= 10;
					carryBit = 1;
				} else {
					carryBit = 0;
				}
				finalp = finalp->next;
			}

			// handle the final node
			if (carryBit == 1 && finalp->next == NULL) {
				finalp->val += 1;

				if (finalp->val >= 10) {
					finalp->val %= 10;
				
					ListNode* finalNode;
					finalNode = new ListNode(1);
					finalp->next = finalNode;	
				}
			}
		}
	}

	head = beforeHead->next;

	return head;
}


/* remaining codes are used for tests */

ListNode* listInit(int* variables, int size) {
	ListNode* head = NULL;
	ListNode* newp = NULL;
	ListNode* p = NULL;

	p = new ListNode(0);
	p->val = variables[0];
	newp = new ListNode(0);
	p->next = newp;
	head = p;
	p = newp;

	for (int i = 1; i < size; i++) {
		p->val = variables[i];
		newp = new ListNode(0);
		if (i == size-1) {
			p->next = NULL;
		} else {
			p->next = newp;
			p = newp;
		}
	}

	return head;
}

void printList(ListNode* l) {
	ListNode* p = l;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return;
}

void test() {
	int var1[10] = {1};
	int var2[10] = {9,9};
	int size1 = 1;
	int size2 = 2;

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	head1 = listInit(var1,size1);
	head2 = listInit(var2,size2);
	
	ListNode* newHead = addTwoNumbers(head1, head2);
	printList(newHead);
}

int main() {
	test();
	return 0;
}