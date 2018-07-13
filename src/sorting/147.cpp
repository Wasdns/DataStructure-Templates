// leetcode147: insertion-sort-list
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
	ListNode* ans = head;

	if (head == NULL || head->next == NULL) {
		ans = head;
	} else {
		stack<ListNode*> mains;
		stack<ListNode*> backs;

		mains.push(head);

		ListNode* p = head->next;

		while (p != NULL) {
			int currentVal = p->val;
			ListNode* nextp = p->next;

			int sTopVal = mains.top()->val;
			
			while (sTopVal > currentVal) {
				backs.push(mains.top());
				mains.pop();

				if (mains.empty()) break; 
				sTopVal = mains.top()->val;
			}

			if (!backs.empty()) {
				if (mains.empty()) {
					p->next = backs.top();
					ans = p;
				} else {
					mains.top()->next = p;
					p->next = backs.top();
				}

				mains.push(p);
				p = nextp;

				while (!backs.empty()) {
					mains.push(backs.top());
					backs.pop();
				}

				mains.top()->next = nextp;
			} else {
				mains.push(p);
				p = nextp;
			}
		}
	}

	return ans;
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

void printList(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	} cout << endl;
}

void test() {
	ListNode* head = NULL;
	ListNode* ans = NULL;

	int var[10] = {4,2,1,3};
	int size = 4;

	int var2[10] = {-1,5,3,4,0};
	int size2 = 5;

	head = listInit(var,size);
	printList(head);
	ans = insertionSortList(head);
	printList(ans);

	head = listInit(var2,size2);
	printList(head);
	ans = insertionSortList(head);
	printList(ans);
}

int main() {
	test();
	return 0;
}