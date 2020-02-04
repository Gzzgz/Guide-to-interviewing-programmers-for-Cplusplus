/*
�����ơ��Ӿ��������ۼӺ�����
����Ŀ������һ������matrix�����е�ֵ����������0�������Ӿ��������ۼӺ͡�
���Ѷȡ�ξ
*/

#include <iostream>

int maxSum(int** m, int rows, int cols) {
	if (rows == 0 || cols == 0) {
		return 0;
	}
	int max = INT_MIN;
	int cur = 0;
	
	for (int i = 0; i != rows; i ++) {
		int* s = new int[cols];
		for (int j = i; j != rows; j ++) {
			cur = 0;
			for (int k = 0; k != cols; k ++) {
				s[k] += m[j][k];
				cur += s[k];
				max = max > cur ? max : cur;
				cur = cur < 0 ? 0 : cur;
			}
		}
		delete[] s;
	}
	return max;
}

int main() {

	int values[] = {-90, 48, 78, 64, -40, 64, -81, -7, 66};
	int count = 0;
	int** arr = new int*[3];
	for (int i = 0; i < 3; i ++) {
		arr[i] = new int[3];
		for (int j = 0; j < 3; j ++) {
			arr[i][j] = values[count++];
		}
	}
	std::cout << maxSum(arr, 3, 3) << std::endl;

	return 0;
}