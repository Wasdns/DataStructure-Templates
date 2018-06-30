/* leetcode234: palindrome-linked-list */
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// This solution refers to https://www.cnblogs.com/HorribleMe/p/4878833.html
// However, it is not true for some specific cases
// e.g., [1,3,0,2]: 1*1+3*2+0*3+2*4 = 2*1+0*2+3*3+1*4
bool isPalindrome1(ListNode* head) {
	bool ans = false;
	if (head == NULL || head->next == NULL) {
		return true;
	}

	// O(1) variable which stores the value sum (the sum of value*factor)
	// The factor is used to indicate the impact of array index.
	// For example, the sum of [1,1,3,1,1] = 1*1 + 1*2 + 3*3 + 1*4 + 1*5 
	int sum = 0, factor = 1;


	// 1.traverse and reverse the given list, initial the sum

	ListNode* slow;
	ListNode* mid;
	ListNode* fast;
	slow = NULL;
	mid = head;
	fast = head->next;

	while (fast != NULL) {
		// update sum based on factor and value
		sum += mid->val*factor;
		factor++;

		// reverse the linked list 
		mid->next = slow;
		slow = mid;
		mid = fast;
		fast = fast->next;
	}

	// process the end of the linked list
	mid->next = slow;
	sum += mid->val*factor;

	cout << "middle sum:" << sum << endl;

	// 2.traverse the reversed linked list, and update the sum

	ListNode* newhead = mid;
	ListNode* newp = newhead;
	int newFactor = 1;

	while (newp != NULL) {
		sum -= newp->val*newFactor;
		cout << "loop, newFactor:" << newFactor << ", sum:" << sum << endl;
		newFactor++;
		newp = newp->next;
	}

	// 3.check if the sum is 0. 
	// If so, we prove that this linked list is palindrome
	if (sum == 0) {
		ans = true;
	}

	return ans;
}


// This solution refers to: https://www.cnblogs.com/grandyang/p/4635425.html
// This solution leverages two pointers: 
// fast (fast = fast->next->next) and slow (slow = slow->next).
//
// First, it finds the middle node of the given linked list by
// traversing the linked list using the fast and slow pointers.
// Meanwhile, it populates the values of the nodes that visited
// by the slow pointer to a stack. 
//
// Second, it compares the value of the node after the middle
// node with the value of the top node of the stack, in order to
// determine if the linked list is palindrome.
bool isPalindrome(ListNode* head) {
	bool ans = true;
	if (head == NULL || head->next == NULL) {
		return ans;
	}

	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* afterMid = head;
	stack<int> s;

	// First, traverse the linked list and find the middle node
	while (fast != NULL && fast->next != NULL) {
		s.push(slow->val);
		// cout << "push:" << slow->val << endl;
		slow = slow->next;
		fast = fast->next->next;
	}
	// if the fast pointer is not NULL, the slow pointer points to the middle node
	// so the afterMid pointer should point to the node after the middle node
	if (fast != NULL) {
		afterMid = slow->next;
	} else {
		afterMid = slow;
	}

	// Second, comparing the node value with the value of the node at the top of stack
	int stackTopVal = -1;
	while (afterMid != NULL) {
		stackTopVal = s.top();
		s.pop();
		// cout << "pop:" << stackTopVal << endl;
		if (stackTopVal != afterMid->val) {
			ans = false;
			break;
		}
		afterMid = afterMid->next;
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

void test() {
	int var[10] = {1,2,3,2,1};
	int size = 5;

	ListNode* head = NULL;
	head = listInit(var,size);
	if (isPalindrome(head)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

int main() {
	test();
	return 0;
}