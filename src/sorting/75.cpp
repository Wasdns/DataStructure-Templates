// leetcode75: sort-colors
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void sortColors(vector<int>& nums) {
	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) a++;
		else if (nums[i] == 1) b++;
		else if (nums[i] == 2) c++;
	}

	for (int i = 0; i < a; i++) {
		nums[i] = 0;
	}
	for (int i = a; i < a+b; i++) {
		nums[i] = 1;
	}
	for (int i = a+b; i < nums.size(); i++) {
		nums[i] = 2;
	}

	// for (int i = 0; i < nums.size(); i++) {
	// 	cout << nums[i] << " ";
	// }

	return;
}

void test() {
	vector<int> a = {2,0,2,1,1,0};
	sortColors(a);
}

int main() {
	test();
	return 0;
}
