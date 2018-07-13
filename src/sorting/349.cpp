// leetcode349: intersection-of-two-arrays
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	int ans_size = 0;
	set<int> ansSet1;
	set<int> ansSet2;

	for (int i = 0; i < nums1.size(); i++) {
		int nums1_item = nums1[i];
		// if not found, insert this item to the set
		if (ansSet1.find(nums1_item) == ansSet1.end()) {
			ansSet1.insert(nums1_item);
		}
	}

	for (int i = 0; i < nums2.size(); i++) {
		int nums2_item = nums2[i];
		// if not found, insert this item to the set
		if (ansSet2.find(nums2_item) == ansSet2.end()) {
			ansSet2.insert(nums2_item);
		}
	}

	set<int>::iterator iter = ansSet2.begin();

	for (int i = 0; i < ansSet2.size(); i++) {
		int element = *iter;
		iter++;
		// if found, insert this item to the set
		if (ansSet1.find(element) != ansSet1.end()) {
			ans_size++;
			ans.resize(ans_size);
			ans[ans_size-1] = element;
		}
	}

	// for (int i = 0; i < ans.size(); i++) {
	// 	cout << ans[i] << " ";
	// } cout << endl;

	return ans;
}

void test() {
	int a[10] = {2,1};
	int b[10] = {1,2};
	vector<int> nums1(a, a+2);
	vector<int> nums2(b, b+2);
	vector<int> ans = intersection(nums1, nums2);
}

int main() {
	test();
	return 0;
}