/* leetcode141: singly-linked list */
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
	if (head == NULL) return false;
	if (head->next == NULL) return false;
	if (head->next->next == NULL) return false;

	bool listHasCycle = false;
	ListNode *slow(0), *fast(0);
	slow = head;
	fast = head->next->next;
	
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (fast != NULL) {
			if (fast->val == slow->val) {
				listHasCycle = true;
				break;
			}
		}
	}

	return listHasCycle;
}

void test() {
	
}

int main() {
	test();
	return 0;
}