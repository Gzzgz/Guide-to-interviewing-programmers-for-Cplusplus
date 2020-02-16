/*
【名称】矩阵的最小路径和
【题目】给定一个矩阵m,从左上角开始每次只能向右或者向下走，最后到达右下角的位置，
路径上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。
【难度】尉
*/

#include <math.h>
#include <iostream>

int minPathSum1(int** m, int rows, int cols) {
	if (rows == 0 || cols == 0) {
		return 0;
	}
	int** dp = new int*[rows];
	for (int i = 0; i < rows; i ++) {
		dp[i] = new int[cols];
	}
	dp[0][0] = m[0][0];
	for (int i = 1; i < rows; i ++) {
		dp[i][0] = dp[i - 1][0] + m[i][0];
	}
	for (int i = 1; i < cols; i ++) {
		dp[0][i] = dp[0][i - 1] + m[0][i];
	}
	for (int i = 1; i < rows; i ++) {
		for (int j = 1; j < cols; j ++) {
			dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			dp[i][j] += m[i][j];

		}
	}
	int r = dp[rows - 1][cols - 1];
	for (int i = 0; i < rows; i ++) {
		delete[] dp[i];
	}
	delete[] dp;
	return r;
}

int minPathSum2(int** m, int rows, int cols) {
	 if (rows == 0 || cols == 0) {
		 return 0;
	}
	 int more = rows > cols ? rows : cols;
	 int less = rows < cols ? rows : cols;
	 bool rowmore = (more == rows);
	 int* arr = new int[less];
	 arr[0] = m[0][0];
	 for (int i = 1; i < less; i ++) {
		 arr[i] = arr[i - 1] + (rowmore ? m[0][i] : m[i][0]);
	 }
	 for (int i = 1; i < more; i ++) {
		 arr[0] += rowmore ? m[i][0] : m[0][i];
		 for (int j = 1; j < less; j ++) {
			 arr[j] = arr[j - 1] < arr[j] ? arr[j - 1] : arr[j];
			 arr[j] += rowmore ? m[i][j] : m[j][i];
		 }
	 }
	 int r = arr[less - 1];
	 delete[] arr;

	 return r;
}

int main() {

	int arr[16] = {1,3,5,9, 8,1,3,4, 5,0,6,1, 8,8,4,0};
	int count = 0;
	int** m = new int*[4];
	for (int i = 0; i < 4; i ++) {
		m[i] = new int[4];
		for (int j = 0; j < 4; j ++) {
			m[i][j] = arr[count++];
		}
	}

	std::cout << minPathSum2(m, 4, 4) << std::endl;

	for (int i = 0; i < 4; i ++) {
		delete[] m[i];
	}
	delete[] m;

	return 0;
}