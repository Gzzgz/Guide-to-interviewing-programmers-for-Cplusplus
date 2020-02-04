/*
�����ơ��������ξ���˳ʱ��ת��90��
����Ŀ������һ��N*N�ľ���matrix����������������˳ʱ��ת��90������ʽ
���磺
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
˳ʱ��ת��90���Ϊ��
13  9  5  1
14 10  6  2
15 11  7  3
16 12  8  4
Ҫ�󣺶���ռ临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
*/

#include <iostream>

void rotateEdge(int** m, int tr, int tc, int dr, int dc) {
	int times = dc - tc;
	int tmp = 0;
	for (int i = 0; i != times; i ++) {
		tmp = m[tr][tc + i];
		m[tr][tc + i] = m[dr - i][tc];
		m[dr - i][tc] = m[dr][dc - i];
		m[dr][dc - i] = m[tr + i][dc];
		m[tr + i][dc] = tmp;
	}
}

void rotate(int** matrix, int rows, int cols) {
	int tr = 0;
	int tc = 0;
	int dr = rows - 1;
	int dc = cols - 1;
	while (tr < dr) {
		rotateEdge(matrix, tr++, tc++, dr--, dc--);
	}
}

int main() {

	int** matrix = new int*[5];
	int count = 0;
	for (int i = 0; i < 5; i ++) {
		matrix[i] = new int[5];
		for (int j = 0; j < 5; j ++) {
			matrix[i][j] = count++;
		}
	}
	rotate(matrix, 5, 5);

	for (int i = 0; i < 5; i ++) {
		for (int j = 0; j < 5; j ++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}