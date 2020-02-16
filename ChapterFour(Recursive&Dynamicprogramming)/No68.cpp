/*
【名称】拍成一条线的纸牌博弈问题
【题目】给定一个整型数组arr，代表数值不同的纸牌排成一条线，玩家A，B依次
拿走每张纸牌，规定玩家A先拿，B后拿，但是每个玩家只能拿走最左或最右的纸牌，
玩家A,B都是绝顶聪明，请返回最后获胜者的分数
【难度】尉
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