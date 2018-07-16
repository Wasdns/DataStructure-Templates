// leetcode58: length-of-last-word
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

int lengthOfLastWord(string s) {
	int ans = 0;

	bool begin = false;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] != ' ') {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				if (!begin) begin = true; 
				ans++;
			} else {
				if (begin) break; 
			}
		} else {
			if (begin) break;
		}
	}

	return ans;
}

void test() {
	string a = " ";
	string a1 = "a aaaa";
	string a2 = " mississippi";
	string a3 = " aabaabbb aabbbbabaaab ";
	
	cout << lengthOfLastWord(a) << endl;
	cout << lengthOfLastWord(a1) << endl;
	cout << lengthOfLastWord(a2) << endl;
	cout << lengthOfLastWord(a3) << endl;
}

int main() {
	test();
	return 0;
}