/*
【名称】最长递增子序列
【题目】给定数组arr, 返回arr的最长递增子序列
要求：如果arr长度为N,请实现时间复杂度为O(NlogN)的方法
【难度】校
*/
#include <iostream>

void getdp1(int* dp, int* arr, int len) {
	for (int i = 0; i < len; i ++) {
		dp[i] = 1;
		for (int j = 0; j < i; j ++) {
			if (arr[i] > arr[j]) {
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}
	}
}

void generateLTS(int* arr, int length, int* dp) {
	int len = 0;
	int index = 0;
	for (int i = 0; i < length; i ++) {
		if (dp[i] > len) {
			len = dp[i];
			index = i;
		}
	}
	int* lis = new int[len];
	int count = len;

	lis[--len] = arr[index];
	for (int i = index - 1; i >= 0; i--) {
		if (arr[i] < arr[index] && dp[i] == dp[index] - 1) {
			lis[--len] = arr[i];
			index = i;
		}
	}

	for (int i = 0; i < count; i ++) {
		std::cout << lis[i] << std::endl;
	}
	delete[] lis;
}

void lis1(int* arr, int len) {
	if (len == 0) {
		return;
	}
	int* dp = new int[len];
	getdp1(dp, arr, len);
	generateLTS(arr, len, dp);
	delete[] dp;
}

void getdp2(int* dp, int* arr, int len) {
	int* ends = new int[len];
	ends[0] = arr[0];
	dp[0] = 1;
	int right = 0;
	int left = 0;
	int r = 0;
	int m = 0;
	for (int i = 1; i < len; i ++) {
		left = 0;
		r = right;
		while (left <= r) {
			m = (left + r) / 2;
			if (arr[i] > ends[m]) {
				left = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		right = right > left ? right : left;
		ends[left] = arr[i];
		dp[i] = left + 1;
	}
}

void lis2(int* arr, int len) {
	if (len == 0) {
		return;
	}
	int* dp = new int[len];
	getdp2(dp, arr, len);
	generateLTS(arr, len, dp);
	delete[] dp;
}

int main() {

	int arr[] = {2,1,5,3,6,4,8,9,7};

	lis2(arr, 9);

	return 0;
}