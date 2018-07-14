// leetcode242: valid-anagram
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

bool isAnagram(string s, string t) {
	bool ans = true;
	if (s == "" and t == "") {
		ans = true;
	} else if (s == "" or t == "") {
		ans = false;
	} else {
		map<char,int> stringMap;
		map<char,int>::iterator stringMap_itor;

		// turn the strings into C-style strings
		vector<char> cstr1(s.c_str(), s.c_str()+s.size()+1);
		vector<char> cstr2(t.c_str(), t.c_str()+t.size()+1);

		for (int i = 0; i < s.size(); i++) {
			int times = 1;
			stringMap_itor = stringMap.find(cstr1[i]);
			// if this item has been inserted to the stringMap, update the times
			if (stringMap_itor != stringMap.end()) {
				times += stringMap_itor->second;
			} 
			stringMap[cstr1[i]] = times;
		}

		for (int i = 0; i < t.size(); i++) {
			stringMap_itor = stringMap.find(cstr2[i]);

			// if we find this char in stringMap, update the appearance times
			if (stringMap_itor != stringMap.end()) {
				int times = stringMap_itor->second;
				times--;
				if (times < 0) {
					ans = false;
					break;
				} else {
					stringMap_itor->second = times;
				}
			} else {
				ans = false;
				break;
			}
		}

		if (ans) {
			for (int i = 0; i < s.size(); i++) {
				stringMap_itor = stringMap.find(cstr1[i]);
				if (stringMap_itor != stringMap.end()) {
					if (stringMap_itor->second != 0) {
						ans = false;
						break;
					}
				} else {
					ans = false;
					break;
				}
			}
		}
	}
	return ans;
}

void printAns(string a, string b) {
	if (isAnagram(a,b)) {
		cout << "isAnagram" << endl;
	} else {
		cout << "isnotAnagram" << endl;
	}
}

void test() {
	string a = "anagram";
	string b = "nagaram";
	printAns(a,b);

	a = "rat";
	b = "car";
	printAns(a,b);

	a = "aacc";
	b = "ccac";
	printAns(a,b);
}

int main() {
	test();
	return 0;
}