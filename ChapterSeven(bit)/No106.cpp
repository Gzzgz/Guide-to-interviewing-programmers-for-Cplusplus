/*
【名称】在其他数都出现k次的数组中找到只出现一次的数
【题目】给定一个整型数组arr和一个大于1的整数k,已知arr中只有1个数出现了
1次，其他的数都出现了k次，请返回只出现了1次的数。
要求：时间复杂度为O(N),额外空间复杂度为O(1)
【难度】尉
*/

#include <iostream>


int getNumFromKSysNum(int eO[], int len, int k) {
	int res = 0;
	for (int i = len - 1; i != -1; i --) {
		res = res * k + eO[i];
	}
	return res;
}

void getKSysNumFromNum(int value, int k, int* res) {
	
	int index = 0;
	while (value != 0) {
		res[index++] = value % k;
		value /= k;
	}
}

void setExclusiveOr(int* eO, int len, int value, int k) {
	int* res = new int[32];
	memset(res, 0, sizeof(int) * 32);
	getKSysNumFromNum(value, k, res);
	for (int i = 0; i < len; i ++) {
		eO[i] = (eO[i] + res[i]) % k;
	}
	delete[] res;
}

int onceNum(int arr[], int len, int k) {
	int* eO = new int[32];
	memset(eO, 0, sizeof(int) * 32);
	for (int i = 0; i != len; i ++) {
		setExclusiveOr(eO, len, arr[i], k);
	}
	int res = getNumFromKSysNum(eO, len, k);
	delete[] eO;
	return res;
}

int main() {
	int arr[] = { 1,1,1,2,3,3,3 };
	std::cout << onceNum(arr, 7, 3) << std::endl;

	return 0;
}