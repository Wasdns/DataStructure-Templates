// leetcode434: number-of-segments-in-a-string
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

int countSegments(string s) {
	int ans = 0;
	if (s == "") return ans; 

	bool isElement = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (isElement) {
				ans++;
				isElement = false;
			}
		} else {
			isElement = true;
		}
	}

	if (isElement) ans++;

	return ans;
}

void printAns(string a) {
	cout << countSegments(a) << endl;
}

void test() {
	string a = "Hello, my name is John";
	printAns(a);

	a = "loveleetcode";
	printAns(a);
}

int main() {
	test();
	return 0;
}
