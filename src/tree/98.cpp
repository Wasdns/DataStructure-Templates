// leetcode98: validate-binary-search-tree
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

bool isValidBST(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	bool ans = true;

	stack<TreeNode*> s;

	// initial the left value with magic number
	int l_val = -1;
	// if this node is the leftBottom node,
	// initial the the left value
	bool isFirstNode = true;

	// the tree traversal is determined by this pointer
	TreeNode* p = root;

	// using DFS to implement in-order tree traversal
	while (p != NULL || !s.empty()) {
		// if p is not NULL, constantly push its left sons to the stack
		while (p != NULL) {
			s.push(p);
			p = p->left;
		}

		// here my procedure have reached the end of the left tree
		if (!s.empty()) {
			TreeNode* s_top = s.top();
			s.pop();

			// if this node is the leftBottom node,
			// initial the the left value
			if (isFirstNode) {
				isFirstNode = false;
				l_val = s_top->val;
			} else {
				// comparing the current value with the left value
				if (s_top->val <= l_val) {
					ans = false;
					break;
				} else {
					l_val = s_top->val;
				}
			}

			// now we turn to visit the right tree
			p = s_top->right;
		}
	}

	return ans;
}


// the following codes are used to implement tests

// createSampleTree1: create the sample tree1:
// 
//   3
//  / \
// 9  20
//   /  \
//  15   7

TreeNode* createSampleTree1() {
	TreeNode* root = new TreeNode(3);
	TreeNode* root_left = new TreeNode(9);
	TreeNode* root_right = new TreeNode(20);
	TreeNode* root_right_left = new TreeNode(15);
	TreeNode* root_right_right = new TreeNode(7);

	root_right->left = root_right_left;
	root_right->right = root_right_right;
	root->left = root_left;
	root->right = root_right;
	return root;
}

// createSampleTree2: create the sample tree1:
// 
//   3
//  / \
// 1  20
//   /  \
//  7   30

TreeNode* createSampleTree2() {
	TreeNode* root = new TreeNode(3);
	TreeNode* root_left = new TreeNode(1);
	TreeNode* root_right = new TreeNode(20);
	TreeNode* root_right_left = new TreeNode(7);
	TreeNode* root_right_right = new TreeNode(30);

	root_right->left = root_right_left;
	root_right->right = root_right_right;
	root->left = root_left;
	root->right = root_right;
	return root;
}

void printTree(TreeNode* root) {
	if (root == NULL) return;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* q_top = q.front();
		q.pop();
		
		cout << q_top->val << " ";

		if (q_top->left != NULL) {
			q.push(q_top->left);
		}
		if (q_top->right != NULL) {
			q.push(q_top->right);
		}
	}
	cout << endl;
}

void printBool(bool ans) {
	if (ans) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

void test() {
	TreeNode* root;

	root = createSampleTree1();
	printTree(root);
	printBool(isValidBST(root));

	root = createSampleTree2();
	printTree(root);
	printBool(isValidBST(root));

	root = new TreeNode(-2147483648);
	printTree(root);
	printBool(isValidBST(root));

	return;
}

int main() {
	test();
	return 0;
}

