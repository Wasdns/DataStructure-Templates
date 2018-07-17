// leetcode344: reverse-string
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

string reverseString(string s) {
	string ans = "";
	for (int i = s.size()-1; i >= 0; i--) {
		ans += s[i];
	}
	return ans;
}

void printAns(string a) {
	cout << reverseString(a) << endl;
}

void test() {
	string a = "A man, a plan, a canal: Panama";
	string a1 = "race a car";
	printAns(a);
	printAns(a1);
}

int main() {
	test();
	return 0;
}