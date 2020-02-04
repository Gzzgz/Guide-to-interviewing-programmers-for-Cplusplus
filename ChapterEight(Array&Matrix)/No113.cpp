/*
�����ơ������ж��ź���ľ���������
����Ŀ������һ����N*M�����;���matrix��һ������K��matrix��ÿһ�к�ÿһ�ж����ź���ġ�
ʵ��һ���������ж�K�Ƿ���matrix�С�
���磺
0 1 2 5
2 3 4 7 
4 4 4 8
5 7 7 9
���K=7,����true,���K=6������false
Ҫ��ʱ�临�Ӷ�ΪO(N+M),����ռ临�Ӷ�Ϊ O(1)
���Ѷȡ�ʿ
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