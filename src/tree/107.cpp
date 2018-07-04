// leetcode107: binary-tree-level-order-traversal-ii
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> ans(10000);

	// for processing some specific cases
	if (root == NULL) {
		ans.assign(ans.begin(), ans.begin());
		return ans;
	} else if (root->left == NULL && root->right == NULL) {
		vector<int> ans0(1);
		ans0[0] = root->val;
		ans[0] = ans0;
		ans.assign(ans.begin(), ans.begin()+1);
	}

	queue<TreeNode*> q;

	// the vector used to store the traverse result
	vector<int> result(10000);
	int result_index = 0;

	// the vector used to store the item number of a layer
	vector<int> layerNumArray(10000);
	int layerNumArray_index = 0;

	// layerNumber: record the item number of a layer 
	int layerNumber = 1;
	// sonNumber: record the item number of the underlaying layer, for example:
	// the sonNumber in the second layer of the sample tree is 2 (two nodes in the third layer)
	int sonNumber = 0;
	// compared_tmp: the variable used to compare its value with the layerNumber
	int compared_tmp = 0;

	q.push(root);

	while (!q.empty()) {
		TreeNode* q_top = q.front();
		q.pop();

		compared_tmp++;
		result[result_index] = q_top->val;
		result_index++;

		// right item first-in
		if (q_top->right != NULL) {
			sonNumber++;
			q.push(q_top->right);
		}
		if (q_top->left != NULL) {
			sonNumber++;
			q.push(q_top->left);
		}

		// If compared_tmp indicates that we have reached the last item in the current layer,
		// we record the item number of this layer in layerNumArray and reset compared_tmp.
		// Moreover, we use the value of sonNumber to reset the layerNumber, and reset sonNumber.
		if (compared_tmp >= layerNumber) {
			// reset compared_tmp
			compared_tmp = 0;

			// record the item number
			layerNumArray[layerNumArray_index] = layerNumber;
			layerNumArray_index++;

			// update the layerNumber and reset sonNumber
			layerNumber = sonNumber;
			sonNumber = 0;
		}
	}


	// codes for debugging

	// cout << "result[i]:" << endl;
	// for (int i = 0; i < result_index; i++) {
	// 	cout << result[i] << " ";
	// } cout << endl;

	// cout << "layerNumArray[i]:" << endl;
	// for (int i = 0; i < layerNumArray_index; i++) {
	// 	cout << layerNumArray[i] << " ";
	// } cout << endl;


	// Finally, converting the results into vector matrix

	// The pointer "resultp" used to point to the item in result array.
	// I initial it with the index of the last item of result array.
	int resultp = result_index-1;

	int ans_index = 0;

	// for each layer
	for (int i = layerNumArray_index-1; i >= 0; i--) {
		// this layer has "itemNum" items
		int itemNum = layerNumArray[i];

		vector<int> layerVector(itemNum);
		int layerVector_index = 0;

		// for "itemNum" times, record "itemNum" items in the layerVector
		for (int j = 0; j < itemNum; j++) {
			layerVector[layerVector_index] = result[resultp];
			layerVector_index++;
			resultp--;
		}

		// insert the layerVector to the answer
		ans[ans_index] = layerVector;
		ans_index++;
	}

	// erase unuseful items
	ans.assign(ans.begin(), ans.begin()+ans_index);

	// // codes for debugging

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
	ans = levelOrderBottom(root);

	TreeNode* root2 = NULL;
	ans = levelOrderBottom(root2);
	
	return;
}

int main() {
	test();
	return 0;
}

