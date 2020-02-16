/*
�����ơ��ĳ�һ���ߵ�ֽ�Ʋ�������
����Ŀ������һ����������arr��������ֵ��ͬ��ֽ���ų�һ���ߣ����A��B����
����ÿ��ֽ�ƣ��涨���A���ã�B���ã�����ÿ�����ֻ��������������ҵ�ֽ�ƣ�
���A,B���Ǿ����������뷵������ʤ�ߵķ���
���Ѷȡ�ξ
*/

#include <iostream>

int f(int* arr, int i, int j);
int s(int* arr, int i, int j);

int f(int* arr, int i, int j) {
	if (i == j) {
		return  arr[i];
	}
	int pf = arr[i] + s(arr, i + 1, j);
	int ps = arr[j] + s(arr, i, j - 1);
	return pf > ps ? pf : ps;
}

int s(int* arr, int i, int j){
	if (i == j) {
		return 0;
	}
	int pf = f(arr, i + 1, j);
	int ps = f(arr, i , j - 1);
	return  pf < ps ? pf : ps;
}

int win1(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int pf = f(arr, 0, len - 1);
	int ps = s(arr, 0, len - 1);
	return pf > ps ? pf : ps;
}


int win2(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int** f = new int*[len];
	int** s = new int*[len];
	for (int i = 0; i < len; i ++) {
		f[i] = new int[len];
		s[i] = new int[len];
		for (int j = 0; j < len; j ++) {
			f[i][j] = 0;
			s[i][j] = 0;
		}
	}
	for (int j = 0; j < len; j ++) {
		f[j][j] = arr[j];
		for (int i = j - 1; i >= 0; i --) {
			int s1 = arr[i] + s[i + 1][j];
			int s2 = arr[j] + s[i][j - 1];
			f[i][j] = s1 > s2 ? s1 : s2;
			s[i][j] = f[i + 1][j] < f[i][j - 1] ? f[i + 1][j] : f[i][j - 1];
		}
	}
	int res = f[0][len - 1] > s[0][len - 1] ? f[0][len - 1] : s[0][len - 1];

	for (int i = 0; i < len; i ++) {
		delete[] f[i];
		delete[] s[i];
	}
	delete[] f;
	delete[] s;

	return res;
}

int main(){

	int arr[] = {1,2,100,4};

	std::cout << win2(arr, 4) << std::endl;

	return 0;
}