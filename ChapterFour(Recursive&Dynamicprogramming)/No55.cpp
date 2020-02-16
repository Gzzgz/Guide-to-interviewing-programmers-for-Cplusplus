/*
�����ơ�쳲�����ϵ������ĵݹ�Ͷ�̬�滮
����Ŀ����������N������쳲��������еĵ�N��
��������Ŀ1����������N������̨������һ�ο��Կ�2����1��̨�ף������ж������߷�
��������Ŀ2������ũ���г����ĸţÿ��ֻ����1ͷСĸţ������Զ����������һ��ũ
����1ֻ�����ĸţ���ӵ�2�꿪ʼ��ĸţ��ʼ��Сĸţ��ÿֻСĸţ3�������ֿ�����
Сĸţ����������N����N���ţ������
Ҫ�󣺶��������е����⣬��ʵ��ʱ�临�Ӷ�O(logN)�Ľⷨ
���Ѷȡ���
*/

#include <iostream>

int f1(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return f1(n - 1) + f1(n - 2);
}

int f2(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return  1;
	}
	int res = 1;
	int pre = 1;
	int tmp = 0;
	for (int i = 3; i <= n; i ++) {
		tmp = res;
		res += pre;
		pre = tmp;
	}
	return res;
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
	for (int i = 0; i < rows; i ++) {
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
			for (int i = 0; i < 2; i ++) {
				for (int j = 0; j < 2; j ++) {
					res[i][j] = res_tmp[i][j];
					res_tmp[i][j] = 0;
				}
			}
		}
		muliMatrix(tmp, tmp, tmp_tmp,  rows, cols);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				tmp[i][j] = tmp_tmp[i][j];
				tmp_tmp[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 2; i ++) {
		delete[] tmp[i];
		delete[] res_tmp[i];
		delete[] tmp_tmp[i];
	}
	delete[] tmp;
	delete[] tmp_tmp;
	delete[] res_tmp;
}

int f3(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	int** base = new int*[2]; 
	int** res = new int*[2];
	int arr[4] = {1,1,1,0};
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

	int r =  res[0][0] + res[1][0];
	for (int i = 0; i < 2; i ++) {
		delete[] res[i];
		delete[] base[i];
	}
	delete[] res;
	delete[] base;
	return r;
}

int s1(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return n;
	}
	return s1(n - 1) + s1(n - 2);
}

int s2(int n) {
	if (n < 1) {
		return  0;
	}
	if (n == 1 || n == 2) {
		return n;
	}
	int res = 2;
	int pre = 1;
	int tmp = 0;
	for (int i = 3; i <= n; i ++) {
		tmp = res;
		res += pre;
		pre = tmp;
	}
	return res;
}

int s3(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return n;
	}
	int** base = new int*[2];
	int** res = new int*[2];
	int arr[4] = { 1,1,1,0 };
	int count = 0;
	for (int i = 0; i < 2; i++) {
		base[i] = new int[2];
		res[i] = new int[2];
		for (int j = 0; j < 2; j++) {
			base[i][j] = arr[count++];
			res[i][j] = 0;
		}
	}
	matrixPower(base, res, 2, 2, n - 2);

	int r = 2 * res[0][0] + res[1][0];
	for (int i = 0; i < 2; i++) {
		delete[] res[i];
		delete[] base[i];
	}
	delete[] res;
	delete[] base;
	return r;
}

int c1(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2 || n == 3) {
		return n;
	}
	return c1(n - 1) + c1(n - 3);
}

int c2(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2 || n == 3) {
		return n;
	}
	int res = 3;
	int pre = 2;
	int prepre = 1;
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 4; i <= n; i ++) {
		tmp1 = res;
		tmp2 = pre;
		res += prepre;
		pre = tmp1;
		prepre = tmp2;
	}
	return res;
}

int c3(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1 || n == 2 || n == 3) {
		return n;
	}
	int** base = new int*[3];
	int** res = new int*[3];
	int arr[9] = { 1,1,0,0,0,1,1,0,0 };
	int count = 0;
	for (int i = 0; i < 3; i++) {
		base[i] = new int[3];
		res[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			base[i][j] = arr[count++];
			res[i][j] = 0;
		}
	}
	matrixPower(base, res, 3, 3, n - 3);

	int r = 3 * res[0][0] + 2 * res[1][0] + res[2][0];
	for (int i = 0; i < 3; i++) {
		delete[] res[i];
		delete[] base[i];
	}
	delete[] res;
	delete[] base;
	return r;
}


int main() {

	std::cout << c2(6) << std::endl;

	return 0;
}