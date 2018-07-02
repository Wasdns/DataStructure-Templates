// leetcode20: valid-parentheses
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool isValid(string s) {
	bool res = true;

	stack<string> str_stack;

	for (int i = 0; i < s.size(); i++) {
		stringstream stream;
		stream << s[i];
		string item = stream.str();
		// cout << "item:" << item << endl;

		// if current item is left parentheses, push it to the stack
		if (item == "(" || item == "{" || item == "[") {
			// cout << "push:" << item << endl;
			str_stack.push(item);
		} else if (item == ")" || item == "}" || item == "]") {
			// if the stack is empty, this string is invalid
			if (str_stack.empty()) {
				res = false;
				break;
			} else {
				string stack_top = str_stack.top();
				str_stack.pop();

				// the parentheses at the top of stack matches the current parentheses
				if ((stack_top == "(" && item == ")") ||
				    (stack_top == "[" && item == "]") || 
				    (stack_top == "{" && item == "}")) {
					// cout << "pop:" << stack_top << endl;
					continue;
				} else {
					res = false;
					break;
				}
			}
		}
	}

	// for some cases like: "["
	if (!str_stack.empty()) {
		res = false;
	}

	return res;
}

void test() {
	string str1 = "()";
	string str2 = "()[]{}";
	string str3 = "(]";
	string str4 = "([)]";
	string str5 = "{[]}";

	if (isValid(str1)) {
		cout << str1 << " is true" << endl;
	} else {
		cout << str1 << " is false" << endl;
	}

	if (isValid(str2)) {
		cout << str2 << " is true" << endl;
	} else {
		cout << str2 << " is false" << endl;
	}

	if (isValid(str3)) {
		cout << str3 << " is true" << endl;
	} else {
		cout << str3 << " is false" << endl;
	}

	if (isValid(str4)) {
		cout << str4 << " is true" << endl;
	} else {
		cout << str4 << " is false" << endl;
	}

	if (isValid(str5)) {
		cout << str5 << " is true" << endl;
	} else {
		cout << str5 << " is false" << endl;
	}

	return;
}

int main() {
	test();
	return 0;
}