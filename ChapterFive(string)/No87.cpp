/*
【名称】0左边必有1的二进制字符串数量
【题目】给定一个整数N,求由"0"与"1"字符组成的长度为N的所有字符串中，满足
"0"字符的左边必有"1"字符的字符串数量。
【难度】校
*/

#include <iostream>
#include <string>


int process(int i, int n) {
	if (i == n - 1) {
		return 2;
	}
	if (i == n) {
		return 1;
	}
	return process(i + 1, n) + process(i + 2, n);
}

int getNum1(int n) {
	if (n < 1) {
		return 0;
	}
	return process(1, n);
}

int getNum2(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int pre = 1;
	int cur = 1;
	int tmp = 0;
	for (int i = 2; i < n + 1; i ++) {
		tmp = cur;
		cur += pre;
		pre = tmp;
	}
	return cur;
}

void muliMatrix(int** m1, int** m2, int**res, int rows, int cols) {
	
	for (int i = 0; i < cols; i ++) {
		for (int j = 0; j < rows; j ++) {
			for (int k = 0; k < rows; k ++) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

void matrixPower(int** m, int** res, int rows, int cols, int p) {
	int** tmp = new int*[rows];
	int** res_tmp = new int*[rows];
	int** tmp_tmp = new int*[rows];
	for (int i = 0; i < rows; i++) {
		tmp[i] = new int[cols];
		res_tmp[i] = new int[cols];
		tmp_tmp[i] = new int[cols];
		res[i][i] = 1;
		for (int j = 0; j < cols; j++) {
			tmp[i][j] = m[i][j];
			tmp_tmp[i][j] = 0;
			res_tmp[i][j] = 0;
		}
	}
	for (; p != 0; p >>= 1) {
		if ((p & 1) != 0) {
			muliMatrix(res, tmp, res_tmp, rows, cols);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					res[i][j] = res_tmp[i][j];
					res_tmp[i][j] = 0;
				}
			}
		}
		muliMatrix(tmp, tmp, tmp_tmp, rows, cols);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				tmp[i][j] = tmp_tmp[i][j];
				tmp_tmp[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		delete[] tmp[i];
		delete[] res_tmp[i];
		delete[] tmp_tmp[i];
	}
	delete[] tmp;
	delete[] tmp_tmp;
	delete[] res_tmp;
}

int getNum3(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return n;
	}
	int** base = new int*[2];
	int** res = new int*[2];
	int arr[] = {1, 1, 1, 0};
	int count = 0;

	for (int i = 0; i < 2; i ++) {
		base[i] = new int[2];
		res[i] = new int[2];
		for (int j = 0; j < 2; j ++) {
			base[i][j] = arr[count++];
			res[i][j] = 0;
		}
	}
	matrixPower(base, res, 2, 2, n - 2);

	int r = 2 * res[0][0] + res[1][0];

	for (int i = 0; i < 2; i ++) {
		delete[] base[i];
		delete[] res[i];
	}
	delete[] base;
	delete[] res;

	return r;
}

int main() {

	int n = 3;

	std::cout << getNum3(n) << std::endl;


	return 0;
}