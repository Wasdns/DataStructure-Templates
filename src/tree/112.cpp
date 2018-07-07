// leetcode112: path-sum
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
	if (root->left == NULL && root->right == NULL) {
		ans = true;
	}
	return ans;
}

bool hasPathSum(TreeNode* root, int sum) {
	bool ans = false;
	if (root == NULL) {
		ans = false;
	} else if (root->left == NULL && root->right == NULL) {
		if (root->val == sum) {
			ans = true;
		}
	} else {
		queue<TreeNode*> nodeq;
		// sumq stores the path sum of each node
		queue<int> sumq;

		nodeq.push(root);
		sumq.push(root->val);

		while (!nodeq.empty()) {
			TreeNode* nodeq_top = nodeq.front();
			int currentPathSum = sumq.front();
			nodeq.pop();
			sumq.pop();

			if (nodeq_top->left != NULL) {
				int l_sumVal = nodeq_top->left->val+currentPathSum;
				if (l_sumVal == sum && isTail(nodeq_top->left)) {
					ans = true;
					break;
				} else {
					nodeq.push(nodeq_top->left);
					sumq.push(l_sumVal);
				}
			}

			if (nodeq_top->right != NULL) {
				int r_sumVal = nodeq_top->right->val+currentPathSum;
				if (r_sumVal == sum && isTail(nodeq_top->right)) {
					ans = true;
					break;
				} else {
					nodeq.push(nodeq_top->right);
					sumq.push(r_sumVal);
				}
			}
		}
	}

	return ans;
}

// the best solution
bool hasPathSum2(TreeNode* root, int sum) {
	if (!root) return false;
	if (!root->left && !root->right) return (sum == root->val);
	return hasPathSum2(root->left, sum - root->val) || hasPathSum2(root->right, sum - root->val);
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
// 5       4

TreeNode* createSampleTree2() {
	TreeNode* root = new TreeNode(1);
	TreeNode* root_left = new TreeNode(3);
	TreeNode* root_right = new TreeNode(2);
	TreeNode* root_left_left = new TreeNode(5);
	TreeNode* root_right_right = new TreeNode(4);

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
	printBool(hasPathSum(root,30));

	root = createSampleTree2();
	printTree(root);
	printBool(hasPathSum(root,7));

	root = createSampleTree3();
	printTree(root);
	printBool(hasPathSum(root,6));

	return;
}

int main() {
	test();
	return 0;
}
