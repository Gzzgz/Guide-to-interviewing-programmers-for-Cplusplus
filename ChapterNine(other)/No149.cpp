/*
【名称】从N个数种等概率打印M个数
【题目】给定一个长度N且美欧重复元素的数组arr和一个整数n，实现函数等概率随机
打印arr中的M个数。
要求：1.相同的数不要重复打印；
2.时间复杂度O(M)，空间复杂度O(1)
3.可以改变arr数组。
【难度】士
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int* arr, int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void printRandM(int* arr, int len, int m) {
	if (arr == nullptr || len == 0 || m < 0) {
		return;
	}
	m = len < m ? len : m;
	int count = 0;
	int i = 0;
	while (count < m) {
		i = (int)(rand() % 100 / 100.0 * (len - count));
		std::cout << arr[i] << " ";
		swap(arr, len - count++ - 1, i);
	}
	std::cout << std::endl;
}

int main() {
	srand(time(NULL));
	int arr[] = {1,2,3,4,5,6,7};
	printRandM(arr, 7, 5);

	return 0;
}