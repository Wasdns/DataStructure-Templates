// leetcode100: same-tree
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

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	} else if (p == NULL || q == NULL) {
		return false;
	} else if (p->val != q->val) {
		return false;
	}

	bool ans = true;
	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
	TreeNode* p_copy = p;
	TreeNode* q_copy = q;

	q1.push(p_copy);
	q2.push(q_copy);

	while (1) {
		if (q1.empty() || q2.empty()) {
			if (!q1.empty() || !q2.empty()) {
				ans = false;
			}
			break;
		}

		TreeNode* q1_top;
		TreeNode* q2_top;

		q1_top = q1.front();
		q2_top = q2.front();
		q1.pop();
		q2.pop();

		if (q1_top->val != q2_top->val) {
			ans = false;
			break;
		} else {
			// push the left node to the queue
			if (q1_top->left != NULL || q2_top->left != NULL) {
				if (q1_top->left == NULL || q2_top->left == NULL) {
					ans = false;
					break;
				} else {
					q1.push(q1_top->left);
					q2.push(q2_top->left);
				}
			}

			// push the right node to the queue
			if (q1_top->right != NULL || q2_top->right != NULL) {
				if (q1_top->right == NULL || q2_top->right == NULL) {
					ans = false;
					break;
				} else {
					q1.push(q1_top->right);
					q2.push(q2_top->right);
				}
			}
		}
	}
	
	return ans;
}

// beautiful solution
bool isSameTree2(TreeNode* p, TreeNode* q) {
	if (p != NULL && q != NULL){
		return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	} else if (p == NULL && q == NULL){
		return true;
	} else {
		return false;
	}
}

void test() {
	
	return;
}

int main() {
	test();
	return 0;
}