/*
【名称】边界都是1的最大正方形大小
【题目】给定一个N*N的矩阵，在这个矩阵中，只有0和1两种值，返回边框全是1的最大正方形的边长长度
例如：
0 1 1 1 1 
0 1 0 0 1
0 1 0 0 1
0 1 1 1 1
0 1 0 1 1
其中边框全是1的最大正方形的大小为4*4，所以返回4
【难度】尉
*/
#include <iostream>


bool hasSizeOfBorder(int size, int** right, int** down, int rows, int cols) {
	
	for (int i = 0; i != rows - size + 1; i ++) {
		for (int j = 0; j != cols - size + 1; j ++) {
			if (right[i][j] >= size && down[i][j] >= size
				&& right[i + size - 1][j] >= size
				&& down[i][j + size - 1] >= size) {
				return true;
			}
		}
	}
	return false;
}

void setBorderMap(int** m, int** right, int** down, int rows, int cols) {

	int r = rows;
	int c = cols;
	if (m[r - 1][c - 1] == 1) {
		right[r - 1][c - 1] = 1;
		down[r - 1][c - 1] = 1;
	}
	for (int i = r - 2; i != -1; i --) {
		if (m[i][c - 1] == 1) {
			right[i][c - 1] = 1;
			down[i][c - 1] = down[i + 1][c + 1] + 1;
		}
	}
	for (int i = c - 2; i != -1; i --) {
		if (m[r - 1][i] == 1) {
			right[r - 1][i] = right[r - 1][i + 1] + 1;
			down[r - 1][i] = 1;
		}
	}
	for (int i = r - 2; i != -1; i --) {
		for (int j = c - 2; j != -1; j --) {
			if (m[i][j] == 1) {
				right[i][j] = right[i][j + 1] + 1;
				down[i][j] = down[i + 1][j] + 1;
			}
		}
	}
}

int getMaxSize(int** m, int rows, int cols) {

	int** right = new int*[rows];
	int** down = new int*[rows];
	int res = 0;

	for (int i = 0; i < rows; i ++) {
		right[i] = new int[cols];
		down[i] = new int[cols];
		for (int j = 0; j < cols; j ++) {
			right[i][j] = 0;
			down[i][j] = 0;
		}
	}
	setBorderMap(m, right, down, rows, cols);
	for (int size = rows < cols ? rows : cols; size != 0; size --) {
		if (hasSizeOfBorder(size, right, down, rows, cols)) {
			res = size;
			break;
		}
	}
	for (int i = 0; i < rows; i ++) {
		delete[] right[i];
		delete[] down[i];
	}
	delete[] right;
	delete[] down;

	return res;
}

int main() {

	int arr[] = {0,1,1,1,1, 0,1,0,0,1, 0,1,0,0,1, 0,1,1,1,1, 0,1,0,1,1};
	int count = 0;

	int** m = new int*[5];
	for (int i = 0; i < 5; i ++) {
		m[i] = new int[5];
		for (int j = 0; j < 5; j ++) {
			m[i][j] = arr[count++];
		}
	}

	std::cout << getMaxSize(m, 5, 5) << std::endl;

	for (int i = 0; i < 5; i ++) {
		delete[] m[i];
	}
	delete[] m;

	return 0;
}