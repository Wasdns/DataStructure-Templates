// leetcode150: evaluate-reverse-polish-notation
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int calculator(int a, int b, string ops) {
	int res = 0;
	if (ops == "+") {
		res = a+b;
	} else if (ops == "-") {
		res = a-b;
	} else if (ops == "*") {
		res = a*b;
	} else if (ops == "/") {
		res = a/b;
	}
	return res;
}

int evalRPN(vector<string>& tokens) {
	int res = 0;

	stack<int> val_stack;

	for (int i = 0; i < tokens.size(); i++) {
		string item = tokens[i];

		// if current item indicates an operator
		if (item == "+" || item == "-" || item == "*" || item == "/") {
			int value2 = 0, value1 = 0;

			// get the second value
			if (val_stack.empty()) {
				cout << "Error: the stack is empty!" << endl;
				return -1;
			} else {
				value2 = val_stack.top();
				val_stack.pop();
			}

			// get the first value
			if (val_stack.empty()) {
				cout << "Error: the stack is empty!" << endl;
				return -1;
			} else {
				value1 = val_stack.top();
				val_stack.pop();
			}

			int tmp = calculator(value1, value2, item);
			val_stack.push(tmp);
		} else {
			// here we transform the string into int value
			int item_int = atoi(item.c_str());
			val_stack.push(item_int);
		}
	}

	res = val_stack.top();
	val_stack.pop();
	if (!val_stack.empty()) {
		cout << "Error: the stack is not empty!" << endl;
		return -1;
	}

	return res;
}


// the following codes are used to test the program

void printVector(vector<string> notation) {
	for (int i = 0; i < notation.size(); i++) {
		cout << notation[i] << " ";
	}
	cout << endl;
}

void test() {
	vector<string> str1 = {"2", "1", "+", "3", "*"};
	vector<string> str2 = {"4", "13", "5", "/", "+"};
	vector<string> str3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	printVector(str1);
	cout << evalRPN(str1) << endl;
	printVector(str2);
	cout << evalRPN(str2) << endl;
	printVector(str3);
	cout << evalRPN(str3) << endl;

	return;
}

int main() {
	test();
	return 0;
}