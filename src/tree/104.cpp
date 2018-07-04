// leetcode104: maximum-depth-of-binary-tree
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
	int depth = 0;

	if (root == NULL) {
		depth = 0;
	} else if (root->left == NULL && root->right == NULL) {
		depth = 1;
	} else {
		int leftTreeDepth = maxDepth(root->left);
		int rightTreeDepth = maxDepth(root->right);
		if (leftTreeDepth > rightTreeDepth) {
			depth = leftTreeDepth+1;
		} else {
			depth = rightTreeDepth+1;
		}
	}

	return depth;
}

// a better solution
int maxDepth1(TreeNode* root) {
	if (root == NULL)
		return 0;
	return 1+max(maxDepth1(root->left), maxDepth1(root->right));
}

void test() {
	
	return;
}

int main() {
	test();
	return 0;
}