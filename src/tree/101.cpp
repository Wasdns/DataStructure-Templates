// leetcode101: symmetric-tree
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

bool isSymmetric(TreeNode* root) {
	if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
		return true;
	} else if (root->left == NULL || root->right == NULL) {
		return false;
	}

	queue<TreeNode*> q_left;
	queue<TreeNode*> q_right;
	q_left.push(root->left);
	q_right.push(root->right);
	
	bool ans = true;

	while (!q_left.empty() && !q_right.empty()) {
		TreeNode* q_left_top = q_left.front();
		TreeNode* q_right_top = q_right.front();

		// check if the two items are Symmetric
		if (q_left_top->val != q_right_top->val) {
			ans = false;
			break;
		}

		q_left.pop();
		q_right.pop();

		// push new items to the queues:
		// left son-tree: left son first 
		// right son-tree: right son first

		if (q_left_top->left == NULL) {
			if (q_right_top->right != NULL) {
				ans = false;
				break;
			}
		} else {
			if (q_right_top->right == NULL) {
				ans	= false;
				break;
			} else {
				q_left.push(q_left_top->left);
				q_right.push(q_right_top->right);
			}
		}

		if (q_left_top->right == NULL) {
			if (q_right_top->left != NULL) {
				ans = false;
				break;
			}
		} else {
			if (q_right_top->left == NULL) {
				ans = false;
				break;
			} else {
				q_left.push(q_left_top->right);
				q_right.push(q_right_top->left);
			}
		}
	}

	if (!q_left.empty() || !q_right.empty()) {
		ans = false;
	}

	return ans;
}

void test() {
	
	return;
}

int main() {
	test();
	return 0;
}