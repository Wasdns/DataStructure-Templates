// leetcode819: most-common-word
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

static vector<string> rawStringProcessor(string s) {
	vector<string> ans;
	int ans_size = 0;

	string element = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (element.size() > 0) {
				ans_size++;
				ans.resize(ans_size);
				ans[ans_size-1] = element;
			}
			element = "";
		} else if (s[i] == '!' || s[i] == '?' || s[i] == '\'' || s[i] == ',' || s[i] == ';' || s[i] == '.') {
			continue;
		} else {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				element += (s[i]+32);
			} else {
				element += s[i];
			}
		}
	}

	if (element != "") {
		ans_size++;
		ans.resize(ans_size);
		ans[ans_size-1] = element;
		element = "";
	}

	return ans;
}

static bool isBanned(string s, vector<string>& banned) {
	vector<string>::iterator iter = find(banned.begin(), banned.end(), s);
	if (iter == banned.end()) {
		return false;
	} else {
		return true;
	}
}

string mostCommonWord(string paragraph, vector<string>& banned) {
	if (paragraph == "") return "";
	
	vector<string> strVector = rawStringProcessor(paragraph);

	int strVector_size = strVector.size();

	map<string, int> strVal;
	map<string, int>::iterator iter;

	string ans = "";
	int mostCommonTimes = 0;

	for (int i = 0; i < strVector_size; i++) {
		string element = strVector[i];

		if (isBanned(element, banned)) continue;

		iter = strVal.find(element);

		int occurredTimes = 0;

		if (iter != strVal.end()) {
			occurredTimes = iter->second;
			occurredTimes++;
			iter->second = occurredTimes;
		} else {
			occurredTimes = 1;
			strVal[element] = 1;
		}

		if (occurredTimes > mostCommonTimes) {
			mostCommonTimes = occurredTimes;
			ans = element;
		}
	}

	return ans;
}

void printAns(string a, vector<string>& banned) {
	cout << mostCommonWord(a,banned) << endl;
}

void test() {
	string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit...";
	vector<string> banned = {"hit"};
	printAns(paragraph,banned);

	paragraph = "Bob";
	banned = {};
	printAns(paragraph,banned);
}

int main() {
	test();
	return 0;
}

