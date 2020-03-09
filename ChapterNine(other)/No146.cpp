/*
【名称】正数数组的最小不可组成和
【题目】给定一个正数数组arr，其中所有的值都是整数，以下是最小不可组成和概念：
1.把arr每个子集内的所有元素加起来会出现很多值，其中最小的记为min，最大的记为max;
2.在区间[min,max]上，如果有数不可以被arr某一个子集相加得到，那么其中最小的那个
数是arr的最小不可组成和；
3.在区间[min, max]上，如果所有的数都可以被 arr的某一个子集相加得到，那么max+1
是arr的最小不可组成和。
请写函数返回正数数组arr的最小不可组成和。
【进阶题目】如果已知正数数组arr中肯定有1这个数，是否能更快地得到最小不可组成和
【难度】尉
*/
#include <iostream>
#include <set>

void process(int* arr, int len, int i, int sum, std::set<int>& set) {
	if (i == len) {
		set.insert(sum);
		return;
	}
	process(arr, len, i + 1, sum, set);
	process(arr, len, i + 1, sum + arr[i], set);
}

int unformedSum1(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 1;
	}
	std::set<int> set;
	process(arr, len, 0, 0, set);
	int min = INT_MAX;
	for (int i = 0; i < len; i ++) {
		min = min < arr[i] ? min : arr[i];
	}
	for (int i = min + 1; i != INT_MAX; i ++) {
		if (set.find(i) == set.end()) {
			return i;
		}
	}
	return 0;
}


int unformedSum2(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 1;
	}
	int sum = 0;
	int min = INT_MAX;
	for (int i = 0; i < len; i ++) {
		sum += arr[i];
		min = min < arr[i] ? min : arr[i];
	}
	bool* dp = new bool[sum + 1];
	memset(dp, 0, sizeof(bool) * len);
	dp[0] = true;
	for (int i = 0; i < len; i ++) {
		for (int j = sum; j >= arr[i]; j --) {
			dp[j] = dp[j - arr[i]] ? true : dp[j];
		}
	}
	for (int i = min; i < sum + 1; i ++) {
		if (!dp[i]) {
			return i;
		}
	}
	return sum + 1;
}


int main() {
	
	int arr[] = {3, 2, 5};

	std::cout << unformedSum2(arr, 3) << std::endl;

	return 0;
}