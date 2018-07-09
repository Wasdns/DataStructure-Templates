// leetcode515: find-largest-value-in-each-tree-row
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

bool isTail(TreeNode* root) {
	bool ans = false;
    if (root == NULL) {
        return ans;
    } else if (root->left == NULL && root->right == NULL) {
		ans = true;
	}
	return ans;
}

vector<int> largestValues(TreeNode* root) {
	vector<int> ans;
	int ans_size = 0;

	if (root == NULL) {
		return ans;
	} else if (isTail(root)) {
		ans_size++;
		ans.resize(ans_size);
		ans[0] = root->val;
		return ans;
	} else {
		queue<TreeNode*> nodeq;
		nodeq.push(root);

		int layerNumber = 1;
		int sonNumber = 0;
		int temp = 0;

		bool isInitialed = false;
		int maxNum = 0;

		while (!nodeq.empty()) {
			TreeNode* currentNode = nodeq.front();
			nodeq.pop();

			temp++;

			// update the maximum number in this layer
			if (!isInitialed) {
				// record the value in maxNum
				maxNum = currentNode->val;
				ans_size++;
				ans.resize(ans_size);
				ans[ans_size-1] = maxNum;

				// mark isInitialed as true
				isInitialed = true;
			} else if (currentNode->val > maxNum) {
				maxNum = currentNode->val;
				ans[ans_size-1] = maxNum;
			}

			if (currentNode->left != NULL) {
				sonNumber++;
				nodeq.push(currentNode->left);
			}
			if (currentNode->right != NULL) {
				sonNumber++;
				nodeq.push(currentNode->right);
			}

			// in this case, we have reached the end of this layer
			if (temp >= layerNumber) {
				// reset all temporary variables
				temp = 0;
				layerNumber = sonNumber;
				sonNumber = 0;

				// reset isInitialed
				isInitialed = false;
			}
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

void printAns(vector<int> ans) {
	cout << "=====The Answer=====" << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	} cout << endl;
	cout << "====================" << endl;
}

void test() {
	TreeNode* root1;
	TreeNode* root2;
	TreeNode* root3;
	vector<int> ans;

	root1 = createSampleTree1();
	root2 = createSampleTree2();
	root3 = createSampleTree3();

	cout << "Tree1:" << endl;
	ans = largestValues(root1);
	printAns(ans);

	cout << "Tree2:" << endl;
	ans = largestValues(root2);
	printAns(ans);

	cout << "Tree3:" << endl;
	ans = largestValues(root3);
	printAns(ans);

	return;
}

int main() {
	test();
	return 0;
}

