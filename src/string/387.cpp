// leetcode387: first-unique-character-in-a-string
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

int firstUniqChar(string s) {
	int ans = -1;
	if (s == "") return ans;

	map<char,int> strVal;
	map<char,int>::iterator itor;
	
	for (int i = 0; i < s.size(); i++) {
		itor = strVal.find(s[i]);
		if (itor == strVal.end()) {
			strVal[s[i]] = 1;
		} else {
			itor->second += 1;
		}
	}

	for (int i = 0; i < s.size(); i++) {
		itor = strVal.find(s[i]);
		if (itor->second == 1) {
			ans = i;
			break;
		}
	}

	return ans;
}

void printAns(string a) {
	cout << firstUniqChar(a) << endl;
}

void test() {
	string a = "leetcode";
	printAns(a);

	a = "loveleetcode";
	printAns(a);
}

int main() {
	test();
	return 0;
}
