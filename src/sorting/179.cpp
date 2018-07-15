// leetcode179: largest-number
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

// This function is used to determine which number is bigger
// based on the following assumption: if ab < ba, then a < b
static bool sort_cmp(int a, int b) {
	string a_str = to_string(a);
	string b_str = to_string(b);
	return (a_str+b_str) < (b_str+a_str);
}

string largestNumber(vector<int>& nums) {
	string ans = "";

	if (nums.size() == 0) {
		return ans;
	}

	// this flag is used to avoid unavoidable segmentation fault
	bool allTheSame = true;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != nums[0]) {
			allTheSame = false;
			break;
		}
	}

	if (!allTheSame) {
		sort(nums.begin(), nums.end(), sort_cmp);
	} 

	if (allTheSame && nums[0] == 0) {
		ans = to_string(0);
	} else {
		for (int i = nums.size()-1; i >= 0; i--) {
			string element = to_string(nums[i]);
			ans += element;
		}
	}

	return ans;
}

void test() {
	vector<int> a = {10,2};
	vector<int> b = {3,30,34,5,9};
	vector<int> c = {1,2,3,4,5,6,7,8,9,0};
	vector<int> d = {0,0,1};
	vector<int> e = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> f = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector<int> g = {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> h = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	vector<int> i = {62,58,36,59,4,16,82,67,13,41,31,29,53,56,43,96,56,43,46,45,7,65,9,9,96,99,95,84,94,27,69,88,38,25,77,44,38,37,1,94,49,78,4,99,99,22,7,60,37,17,42,48,41,88,57,17,92,1,51,51,82,34,8,3,84,29,23,5,19,1,28,76,32,33,70,94,95,8,72,35,99,50,80,14,11,78,4,38,99,65,11,71,52,68,22,32,1,26,82,28};
	vector<int> j = {0,0};

	cout << largestNumber(a) << endl;
	cout << largestNumber(b) << endl;
	cout << largestNumber(c) << endl;
	cout << largestNumber(d) << endl;
	cout << largestNumber(e) << endl;
	cout << largestNumber(f) << endl;
	cout << largestNumber(g) << endl;
	cout << largestNumber(h) << endl;
	cout << largestNumber(i) << endl;
	cout << largestNumber(j) << endl;
}

int main() {
	test();
	return 0;
}
