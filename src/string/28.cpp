// leetcode28: implement-strstr
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

int strStr(string haystack, string needle) {
	if (needle == "" || haystack == "") {
		if (needle == "") {
			return 0;
		} else if (haystack == "") {
			return -1;
		}
	}

	int ans = 0;

	int index = 0;
	int needle_len = needle.size();
	bool isHit = false;

	for (int i = 0; i < haystack.size(); i++) {
		for (int j = i; j < haystack.size(); j++) {
			if (haystack[j] == needle[index]) {
				index++;
			} else {
				index = 0;
				if (haystack[j] == needle[index]) {
					index++;
				}
			}

			// if find the needle string
			if (index == needle_len) {
				isHit = true;
				ans = j-needle_len+1;
				break;
			}
		}
		if (isHit) break;
		else index = 0;
	}

	if (!isHit) ans = -1;
	return ans;
}

void test() {
	string a = "hello";
	string b = "ll";

	string a1 = "aaaaa";
	string b1 = "ba";

	string a2 = "mississippi";
	string b2 = "issip";

	string a3 = "aabaabbbaabbbbabaaab";
	string b3 = "abaa";
	
	cout << strStr(a,b) << endl;
	cout << strStr(a1,b1) << endl;
	cout << strStr(a2,b2) << endl;
	cout << strStr(a3,b3) << endl;
}

int main() {
	test();
	return 0;
}
