/*
【名称】自然数数组的排序
【题目】给定一个长度为N的整型数组arr，其中有N个互不相等的自然数1-N，请实现arr
的排序，但是不要把下标0~N-1位置上的数通过直接赋值的方式替换成1-N
要求：时间复杂度为O(N),额外空间复杂度为O(1)
【难度】士
*/

#include <iostream>

void sort1(int* arr, int len) {
	int tmp = 0;
	int next = 0;
	for (int i = 0; i != len; i ++) {
		tmp = arr[i];
		while (arr[i] != i + 1) {
			next = arr[tmp - 1];
			arr[tmp - 1] = tmp;
			tmp = next;
		}
	}
}

void sort2(int* arr, int len) {
	int tmp = 0;
	for (int i = 0; i != len; i ++) {
		while (arr[i] != i + 1) {
			tmp = arr[arr[i] - 1];
			arr[arr[i] - 1] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main() {

	int arr[] = {5, 4, 3, 1, 2};
	
	sort1(arr, 5);
	sort2(arr, 5);

	for (int i = 0; i < 5; i ++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}