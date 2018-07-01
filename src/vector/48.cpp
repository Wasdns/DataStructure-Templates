// leetcode48: rotate-image
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<vector<int>> matrix);

// Solution:
// Regard the matrix as several circles which have the same center.
// e.g.:
// 1 2 3
// 4 5 6
// 7 8 9
// This matrix has two circules, one is:
// 1 2 3
// 4   6
// 7 8 9
// while another is:
//   5
// For each circle, I rotate it using a temporary vector. And after
// all the circles have been rotated, this algorithm finished.

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	if (n == 0 || n == 1) {
		return;
	}

	// the number of circles
	int circles_num = n/2;

	// for each circle
	for (int i = 0; i < circles_num; i++) {
		// the item number occupied by a line of this circle 
		// e.g., 
		// 1 2 3 
		// 4   6
		// 7 8 9
		// each line has three items, so the number is 3
		int item_num = n-2*i;

		// two key index of edge items
		int edge1 = i;
		int edge2 = n-i-1;

		// using a temporary vector to store these items
		vector<int> tmpArray(item_num);


		// the following process splits the rotating into two steps
		// 1.rotate the items in the middle
		// 2.rotate the four items in the edges
		// e.g., 
		// 1 2 3 
		// 4   6
		// 7 8 9
		// 1: 2->6->8->4->2
		// 2: 1->3->9->7->1


		// 1.rotate the items in the middle

		// (1) left-right
		int lineno=edge1, columno=edge1;
		int tmpArray_idx = 0;

		// record the first line in tmpArray
		for (columno = edge1+1; columno < edge2; columno++) {
			tmpArray[tmpArray_idx] = matrix[lineno][columno];
			tmpArray_idx++;
		}

		// (2) top-down
		columno = edge2;
		tmpArray_idx = 0;

		for (lineno = edge1+1; lineno < edge2; lineno++) {
			// for each item, switch the current item and the item stored in tmpArray
			int tmpItem = matrix[lineno][columno];
			matrix[lineno][columno] = tmpArray[tmpArray_idx];
			tmpArray[tmpArray_idx] = tmpItem;
			tmpArray_idx++;
		}

		// (3) right-left
		lineno = edge2;
		tmpArray_idx = 0;

		for (columno = edge2-1; columno > edge1; columno--) {
			// for each item, switch the current item and the item stored in tmpArray
			int tmpItem = matrix[lineno][columno];
			matrix[lineno][columno] = tmpArray[tmpArray_idx];
			tmpArray[tmpArray_idx] = tmpItem;
			tmpArray_idx++;
		}

		// (4) bottom-up
		columno = edge1;
		tmpArray_idx = 0;

		for (lineno = edge2-1; lineno > edge1; lineno--) {
			// for each item, switch the current item and the item stored in tmpArray
			int tmpItem = matrix[lineno][columno];
			matrix[lineno][columno] = tmpArray[tmpArray_idx];
			tmpArray[tmpArray_idx] = tmpItem;
			tmpArray_idx++;
		}

		// (5) finally, fill the first line of circle
		lineno = edge1;
		tmpArray_idx = 0;

		for (columno = edge1+1; columno < edge2; columno++) {
			matrix[lineno][columno] = tmpArray[tmpArray_idx];
			tmpArray_idx++;
		}


		// 2.rotate the four items in the edges

		int leftUp = matrix[edge1][edge1];
		int RightUp = matrix[edge1][edge2];
		int RightDown = matrix[edge2][edge2];
		int leftDown = matrix[edge2][edge1];
		matrix[edge1][edge1] = leftDown;
		matrix[edge1][edge2] = leftUp;
		matrix[edge2][edge2] = RightUp;
		matrix[edge2][edge1] = RightDown;
	}

	// printVector(matrix);
	return;
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
	vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	rotate(matrix1);
	rotate(matrix2);

	return;
}

int main() {
	test();
	return 0;
}