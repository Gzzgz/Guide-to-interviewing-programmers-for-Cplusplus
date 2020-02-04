/*
【名称】“之”字形打印矩阵
【题目】给定一个矩阵matrix,按照“之”字形的方式打印这个矩阵，例如：
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
“之”字形打印的结果为：1，2，5，9，6，3，4，7，10，11，8，12
要求：额外空间复杂度为O(1)
【难度】士
*/

#include <iostream>


void printLevel(int** m, int rows, int cols, int tr, int tc,
	int dr, int dc, bool f) {
	if (f) {
		while (tr != dr + 1) {
			std::cout << m[tr++][tc--] << " ";
		}
	}
	else {
		while (dr != tr - 1) {
			std::cout << m[dr--][dc++] << " ";
		}
	}
}

void printMatrixZigZag(int** matrix, int rows, int cols) {
	int tr = 0;
	int tc = 0;
	int dr = 0;
	int dc = 0;
	int endr = rows - 1;
	int endc = cols - 1;
	bool fromup = false;
	while (tr != endr + 1) {
		printLevel(matrix, rows, cols, tr, tc, dr, dc, fromup);
		tr = tc == endc ? tr + 1 : tr;
		tc = tc == endc ? tc : tc + 1;
		dc = dr == endr ? dc + 1 : dc;
		dr = dr == endr ? dr : dr + 1;
		fromup = !fromup;
	}
}

int main() {

	int** matrix = new int*[4];
	int count = 1;
	for (int i = 0; i < 4; i++) {
		matrix[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = count++;
		}
	}

	printMatrixZigZag(matrix, 4, 4);

	delete[] matrix;
	return 0;
}