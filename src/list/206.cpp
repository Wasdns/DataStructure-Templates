/* leetcode206: reverseList */
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode* slow;
	ListNode* mid;
	ListNode* fast;
	slow = NULL;
	mid = head;
	fast = head->next;

	while (fast != NULL) {
		mid->next = slow;
		slow = mid;
		mid = fast;
		fast = fast->next;
	}

	mid->next = slow;
	return mid;
}

int main() {
	return 0;
}