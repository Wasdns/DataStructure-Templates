// leetcode617: merge-two-binary-trees
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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	TreeNode* ans = NULL;

	if (t1 == NULL || t2 == NULL) {
		if (t1 == NULL && t2 == NULL) {
			ans = NULL;
		} else if (t1 == NULL) {
			ans = t2;
		} else if (t2 == NULL) {
			ans = t1;
		}
	} else if (isTail(t1) || isTail(t2)) {
		if (isTail(t1)) {
			t2->val += t1->val;
			ans = t2;
		} else {
			t1->val += t2->val;
			ans = t1;
		}
	} else { // we have ensured that the two roots are not tail nodes in this case
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(t1);
		q2.push(t2);

		// merge t2 to t1
		while (!q1.empty()) {
			TreeNode* q1_top = q1.front();
			q1.pop();
			TreeNode* q2_top = q2.front();
			q2.pop();

			q1_top->val += q2_top->val;

			if (q1_top->left == NULL || q2_top->left == NULL) {
				if (q1_top->left == NULL && q2_top->left == NULL) {
					// do nothing
				} else if (q1_top->left == NULL) {
					q1_top->left = q2_top->left;
				} else if (q2_top->left == NULL) {
					// do nothing
				}
			} else if (isTail(q1_top->left) || isTail(q2_top->left)) {
				if (isTail(q1_top->left) && isTail(q2_top->left)) {
					q1_top->left->val += q2_top->left->val;
				} else if (isTail(q1_top->left)) {
					q2_top->left->val += q1_top->left->val;
					q1_top->left = q2_top->left;
				} else if (isTail(q2_top->left)) {
					q1_top->left->val += q2_top->left->val;
				}
			} else {
				q1.push(q1_top->left);
				q2.push(q2_top->left);
			}

			if (q1_top->right == NULL || q2_top->right == NULL) {
				if (q1_top->right == NULL && q2_top->right == NULL) {
					// do nothing
				} else if (q1_top->right == NULL) {
					q1_top->right = q2_top->right;
				} else if (q2_top->right == NULL) {
					// do nothing
				}
			} else if (isTail(q1_top->right) || isTail(q2_top->right)) {
				if (isTail(q1_top->right) && isTail(q2_top->right)) {
					q1_top->right->val += q2_top->right->val;
				} else if (isTail(q1_top->right)) {
					q2_top->right->val += q1_top->right->val;
					q1_top->right = q2_top->right;
				} else if (isTail(q2_top->right)) {
					q1_top->right->val += q2_top->right->val;
				}
			} else {
				q1.push(q1_top->right);
				q2.push(q2_top->right);
			}
		}

		ans = t1;
	}

	return ans;
}

// a better solution
TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
	if (t1 == nullptr) {
		if (t2 != nullptr) {
			t1 = t2;
		}
		return t1;
	} else {
		if (t2 != nullptr) { 
			t1->val += t2->val;
		} else return t1;
	}
	t1->left = mergeTrees2(t1->left, t2->left);
	t1->right = mergeTrees2(t1->right, t2->right);
	return t1;
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
	TreeNode* root1;
	TreeNode* root2;
	vector<int> ans;

	root1 = createSampleTree1();
	root2 = createSampleTree2();
	
	TreeNode* t12;

	cout << "Merge trees:" << endl;
	t12 = mergeTrees(root1, root2);
	printTree(t12);

	return;
}

int main() {
	test();
	return 0;
}
