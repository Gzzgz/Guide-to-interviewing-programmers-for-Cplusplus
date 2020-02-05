/*
�����ơ���������֮��������������ֵ
����Ŀ������һ����������arr��������������������������ֵ
arr=[9,3,1,10],�����Ϊ[1,3,9,10],����6
Ҫ�����arr�ĳ���ΪN��������ʱ�临�Ӷ�O(N)
���Ѷȡ�ξ
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