// leetcode844: backspace-string-compare
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool backspaceCompare(string S, string T) {
	if (S == "" && T == "") return true;

	bool res = true;

	stack<char> stackS;
	stack<char> stackT;

	// convert the string to char*
	vector<char> S_cstr(S.c_str(), S.c_str()+S.size()+1);
	vector<char> T_cstr(T.c_str(), T.c_str()+T.size()+1);

	// traverse the two strings for populating the stacks
	for (int i = 0; i < S.size(); i++) {
		char item = S_cstr[i];
		if (item == '#') {
			if (!stackS.empty()) {
				stackS.pop();
			}
		} else {
			stackS.push(item);
		}
	}
	for (int i = 0; i < T.size(); i++) {
		char item = T_cstr[i];
		if (item == '#') {
			if (!stackT.empty()) {
				stackT.pop();
			}
		} else {
			stackT.push(item);
		}
	}

	// compare the stack items 
	while (!stackS.empty() && !stackT.empty()) {
		char itemS = stackS.top();
		char itemT = stackT.top();

		// if found difference -> false
		if (itemS != itemT) {
			res = false;
			break;
		} else {
			stackS.pop();
			stackT.pop();
		}
	}

	if (!stackS.empty() || !stackT.empty()) {
		res = false;
	}

	return res;
}

void judge(string s1, string s2) {
	if (backspaceCompare(s1,s2)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return;
}

void test() {
	string a1 = "ab#c";
	string a2 = "ad#c";
	string b1 = "ab##";
	string b2 = "c#d#";
	string c1 = "a##c";
	string c2 = "#a#c";
	string d1 = "a#c";
	string d2 = "b";

	judge(a1,a2);
	judge(b1,b2);
	judge(c1,c2);
	judge(d1,d2);
	
	return;
}

int main() {
	test();
	return 0;
}