// leetcode67: add-binary
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

string addBinary(string a, string b) {
	string ans = "";
	if (a == "" || b == "") {
		if (a == "") {
			ans = b;
		} else {
			ans = a;
		}
	}

	bool carry = false;
	int a_idx = a.size()-1;
	int b_idx = b.size()-1;

	while (a_idx >= 0 && b_idx >= 0) {
		int bitAns = 0;
		
		if (a[a_idx] == '1' && b[b_idx] == '1') {
			if (carry) {
				bitAns = 1;
				carry = true;
			} else {
				bitAns = 0;
				carry = true;
			}
		} else if (a[a_idx] == '0' && b[b_idx] == '0') {
			if (carry) {
				bitAns = 1;
				carry = false;
			} else {
				bitAns = 0;
				carry = false;
			}
		} else if (a[a_idx] == '1' || b[b_idx] == '1') {
			if (carry) {
				bitAns = 0;
				carry = true;
			} else {
				bitAns = 1;
				carry = false;
			}
		}

		ans += to_string(bitAns);

		a_idx--;
		b_idx--;
	}

	if (a_idx >= 0) {
		for (int i = a_idx; i >= 0; i--) {
			int bitAns = 0;
			if (a[i] == '0') {
				if (carry) {
					bitAns = 1;
					carry = false;
				} else {
					bitAns = 0;
					carry = false;
				}
			} else {
				if (carry) {
					bitAns = 0;
					carry = true;
				} else {
					bitAns = 1;
					carry = false;
				}
			}

			ans += to_string(bitAns);
		}
	} else if (b_idx >= 0) {
		for (int i = b_idx; i >= 0; i--) {
			int bitAns = 0;
			if (b[i] == '0') {
				if (carry) {
					bitAns = 1;
					carry = false;
				} else {
					bitAns = 0;
					carry = false;
				}
			} else {
				if (carry) {
					bitAns = 0;
					carry = true;
				} else {
					bitAns = 1;
					carry = false;
				}
			}

			ans += to_string(bitAns);
		}
	} 

	if (carry) {
		ans += to_string(1);
		carry = false;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

void test() {
	string a = "11";
	string a1 = "1";
	string a2 = "1010";
	string a3 = "1011";

	string t1 = "100";
	string t2 = "110010";
	
	cout << addBinary(a,a1) << endl;
	cout << addBinary(a2,a3) << endl;
	cout << addBinary(t1,t2) << endl;
}

int main() {
	test();
	return 0;
}