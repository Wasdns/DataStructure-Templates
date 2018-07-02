// leetcode496: next-greater-element-i
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// this solution is not good
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	int size = findNums.size();
	vector<int> ans(size);

	stack<int> numsStack;
	for (int i = 0; i < nums.size(); i++) {
		numsStack.push(nums[i]);
	}

	for (int i = 0; i < size; i++) {
		int currentItem = findNums[i];

		// initial two stacks
		// numsStack_copy is used to initial the findStack
		// the findStack stores the items after the current item in numsStack
		stack<int> numsStack_copy = numsStack;
		stack<int> findStack;

		int theGreaterVal = -1;

		// initial the findStack
		while (!numsStack_copy.empty()) {
			int topVal = numsStack_copy.top();

			// push all the items after the current item to the numStack
			if (topVal != currentItem) {
				findStack.push(topVal);
				numsStack_copy.pop();
			} else {
				break;
			}
		}

		// find the item that greater than the current item in the findStack
		while (!findStack.empty()) {
			int topVal = findStack.top();

			// if found, update the greater value and break
			if (topVal > currentItem) {
				theGreaterVal = topVal;
				break;
			} else {
				findStack.pop();
			}
		}

		ans[i] = theGreaterVal;
	}
	return ans;
}

// the following codes are used to test the program

void printVector(vector<int> ans) {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

void test() {
	vector<int> a1 = {4,1,2};
	vector<int> a2 = {1,3,4,2};
	vector<int> b1 = {2,4};
	vector<int> b2 = {1,2,3,4};

	vector<int> ans;
	ans = nextGreaterElement(a1,a2);
	printVector(ans);
	ans = nextGreaterElement(b1,b2);
	printVector(ans);

	return;
}

int main() {
	test();
	return 0;
}