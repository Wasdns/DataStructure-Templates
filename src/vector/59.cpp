// leetcode59: spiral-matrix-ii
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n));
	if (n == 0) {
		matrix = {};
		return matrix;
	}
	if (n == 1) {
		matrix = {{1}};
		return matrix;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = -1;
		}
	}

	int item = 1;
	int lineno = 0;
	int columno = 0;

	while (1) {
		// 1.go right
		while (columno < n && matrix[lineno][columno] == -1) {
			matrix[lineno][columno] = item;
			item++;
			columno++;
		}

		columno--;
		lineno++;

		// if the underneath item has been visited, break
		if (matrix[lineno][columno] != -1) break;

		// 2.go down
		while (lineno < n && matrix[lineno][columno] == -1) {
			matrix[lineno][columno] = item;
			item++;
			lineno++;
		}

		lineno--;
		columno--;

		// if the left item has been visited, break
		if (matrix[lineno][columno] != -1) break;

		// 3.go left
		while (columno >= 0 && matrix[lineno][columno] == -1) {
			matrix[lineno][columno] = item;
			item++;
			columno--;
		}

		columno++;
		lineno--;

		// if the upward item has been visited, break
		if (matrix[lineno][columno] != -1) break;

		// 4.go up
		while (lineno >= 0 && matrix[lineno][columno] == -1) {
			matrix[lineno][columno] = item;
			item++;
			lineno--;
		}

		lineno++;
		columno++;

		// if the right item has been visited, break
		if (matrix[lineno][columno] != -1) break;
	}


	return matrix;
}

// the following codes are used to test the program

void printVector(vector<vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void test() {
	vector<vector<int>> matrix;
	int n = 1;
	matrix = generateMatrix(n);
	printVector(matrix);

	return;
}

int main() {
	test();
	return 0;
}