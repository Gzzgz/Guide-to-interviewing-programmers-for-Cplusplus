/*
【名称】转圈打印矩阵
【题目】给定一个整型矩阵matrix，请按照转圈的方式打印它
例如：
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
打印结果为:1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
要求：额外空间复杂度为O(1)
【难度】士
*/

#include <iostream>

void printEdge(int** m, int tR, int tC, int dR, int dC) {
	if (tR == dR) {
		for (int i = tC; i <= dC; i ++) {
			std::cout << m[tR][i] << " ";
		}
	}
	else if (tC == dC) {
		for (int i = tR; i <= dR; i ++) {
			std::cout << m[i][tC] << " ";
		}
	}
	else {
		int curC = tC;
		int curR = tR;
		while (curC != dC) {
			std::cout << m[tR][curC] << " ";
			curC++;
		}
		while (curR != dR) {
			std::cout << m[curR][dC] << " ";
			curR++;
		}
		while (curC != tC) {
			std::cout << m[dR][curC] << " ";
			curC--;
		}
		while(curR != tR) {
			std::cout << m[curR][tC] << " ";
			curR--;
		}
	}
}

void spiralOrderPrint(int** matrix, int rows, int cols) {
	int tR = 0;
	int tC = 0;
	int dR = rows - 1;
	int dC = cols - 1;
	while (tR <= dR && tC <= dC) {
		printEdge(matrix, tR++, tC++, dR--, dC--);
	}
}


int main() {

	int** matrix = new int*[5];
	int count = 0;
	for (int i = 0; i < 5; i ++) {
		matrix[i] = new int[5];
		for (int j = 0; j < 5;  j++) {
			matrix[i][j] = count++;
		}
	}

	spiralOrderPrint(matrix, 5, 5);
	delete[] matrix;

	return 0;
}