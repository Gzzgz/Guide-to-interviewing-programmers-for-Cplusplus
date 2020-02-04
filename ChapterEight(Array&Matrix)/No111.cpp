/*
�����ơ���Ҫ�������������鳤��
����Ŀ������һ����������arr�������Ҫ�������������鳤�ȡ�
���磺arr={1,5,3,4,2,6,7},����4
���Ѷȡ�ʿ
*/

#include <iostream>

int getMinLength(int arr[], int len) {
	if (len < 2) {
		return 0;
	}
	int min = arr[len - 1];
	int noMinIndex = -1;
	for (int i = len - 2; i != -1; i --) {
		if (arr[i] > min) {
			noMinIndex = i;
		}
		else {
			min = min > arr[i] ? arr[i] : min;
		}
	}
	if (noMinIndex == -1) {
		return 0;
	}
	int max = arr[0];
	int noMaxIndex = -1;
	for (int i = 1; i != len; i ++) {
		if (arr[i] < max) {
			noMaxIndex = i;
		}
		else {
			max = max > arr[i] ? max : arr[i];
		}
	}
	std::cout << noMinIndex << " " << noMaxIndex << std::endl;

	return noMaxIndex - noMinIndex + 1;
}

int main() {

	int arr[] = {1, 4, 6, 2, 7};

	std::cout << getMinLength(arr, 5) << std::endl;

	return 0;
}