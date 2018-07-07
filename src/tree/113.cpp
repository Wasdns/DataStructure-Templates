// leetcode113: path-sum-ii
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

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ans;
	int ans_size = 0;

	if (root == NULL) {
		return ans;
	} else if (isTail(root)) {
		vector<int> ans_root(1);
		if (root->val == sum) {
			ans_root[0] = root->val;
			ans.resize(1);
			ans[0] = ans_root;
		}
	} else {
		// traverse the tree
		queue<TreeNode*> nodeq;

		// record the path of current node
		queue<vector<int>> pathq;
		// the vector used to initial pathq
		vector<int> path = {root->val};
		
		// record the path sum of current node
		queue<int> sumq;

		nodeq.push(root);
		pathq.push(path);
		sumq.push(root->val);

		while (!nodeq.empty()) {
			TreeNode* currentNode = nodeq.front();
			nodeq.pop();
			vector<int> currentPath = pathq.front();
			pathq.pop();
			int currentSum = sumq.front();
			sumq.pop();

			// if meet the tail node, determine whether the path sum is matched
			if (isTail(currentNode)) {
				if (currentSum == sum) {
					ans_size++;
					ans.resize(ans_size);
					ans[ans_size-1] = currentPath;
				}
			} else {
				int currentPathLength = currentPath.size();
				int newPathLength = currentPathLength+1;

				if (currentNode->left != NULL) {
					// update sumq
					int newSum = currentSum+currentNode->left->val;
					sumq.push(newSum);

					// update pathq
					vector<int> newPath = currentPath;
					newPath.resize(newPathLength);
					// record the new node in the last item of newPath
					newPath[newPathLength-1] = currentNode->left->val;
					pathq.push(newPath);

					// update nodeq
					nodeq.push(currentNode->left);
				}

				if (currentNode->right != NULL) {
					// update sumq
					int newSum = currentSum+currentNode->right->val;
					sumq.push(newSum);

					// update pathq
					vector<int> newPath = currentPath;
					newPath.resize(newPathLength);
					// record the new node in the last item of newPath
					newPath[newPathLength-1] = currentNode->right->val;
					pathq.push(newPath);

					// update nodeq
					nodeq.push(currentNode->right);
				}
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

void printAns(vector<vector<int>> ans) {
	cout << "=====The Answers=====" << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=====================" << endl;
}

void test() {
	TreeNode* root;
	vector<vector<int>> ans;

	cout << "Sample Tree1:" << endl;
	root = createSampleTree1();
	printTree(root);
	ans = pathSum(root, 30);
	printAns(ans);

	cout << "Sample Tree2:" << endl;
	root = createSampleTree2();
	printTree(root);
	ans = pathSum(root, 9);
	printAns(ans);

	cout << "Sample Tree3:" << endl;
	root = createSampleTree3();
	printTree(root);
	ans = pathSum(root, 6);
	printAns(ans);

	return;
}

int main() {
	test();
	return 0;
}
