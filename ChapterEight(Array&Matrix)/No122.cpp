/*
【名称】子数组的最大累加和问题
【题目】给定一个数组arr，返回子数组的最大累加和。
例如arr=[1,-2,3,5,-2,6,-1]，所有的子数组中，[3,5,-2,6]可以累加出最大的和12，所以返回12
要求：如果arr长度为N，要求时间复杂度为O(N),额外的空间复杂度为O(1)
【难度】士
*/

#include <iostream>

int maxSum(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int max = INT_MIN;
	int cur = 0;
	for (int i = 0; i != len; i ++) {
		cur += arr[i];
		max = max > cur ? max : cur;
		cur = cur < 0 ? 0 : cur;
	}
	return max;
}

int main() {
	int arr[] = {1, -2, 3, 5, -2, 6, -1};
	std::cout << maxSum(arr, 7) << std::endl;

	return 0;
}