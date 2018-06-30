// leetcode27: remove-element
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	int size = nums.size();
	int slowIdx = 0;
	for (int i = 0; i < size; i++) {
		if (nums[i] == val) {
			nums[i] = -1;
		} else {
			if (nums[slowIdx] == -1) {
				nums[slowIdx] = nums[i];
				nums[i] = -1;

				// update slowIdx
				while (nums[slowIdx] != -1 && slowIdx < i) {
					slowIdx++;
				}
			} else {
				slowIdx++;
			}
		}
	}

	// for (int i = 0; i < slowIdx; i++) {
	// 	cout << nums[i] << endl;
	// }

	return slowIdx;
}

void test() {
	int a[10] = {0,1,2,2,3,0,4,2};
	vector<int> nums(&a[0], &a[7]);

	int val = 2;
	cout << removeElement(nums, val) << endl;
	return;
}

int main() {
	test();
	return 0;
}