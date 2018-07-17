// leetcode345: reverse-vowels-of-a-string
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

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	} else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
		return true;
	} else {
		return false;
	}
}

string reverseVowels(string s) {
	if (s == "") return s;
	int l = 0;
	int r = s.size()-1;
	while (l <= r) {
		if (!isVowel(s[l])) {
			l++;
			continue;
		}
		if (!isVowel(s[r])) {
			r--;
			continue;
		}

		string tmp = "";
		tmp += s[l];
		s[l] = s[r];
		s[r] = tmp[0];

		l++;
		r--;
	}
	return s;
}

void printAns(string a) {
	cout << reverseVowels(a) << endl;
}

void test() {
	string a = "hello";
	string a1 = "leetcode";
	printAns(a);
	printAns(a1);
}

int main() {
	test();
	return 0;
}