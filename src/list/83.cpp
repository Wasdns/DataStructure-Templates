/* leetcode83: remove-duplicates-from-sorted-list */
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int a[100000];

bool isValOccurred(int val, int length) {
	bool ans = false;

	// search the a
	for (int i = 0; i < length; i++) {
		if (a[i] == val) {
			ans = true;
			break;
		}
	}

	// if not found, record this value on the a
	if (!ans && length < 99999) {
		a[length] = val;
	}

	return ans;
}

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode* slow;
	ListNode* mid;
	ListNode* fast;
	slow = head;
	mid = head->next;
	fast = head->next->next;

	// record the first value in the a
	int aLength = 1;
	a[0] = head->val;

	while (fast != NULL) {
		if (isValOccurred(mid->val, aLength)) {
			slow->next = fast;
			mid = fast;
			fast = fast->next;
		} else {
			slow = mid;
			mid = fast;
			fast = fast->next;

			// update the length of a
			aLength++;
		}
	}

	if (isValOccurred(mid->val, aLength)) {
		slow->next = NULL;
	}

	return head;
}

int main() {
	return 0;
}
