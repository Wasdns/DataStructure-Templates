/* leetcode203: remove-linked-list-elements */
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
	ListNode* newList = head;
	ListNode* fastp = NULL;
	ListNode* slowp = NULL;

	if (head == NULL) {
		return newList;
	} else if (head->next == NULL) {
		if (head->val == val) {
			newList = NULL;
		}
	} else {
		// ensure the start node's value is not the given value
		while (newList != NULL) {
			if (newList->val != val) break;
			newList = newList->next;
		}

		if (newList == NULL || newList->next == NULL) {
			return newList;
		}

		fastp = newList->next;
		slowp = newList;

		while (fastp != NULL) {
			// if the value of the node which is pointed by fastp is the given value
			// remove this node by updating pointers
			if (fastp->val == val) {
				fastp = fastp->next;
				slowp->next = fastp;
			}

			// if meets the end of this linked list
			if (fastp == NULL) { 
				break;
			} else {
				// if the fastp meets the value immediately, skip to next operation.
				// e.g., [1,2,2,1] 2
				if (fastp->val == val) {
					continue;
				} else { // otherwise, update the fastp and slowp
					fastp = fastp->next;
					slowp = slowp->next;
				}
			}
		}
	}

	return newList;
}

int main() {
	return 0;
}