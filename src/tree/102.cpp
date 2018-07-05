// leetcode102: binary-tree-level-order-traversal
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

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	int ans_size = 0;
	ans.resize(ans_size);
	int ans_index = 0;

	if (root == NULL) {
		return ans;
	}

	queue<TreeNode*> q;
	q.push(root);

	// layerNumber: record the item number of a layer 
	int layerNumber = 1;
	// sonNumber: record the item number of the underlaying layer, for example:
	// the sonNumber in the second layer of the sample tree is 2 (two nodes in the third layer)
	int sonNumber = 0;
	// compared_tmp: the variable used to compare its value with the layerNumber
	int compared_tmp = 0;

	// the vector used to store the items in a layer
	vector<int> layerVector;
	int layerVector_size = layerNumber;
	layerVector.resize(layerVector_size);
	int layerVector_index = 0;

	while (!q.empty()) {
		TreeNode* q_top = q.front();
		q.pop();

		// record this node value in the layer vector
		layerVector[layerVector_index] = q_top->val;
		layerVector_index++;

		// populate the sons of current node to the queue
		if (q_top->left != NULL) {
			q.push(q_top->left);
			sonNumber++;
		}
		if (q_top->right != NULL) {
			q.push(q_top->right);
			sonNumber++;
		}

		compared_tmp++;

		// If this procedure have reached the tail node in the current layer,
		if (compared_tmp >= layerNumber) {
			// updates the layerNumber with the value of sonNumber
			layerNumber = sonNumber;

			// resets sonNumber, compared_tmp
			sonNumber = 0;
			compared_tmp = 0;

			// records the node values stored in layerVector
			ans_size++;
			ans.resize(ans_size);
			ans[ans_index] = layerVector;
			ans_index++;

			// cleanup the layerVector and resize it with the new size 
			// (which equals to the value of layerNumber)
			layerVector.clear();
			layerVector_size = layerNumber;
			layerVector.resize(layerVector_size);
			layerVector_index = 0;
		}
	}

	// codes for debugging

	// for (int i = 0; i < ans_index; i++) {
	// 	for (int j = 0; j < ans[i].size(); j++) {
	// 		cout << ans[i][j] << " ";
	// 	} cout << endl;
	// }

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

	vector<vector<int>> ans;
	ans = levelOrder(root);

	TreeNode* root2 = NULL;
	ans = levelOrder(root2);
	
	return;
}

int main() {
	test();
	return 0;
}

