/* leetcode160: remove-duplicates-from-sorted-list */
#include <cstdio>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int a[100000];
int b[100000];

// this function returns the reversed index of merged node
// in the example given by leetcode, the reversed index is 3 (c3->c2->c1)
int findSame(int aLength, int bLength) {
	int index = 0;
	int aIdx = aLength-1;
	int bIdx = bLength-1;

	while (aIdx >= 0 && bIdx >= 0 && a[aIdx] == b[bIdx]) {
		aIdx--;
		bIdx--;
		index++;
	}

	return index;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}

	ListNode* ans = NULL;
	ListNode* tmp = headA;
	ListNode* pa = headA;
	ListNode* pb = headB;
	int aLength = 0;
	int bLength = 0;
	
	while (pa != NULL) {
		a[aLength] = pa->val;
		aLength++;
		pa = pa->next;
	}

	while (pb != NULL) {
		b[bLength] = pb->val;
		bLength++;
		pb = pb->next;
	}

	int reversedIdx = findSame(aLength, bLength);
	if (reversedIdx == 0) {
		ans = NULL;
	} else {
		for (int i = 0; i < aLength-reversedIdx; i++) {
			tmp = tmp->next;
		}
		ans = tmp;
	}

	return ans;
}

int main() {
	return 0;
}