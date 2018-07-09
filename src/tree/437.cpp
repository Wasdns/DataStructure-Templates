// leetcode437: path-sum-iii
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

int pathSum(TreeNode* root, int sum) {
	int ans = 0;

	if (root == NULL) {
		return ans;
	} else if (isTail(root)) {
		if (root->val == sum) {
			ans = 1;
		}
		return ans;
	} else {
		queue<TreeNode*> nodeq;
		queue<int> sumq;

		nodeq.push(root);
		sumq.push(root->val);

		while (!nodeq.empty()) {
			TreeNode* currentNode = nodeq.front();
			nodeq.pop();
			int currentSum = sumq.front();
			sumq.pop();

			if (currentSum == sum) {
				ans++;
			}

			if (currentNode->left != NULL) {
				nodeq.push(currentNode->left);
				int newSum = currentSum+currentNode->left->val;
				sumq.push(newSum);
			}
			if (currentNode->right != NULL) {
				nodeq.push(currentNode->right);
				int newSum = currentSum+currentNode->right->val;
				sumq.push(newSum);
			}
		}

		if (root->left != NULL) {
			int l_ans = pathSum(root->left, sum);
			ans += l_ans;
		}
		if (root->right != NULL) {
			int r_ans = pathSum(root->right, sum);
			ans += r_ans;
		}
	}

	return ans;
}

// the following codes are used to test the program

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    cout << input << endl;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
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
	string tree_str;

	//       10
	//      /  \
	//     5   -3
	//    / \    \
	//   3   2   11
	//  / \   \
	// 3  -2   1
	tree_str = "[10,5,-3,3,2,null,11,3,-2,null,1]";
	root1 = stringToTreeNode(tree_str);

	//   3
	//  / \
	// 9  20
	//   /  \
	//  15   7
	tree_str = "[3,9,20,null,null,15,7]";
	root2 = stringToTreeNode(tree_str);

	int ans = 0;

	cout << "Tree1:" << endl;
	ans = pathSum(root1,8);
	cout << ans << endl;

	cout << "Tree2:" << endl;
	ans = pathSum(root2,30);
	cout << ans << endl;

	return;
}

int main() {
	test();
	return 0;
}

