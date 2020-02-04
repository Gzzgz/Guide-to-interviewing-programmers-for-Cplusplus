/*
�����ơ������±궼����������ż���±궼��ż��
����Ŀ������һ�����Ȳ�С��2������arr��ʵ��һ����������arr��Ҫô�����е�ż���±궼��ż����Ҫô�����е������±궼��������
Ҫ�����arr����ΪN,����Ҫ��ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
*/

#include <iostream>

void swap(int* arr, int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void modify(int* arr, int len) {
	if (len < 2) {
		return;
	}
	int even = 0;
	int odd = 1;
	int end = len - 1;
	while (even <= end && odd <= end) {
		if ((arr[end] & 1) == 0) {
			swap(arr, end, even);
			even += 2;
		}
		else {
			swap(arr, end, odd);
			odd += 2;
		}
	}
}

int main() {

	int arr[6] = {1, 8, 3, 2, 4, 6};
	modify(arr, 6);
	for (int i = 0; i < 6; i ++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}