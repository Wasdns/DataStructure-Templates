// leetcode513: find-bottom-left-tree-value
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

int findBottomLeftValue(TreeNode* root) {
	int ans = 0;

	if (root == NULL) {
		return ans;
	} else if (isTail(root)) {
		ans = root->val;
	} else {
		queue<TreeNode*> nodeq;
		nodeq.push(root);

		int layerNumber = 1;
		int sonNumber = 0;
		int temp = 0;

		bool isLeftVal = true;

		while (!nodeq.empty()) {
			TreeNode* currentNode = nodeq.front();
			nodeq.pop();

			temp++;

			if (isLeftVal) {
				ans = currentNode->val;
				isLeftVal = false;
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
				isLeftVal = true;
			}
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
	ans = findBottomLeftValue(root1);
	cout << ans << endl;

	cout << "Tree2:" << endl;
	ans = findBottomLeftValue(root2);
	cout << ans << endl;

	return;
}

int main() {
	test();
	return 0;
}

