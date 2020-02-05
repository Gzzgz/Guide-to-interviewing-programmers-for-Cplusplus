/*
【名称】数组排序之后相邻数的最大插值
【题目】给定一个整型数组arr，返回排序后的相邻两数的最大差值
arr=[9,3,1,10],排序后为[1,3,9,10],返回6
要求：如果arr的长度为N，请做到时间复杂度O(N)
【难度】尉
*/

#include <iostream>


int bucket(long num, long len, long min, long max) {
	return (int)((num - min) * len / (max - min));
}

int maxGap(int nums[], int len)
{
	if (len < 2) {
		return 0;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < len; i ++) {
		min = min < nums[i] ? min : nums[i];
		max = max > nums[i] ? max : nums[i];
	}
	if (min == max) {
		return 0;
	}
	bool* hasNum = new bool[len + 1];
	int* maxs = new int[len + 1];
	int* mins = new int[len + 1];
	memset(hasNum, 0, sizeof(bool) * (len + 1));
	memset(maxs, 0, sizeof(int) * (len + 1));
	memset(mins, 0, sizeof(int) * (len + 1));
	int bid = 0;
	for (int i = 0; i < len; i ++) {
		bid = bucket(nums[i], len, min, max);
		mins[bid] = hasNum[bid] ? (mins[bid] < nums[i] ? mins[bid] : nums[i]) : nums[i];
		maxs[bid] = hasNum[bid] ? (maxs[bid] > nums[i] ? maxs[bid] : nums[i]) : nums[i];
		hasNum[bid] = true;
	}
	int res = 0;
	int lastMax = 0;
	int i = 0;
	while (i <= len) {
		if (hasNum[i ++]) {
			lastMax = maxs[i -1];
			break;
		}
	}
	for (; i <= len; i ++) {
		if (hasNum[i]) {
			res = res > (mins[i] - lastMax) ? res : (mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}
	return res;
}

int main() {

	int arr[] = {9, 3, 1, 10};
	std::cout << maxGap(arr, 4) << std::endl;

	return 0;
}