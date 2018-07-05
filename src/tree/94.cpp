// leetcode94: binary-tree-inorder-traversal
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

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	int ans_size = 0;
	int ans_index = 0;
	ans.resize(ans_size);

	if (root == NULL) {
		return ans;
	}

	stack<TreeNode*> s;

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
		// so we record the top of the stack in the vector ans
		if (!s.empty()) {
			TreeNode* s_top = s.top();
			s.pop();

			// record the current value to ans
			ans_size++;
			ans.resize(ans_size);
			ans[ans_index] = s_top->val;
			ans_index++;

			// now we turn to visit the right tree
			p = s_top->right;
		}
	}

	return ans;
}


// the following codes are used to implement tests

// createSampleTree: create the sample tree:
// 
//   3
//  / \
// 9  20
//   /  \
//  15   7

TreeNode* createSampleTree() {
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

void test() {
	TreeNode* root = createSampleTree();
	printTree(root);

	vector<int> ans;
	ans = inorderTraversal(root);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	} cout << endl;
	
	return;
}

int main() {
	test();
	return 0;
}
