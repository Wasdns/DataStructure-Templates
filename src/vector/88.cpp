// leetcode88: merge-sorted-array
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int nums1Idx = m;
	for (int i = 0; i < n; i++) {
		// insert this item to the end of nums1
		nums1[nums1Idx] = nums2[i];

		int lIdx = nums1Idx-1;
		int rIdx = nums1Idx;
		while (lIdx > -1) {
			// if left value > right value
			if (nums1[lIdx] > nums1[rIdx]) {
				// swap the two items
				int tmp = 0;
				tmp = nums1[lIdx];
				nums1[lIdx] = nums1[rIdx];
				nums1[rIdx] = tmp;

				// update lIdx and rIdx
				lIdx--;
				rIdx--;
			} else {
				break;
			}
		}

		nums1Idx++;
	}

	// for (int i = 0; i < nums1Idx; i++) {
	// 	cout << nums1[i] << endl;
	// }

	return;
}

void test() {
	int a[10] = {1,2,3,0,0,0};
	int b[10] = {2,5,6};
	vector<int> nums1(a, a+6);
	vector<int> nums2(b, b+3);

	merge(nums1, 3, nums2, 3);
	return;
}

int main() {
	test();
	return 0;
}