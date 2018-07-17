// leetcode520: detect-capital
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

bool detectCapitalUse(string word) {
	if (word == "") return true;
	bool ans = true;

	// this flag represents the upper/lower case of the first character of the string
	// for example, if flag == 1 then the first character is lower case.
	int flag = 0;
	if (word[0] >= 'a' && word[0] <= 'z') flag = 1;

	// judge the remaining string

	// firstOne = 0: the first character is upper case
	// firstOne = 1: the first character is lower case
	int firstOne = 0;

	for (int i = 1; i < word.size(); i++) {
		if (i == 1) {
			if (word[i] >= 'a' && word[i] <= 'z') {
				firstOne = 1;
			} else if (word[i] >= 'A' && word[i] <= 'Z') {
				if (flag == 1) {
					ans = false;
					break;
				} 
			}
		} else {
			if (word[i] >= 'A' && word[i] <= 'Z' && firstOne == 0) {
				continue;
			} else if (word[i] >= 'a' && word[i] <= 'z' && firstOne == 1) {
				continue;
			} else {
				ans = false;
				break;
			}
		}
	}

	return ans;
}

void printAns(string a) {
	if (detectCapitalUse(a)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

void test() {
	string a = "USA";
	string a1 = "FlaG";
	string a2 = "flag";
	string a3 = "Flag";
	printAns(a);
	printAns(a1);
	printAns(a2);
	printAns(a3);
}

int main() {
	test();
	return 0;
}