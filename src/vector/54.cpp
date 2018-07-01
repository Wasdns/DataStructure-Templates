// leetcode54: spiral-matrix
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans = {};
	int m = matrix.size();
	if (m == 0) { // for special input: []
		return ans;
	}
	int n = matrix[0].size();
	
	// for m = 1 or n = 1
	if (m == 1 || n == 1) {
		if (m == 1) {
			for (int j = 0; j < n; j++) {
				ans.push_back(matrix[0][j]);
			}
			return ans;
		} else {
			for (int i = 0; i < m; i++) {
				ans.push_back(matrix[i][0]);
			}
			return ans;
		}
	}

	// for other situations

	// magic number
	int MAGIC = 952693358;

	int lineno = 0;
	int colomno = 0;

	while (1) {
		// 1.go right
		while (colomno < n && matrix[lineno][colomno] != MAGIC) {
			ans.push_back(matrix[lineno][colomno]);
			matrix[lineno][colomno] = MAGIC;
			colomno++;
		}

		colomno--;
		lineno++;

		// if the underneath item has been visited, break
		if (matrix[lineno][colomno] == MAGIC) break;

		// 2.go down
		while (lineno < m && matrix[lineno][colomno] != MAGIC) {
			ans.push_back(matrix[lineno][colomno]);
			matrix[lineno][colomno] = MAGIC;
			lineno++;
		}

		lineno--;
		colomno--;

		// if the left item has been visited, break
		if (matrix[lineno][colomno] == MAGIC) break;

		// 3.go left
		while (colomno >= 0 && matrix[lineno][colomno] != MAGIC) {
			ans.push_back(matrix[lineno][colomno]);
			matrix[lineno][colomno] = MAGIC;
			colomno--;
		}

		colomno++;
		lineno--;

		// if the upward item has been visited, break
		if (matrix[lineno][colomno] == MAGIC) break;

		// 4.go up
		while (lineno >= 0 && matrix[lineno][colomno] != MAGIC) {
			ans.push_back(matrix[lineno][colomno]);
			matrix[lineno][colomno] = MAGIC;
			lineno--;
		}

		lineno++;
		colomno++;

		// if the right item has been visited, break
		if (matrix[lineno][colomno] == MAGIC) break;
	}

	return ans;
}



// the following codes are used to test the program

void printVector(vector<int> ans) {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

void test() {
	vector<vector<int>> matrix1{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<vector<int>> matrix2{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<vector<int>> matrix3{{1, 2}, {3, 4}};
	vector<vector<int>> matrix4{{}};
	vector<vector<int>> matrix5{{1, 2, 3}};
	vector<vector<int>> matrix6{{1}, {2}, {3}};
	vector<int> ans;

	ans = spiralOrder(matrix1);
	printVector(ans);
	ans = spiralOrder(matrix2);
	printVector(ans);
	ans = spiralOrder(matrix3);
	printVector(ans);
	ans = spiralOrder(matrix4);
	printVector(ans);
	ans = spiralOrder(matrix5);
	printVector(ans);
	ans = spiralOrder(matrix6);
	printVector(ans);

	return;
}

int main() {
	test();
	return 0;
}