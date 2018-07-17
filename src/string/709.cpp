// leetcode709: to-lower-case
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

string toLowerCase(string str) {
	string ans = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			ans += (str[i]+32);
		} else {
			ans += str[i];
		}
	}
	return ans;
}

void printAns(string a) {
	cout << toLowerCase(a) << endl;
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