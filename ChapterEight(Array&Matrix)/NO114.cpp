/*
【名称】最长的可整合子数组的长度
【题目】先给出可整合数组的定义。如果一个数组的排序之后，每相邻两个数差的绝对值
都为1，则该数组为可整合数组。例如[5,3,4,6,2]排序之后为[2,3,4,5,6], 符合每相邻
两个数差的绝对值都是1，所以这个数组为可整合数组。 给定一个整型数组arr，请返回其中
最大可整合子数组的长度。例如[5,5,3,2,6,4,3]的最大可整合子数组为[5,3,2,6,4]，所以
返回5.
【难度】尉
*/

#include <iostream>
#include <algorithm>
#include <set>

bool compare(int a, int b) {
	return a <= b;
}

bool isIntegrated(int* arr, int len, int left, int right) {

	int* newarr = new int[right - left + 1];
	for (int i = 0; i < right - left + 1; i ++) {
		newarr[i] = arr[left + i];
	}
	std::sort(newarr, newarr + right - left + 1, compare);
	
	for (int i = 1; i < right - left + 1; i ++) {
		if (newarr[i - 1] != newarr[i] - 1) {
			delete[] newarr;
			return false;
		}
	}
	delete[] newarr;

	return true;
}

int getLIL1(int* arr, int len) {

	if (len == 0) {
		return 0;
	}
	int length = 0;
	for (int i = 0; i < len; i ++) {
		for (int j = i; j < len; j ++) {
			if (isIntegrated(arr, len, i, j)) {
				length = length > (j - i + 1) ? length : (j - i + 1);
			}
		}
	}
	return length;
}

int getLIL2(int* arr, int length) {
	if (length == 0) {
		return 0;
	}
	int len = 0;
	int max = 0;
	int min = 0;
	
	std::set<int> set;
	for (int i = 0; i < length; i ++) {
		max = INT_MIN;
		min = INT_MAX;
		for (int j = i; j < length; j ++) {
			if (set.find(arr[j]) != set.end()) {
				break;
			}
			set.insert(arr[j]);
			max = max > arr[j] ? max : arr[j];
			min = min < arr[j] ? min : arr[j];
			if (max - min == j - 1) {
				len = len > (j - i + 1) ? len : (j - i + 1);
			}
		}
		set.clear();
	}
	return len;
}

int main() {

	int arr[] = {3,3,4,5,6,7, 6};

	std::cout << getLIL1(arr, 7) << std::endl;

	std::cout << getLIL2(arr, 7) << std::endl;

	return 0;
}