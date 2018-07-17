// leetcode680: valid-palindrome-ii
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

static bool isPalindrome(string s, int l, int r) {
	if (s == "") return true;
	bool ans = true;
	while (l <= r) {
		if (s[l] != s[r]) {
			ans = false;
			break;
		}
		l++;
		r--;
	}

	return ans;
}

bool validPalindrome(string s) {
	bool ans = true;
	if (s == "") ans = true;
	else {
		int l = 0;
		int r = s.size()-1;
		while (l <= r) {
			if (s[l] != s[r]) {
				ans = (isPalindrome(s,l,r-1) || isPalindrome(s,l+1,r));
				break;
			} else {
				l++;
				r--;
			}
		}
	}

	return ans;
}

void printAns(string a) {
	if (validPalindrome(a)) {
		cout << "t" << endl;
	} else {
		cout << "f" << endl;
	}
}

void test() {
	string a = "aba";
	string a1 = "abca";
	string a2 = "abc";
	string a3 = "deeee";
	printAns(a);
	printAns(a1);
	printAns(a2);
	printAns(a3);
}

int main() {
	test();
	return 0;
}