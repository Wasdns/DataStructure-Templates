// leetcode105: construct-binary-tree-from-preorder-and-inorder-traversal
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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	TreeNode* root = NULL;

	if (preorder.size() == 0 || inorder.size() == 0) {
		root = NULL;
	} else if (preorder.size() == 1 || inorder.size() == 1) {
		int val = preorder[0];
		root = new TreeNode(val);
	} else if (preorder.size() == 2 || inorder.size() == 2) {
		int root_val = preorder[0];
		int son_val = preorder[1];
		root = new TreeNode(root_val);
		TreeNode* son = new TreeNode(son_val);

		if (inorder[0] == root_val) {
			root->right = son;
		} else {
			root->left = son;
		}
	} else {
		int root_val = preorder[0];
		root = new TreeNode(root_val);

		// search the root node in the inorder array and return the index
		int root_index_in_inorder = 0;
		for (int i = 0; i < inorder.size(); i++) {
			if (inorder[i] == root_val) {
				root_index_in_inorder = i;
				break;
			}
		}

		// split the inorder array and the preorder array into two sub-arrays (left and right)
		vector<int> l_preorder;
		int l_preorder_len = 0;

		vector<int> l_inorder;
		int l_inorder_len = 0;
		
		vector<int> r_preorder;
		int r_preorder_len = 0;
		
		vector<int> r_inorder;
		int r_inorder_len = 0;

		// get the indexes of these vectors, and use these indexes to acquire vector length
		int l_preorder_l = 1;
		int l_preorder_r = 1+root_index_in_inorder-1;
		l_preorder_len = l_preorder_r-l_preorder_l+1;
		l_preorder.resize(l_preorder_len);

		int r_preorder_l = 1+root_index_in_inorder;
		int r_preorder_r = preorder.size()-1;
		r_preorder_len = r_preorder_r-r_preorder_l+1;
		r_preorder.resize(r_preorder_len);

		int l_inorder_l = 0;
		int l_inorder_r = root_index_in_inorder-1;
		l_inorder_len = l_inorder_r-l_inorder_l+1;
		l_inorder.resize(l_inorder_len);

		int r_inorder_l = root_index_in_inorder+1;
		int r_inorder_r = inorder.size()-1;
		r_inorder_len = r_inorder_r-r_inorder_l+1;
		r_inorder.resize(r_inorder_len);

		// populate the vectors
		l_preorder.assign(preorder.begin()+l_preorder_l, preorder.begin()+l_preorder_r+1);
		r_preorder.assign(preorder.begin()+r_preorder_l, preorder.begin()+r_preorder_r+1);
		l_inorder.assign(inorder.begin()+l_inorder_l, inorder.begin()+l_inorder_r+1);
		r_inorder.assign(inorder.begin()+r_inorder_l, inorder.begin()+r_inorder_r+1);

		TreeNode* root_left = buildTree(l_preorder, l_inorder);
		TreeNode* root_right = buildTree(r_preorder, r_inorder);
		root->left = root_left;
		root->right = root_right;
	}

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
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	root = buildTree(preorder, inorder);
	printTree(root);

	vector<int> preorder2 = {1,3,5,2,4};
	vector<int> inorder2 = {5,3,1,2,4};
	root = buildTree(preorder2, inorder2);
	printTree(root);

	return;
}

int main() {
	test();
	return 0;
}

