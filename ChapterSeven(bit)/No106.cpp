/*
�����ơ���������������k�ε��������ҵ�ֻ����һ�ε���
����Ŀ������һ����������arr��һ������1������k,��֪arr��ֻ��1����������
1�Σ�����������������k�Σ��뷵��ֻ������1�ε�����
Ҫ��ʱ�临�Ӷ�ΪO(N),����ռ临�Ӷ�ΪO(1)
���Ѷȡ�ξ
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