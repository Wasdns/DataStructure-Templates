// leetcode106: construct-binary-tree-from-postorder-and-inorder-traversal
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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	TreeNode* root = NULL;

	if (postorder.size() == 0 || inorder.size() == 0) {
		root = NULL;
	} else if (postorder.size() == 1 || inorder.size() == 1) {
		int val = postorder[0];
		root = new TreeNode(val);
	} else if (postorder.size() == 2 || inorder.size() == 2) {
		int root_val = postorder[1];
		int son_val = postorder[0];
		root = new TreeNode(root_val);
		TreeNode* son = new TreeNode(son_val);

		if (inorder[0] == root_val) {
			root->right = son;
		} else {
			root->left = son;
		}
	} else {
		int postorder_size = postorder.size();
		int root_val = postorder[postorder_size-1];
		root = new TreeNode(root_val);

		// search the root node in the inorder array and return the index
		int root_index_in_inorder = 0;
		for (int i = 0; i < inorder.size(); i++) {
			if (inorder[i] == root_val) {
				root_index_in_inorder = i;
				break;
			}
		}

		// split the inorder array and the postorder array into two sub-arrays (left and right)
		vector<int> l_postorder;
		int l_postorder_len = 0;

		vector<int> l_inorder;
		int l_inorder_len = 0;
		
		vector<int> r_postorder;
		int r_postorder_len = 0;
		
		vector<int> r_inorder;
		int r_inorder_len = 0;

		// get the indexes of these vectors, and use these indexes to acquire vector length
		int l_postorder_l = 0;
		int l_postorder_r = root_index_in_inorder-1;
		l_postorder_len = l_postorder_r-l_postorder_l+1;
		l_postorder.resize(l_postorder_len);

		int r_postorder_l = root_index_in_inorder;
		int r_postorder_r = postorder_size-1-1;
		r_postorder_len = r_postorder_r-r_postorder_l+1;
		r_postorder.resize(r_postorder_len);

		int l_inorder_l = 0;
		int l_inorder_r = root_index_in_inorder-1;
		l_inorder_len = l_inorder_r-l_inorder_l+1;
		l_inorder.resize(l_inorder_len);

		int r_inorder_l = root_index_in_inorder+1;
		int r_inorder_r = inorder.size()-1;
		r_inorder_len = r_inorder_r-r_inorder_l+1;
		r_inorder.resize(r_inorder_len);

		// populate the vectors
		l_postorder.assign(postorder.begin()+l_postorder_l, postorder.begin()+l_postorder_r+1);
		r_postorder.assign(postorder.begin()+r_postorder_l, postorder.begin()+r_postorder_r+1);
		l_inorder.assign(inorder.begin()+l_inorder_l, inorder.begin()+l_inorder_r+1);
		r_inorder.assign(inorder.begin()+r_inorder_l, inorder.begin()+r_inorder_r+1);

		TreeNode* root_left = buildTree(l_inorder, l_postorder);
		TreeNode* root_right = buildTree(r_inorder, r_postorder);
		root->left = root_left;
		root->right = root_right;

		// cout << "l_postorder_l:" << l_postorder_l << endl;
		// cout << "l_postorder_r:" << l_postorder_r << endl;
		// cout << "r_postorder_l:" << r_postorder_l << endl;
		// cout << "r_postorder_r:" << r_postorder_r << endl;

		// cout << "root:" << root_val << endl;
		// cout << "root_left:" << root_left->val << endl;
		// cout << "root_right:" << root_right->val << endl;
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
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	root = buildTree(inorder, postorder);
	printTree(root);

	vector<int> inorder2 = {5,3,1,2,4};
	vector<int> postorder2 = {5,3,4,2,1};
	root = buildTree(inorder2, postorder2);
	printTree(root);

	return;
}

int main() {
	test();
	return 0;
}

