/*
【名称】在行列都排好序的矩阵中找数
【题目】给定一个有N*M的整型矩阵matrix和一个整数K，matrix的每一行和每一列都是排好序的。
实现一个函数，判断K是否在matrix中。
例如：
0 1 2 5
2 3 4 7 
4 4 4 8
5 7 7 9
如果K=7,返回true,如果K=6，返回false
要求：时间复杂度为O(N+M),额外空间复杂度为 O(1)
【难度】士
*/

#include <iostream>

bool isContains(int matrix[][4], int rows, int cols, int k) {
	int row = 0;
	int col = cols - 1;
	while (row < rows && col > -1) {
		if (matrix[row][col] == k) {
			return true;
		}
		else if (matrix[row][col] > k) {
			col--;
		}
		else {
			row++;
		}
	}
	return false;
}

int main() {

	int arr[4][4] = {0,1,2,5,2,3,4,7,4,4,4,8,5,7,7,9};

	std::cout << isContains(arr, 4, 4, 5) << std::endl;

	return 0;
}