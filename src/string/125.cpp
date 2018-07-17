// leetcode125: valid-palindrome
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

static string formats(string s) {
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
			ans += s[i];
		} else if (s[i] >= 'A' && s[i] <= 'Z') {
			ans += s[i]+32;
		} else {
			continue;
		}
	}
	return ans;
}

bool isPalindrome(string s) {
	if (s == "") return true;

	bool ans = true;

	string s1 = formats(s);
	int l = 0;
	int r = s1.size()-1;
	while (l <= r) {
		if (s1[l] != s1[r]) {
			ans = false;
			break;
		}
		l++;
		r--;
	}

	return ans;
}

void printAns(string a) {
	if (isPalindrome(a)) {
		cout << "isPalindrome" << endl;
	} else {
		cout << "isnotPalindrome" << endl;
	}
}

void test() {
	string a = "A man, a plan, a canal: Panama";
	string a1 = "race a car";
	printAns(a);
	printAns(a1);
}

int main() {
	test();
	return 0;
}