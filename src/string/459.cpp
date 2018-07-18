// leetcode459: repeated-substring-pattern
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

static bool repeatable(string s, string subStr) {
	bool ans = false;

	int limitation = s.size();
	string smuStr = subStr;
	while (smuStr.size() <= limitation) {
		if (smuStr == s) {
			ans = true;
			break;
		} else {
			smuStr += subStr;
		}
	}

	return ans;
}

bool repeatedSubstringPattern(string s) {
	if (s == "") return true;
	bool ans = false;

	string subStr = "";
	for (int i = 0; i < s.size()/2; i++) {
		subStr += s[i];
		if (repeatable(s, subStr)) {
			ans = true;
			break;
		}
	}

	return ans;
}

void printAns(string a) {
	if (repeatedSubstringPattern(a)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

void test() {
	string a = "";
	a = "abcabcabcabc";
	printAns(a);
	a = "abab";
	printAns(a);
	a = "aba";
	printAns(a);
}

int main() {
	test();
	return 0;
}
