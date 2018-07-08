// leetcode144: binary-tree-preorder-traversal
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

void printAns(vector<int> ans) {
	cout << "=====The Answer=====" << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	} cout << endl;
	cout << "====================" << endl;
}

bool isTail(TreeNode* root) {
	bool ans = false;
	if (root->left == NULL && root->right == NULL) {
		ans = true;
	}
	return ans;
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	int ans_size = 0;

	if (root == NULL) {
		return ans;
	} else if (isTail(root)) {
		ans_size++;
		ans.resize(ans_size);
		ans[0] = root->val;
	} else {
		// record the root node in the ans
		ans_size++;
		ans.resize(ans_size);
		ans[0] = root->val;

		// get the preorder of left tree
		vector<int> l_ans = preorderTraversal(root->left);
		int l_ans_size = l_ans.size();

		// get the preorder of right tree
		vector<int> r_ans = preorderTraversal(root->right);
		int r_ans_size = r_ans.size();

		ans_size = ans_size+l_ans_size+r_ans_size;
		ans.resize(ans_size);

		// integrate the l_ans and r_ans to the ans
		for (int i = 1; i < l_ans_size+1; i++) {
			ans[i] = l_ans[i-1];
		}
		for (int i = l_ans_size+1; i < ans_size; i++) {
			ans[i] = r_ans[i-l_ans_size-1];
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

// createSampleTree2: create the sample tree:
// 
//     1
//    / \
//   3   2
//  /     \
// 5       6

TreeNode* createSampleTree2() {
	TreeNode* root = new TreeNode(1);
	TreeNode* root_left = new TreeNode(3);
	TreeNode* root_right = new TreeNode(2);
	TreeNode* root_left_left = new TreeNode(5);
	TreeNode* root_right_right = new TreeNode(6);

	root_left->left = root_left_left;
	root_right->right = root_right_right;
	root->left = root_left;
	root->right = root_right;
	return root;
}

// createSampleTree3: create the sample tree:
// 
//         1
//        / 
//       2 
//      / 
//     3 
//    /
//   4
//  /
// 5

TreeNode* createSampleTree3() {
	TreeNode* root = new TreeNode(1);
	TreeNode* root_l = new TreeNode(2);
	TreeNode* root_l_l = new TreeNode(3);
	TreeNode* root_l_l_l = new TreeNode(4);
	TreeNode* root_l_l_l_l = new TreeNode(5);

	root_l_l_l->left = root_l_l_l_l;
	root_l_l->left = root_l_l_l;
	root_l->left = root_l_l;
	root->left = root_l;
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
	TreeNode* root;
	vector<int> ans;

	cout << "Sample Tree1:" << endl;
	root = createSampleTree1();
	printTree(root);
	ans = preorderTraversal(root);
	printAns(ans);

	cout << "Sample Tree2:" << endl;
	root = createSampleTree2();
	printTree(root);
	ans = preorderTraversal(root);
	printAns(ans);

	cout << "Sample Tree3:" << endl;
	root = createSampleTree3();
	printTree(root);
	ans = preorderTraversal(root);
	printAns(ans);

	return;
}

int main() {
	test();
	return 0;
}
