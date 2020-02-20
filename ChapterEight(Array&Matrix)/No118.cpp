/*
【名称】未排序数组中累加和小于或等于给定值的最长子数组长度
【题目】给定一个无序数组arr，其中元素可正，负，0,给定一个整数k,求arr所有的子
数组中累加和小于或等于k的最长子数组长度.
例如：arr=[3,-2,-4,0,6],k=-2，相加和小于或等于-2的最长子数组为{3,-2,-4,0},所以结果返回4.
【难度】校
*/

#include <iostream>


int getLessIndex(int* arr, int len, int num) {

	int low = 0;
	int high = len - 1;
	int mid = 0;
	int res = -1;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] >= num) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return res;
}

int maxLength(int* arr, int len, int k) {

	int* h = new int[len + 1];
	memset(h, 0, sizeof(int) * (len + 1));
	
	int sum = 0;
	h[0] = sum;
	for (int i = 0; i != len; i ++) {
		sum += arr[i];
		h[i + 1] = sum > h[i] ? sum : h[i];
	}
	sum = 0;
	int res = 0;
	int pre = 0;
	int length = 0;
	for (int i = 0; i != len; i ++) {
		sum += arr[i];
		pre = getLessIndex(h, len + 1, sum - k);
		length = pre == -1 ? 0 : i - pre + 1;
		res = res > length ? res : length;
	}
	delete[] h;

	return res;
}

int main(){

	int arr[] = {3, -2, -4, 0, 6};
	int k = -2;

	std::cout << maxLength(arr, 5, k) << std::endl;

	return 0;
}
