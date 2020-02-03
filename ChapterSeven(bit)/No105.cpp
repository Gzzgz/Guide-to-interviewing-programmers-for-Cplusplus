/*
�����ơ���������������ż���ε��������ҵ����������ε���
����Ŀ������һ����������arr������ֻ��һ���������������Σ���������������
��ż���Σ���ӡ�������
����:�������������������Σ�����������������ż���Σ���ӡ����������
Ҫ��ʱ�临�Ӷ�Ϊ O(N)������ռ临�Ӷ�ΪO(1)
���Ѷȡ�ξ
*/

#include <iostream>

int printOddTimesNum1(int arr[], int len) {
	int eO = 0;
	for (int i = 0; i < len; i ++) {
		eO ^= arr[i];
	}
	return eO;
}

void printOddTimesNum2(int arr[], int len) {
	int eO = 0, eOhasOne = 0;
	for (int i = 0; i < len; i ++) {
		eO ^= arr[i];
	}
	int rightOne = eO & (~eO + 1);
	for (int i = 0; i < len; i ++) {
		if ((arr[i] & rightOne) != 0) {
			eOhasOne ^= arr[i];
		}
	}
	std::cout << eOhasOne << " " << (eO ^ eOhasOne) << std::endl;
}

int main() {

	int arr[7] = {1,1,1,2,2,3,3};
	std::cout << printOddTimesNum1(arr, 7) << std::endl;
	int arr2[6] = { 1,1,1,2,3,3 };
	printOddTimesNum2(arr2, 6);

	return 0;
}