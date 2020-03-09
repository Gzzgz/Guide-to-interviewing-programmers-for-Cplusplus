/*
【名称】最大的leftMax与rightMax之差的绝对值
【题目】给定一个长度为N(N>1)的整型数组arr，可以划分成左右两个部分，左部分
为arr[0...K]，右部分为arr[K+1...N-1]，K可以取值的范围[0,N-2].求这么多划分
方案中，左部分中的最大值减去右部分最大值的绝对值中，最大是多少。
例如[2,7,3,1,1],当左部分为[2,7],有部分为[3,1,1]时，左部分中的最大值减去右部分
最大值的绝对值为4。当左部分为[2,7,3]，右部分为[1,1]时，左部分中的最大值减去
右部分最大值的绝对值为6.还有很多划分方案，但最终返回6.
【难度】校
*/
#include <iostream>

int maxABS1(int* arr, int len) {
	int res = INT_MIN;
	int maxLeft = 0;
	int maxRight = 0;
	for (int i = 0; i < len - 1; i++) {
		maxLeft = INT_MIN;
		for (int j = 0; j < i + 1; j ++) {
			maxLeft = arr[j] > maxLeft ? arr[j] : maxLeft;
		}
		maxRight = INT_MIN;
		for (int j = i + 1; j < len; j ++) {
			maxRight = arr[j] > maxRight ? arr[j] : maxRight;
		}
		res = res >= std::abs(maxLeft - maxRight) ? res : std::abs(maxLeft - maxRight);
	}

	return res;
}

int maxABS2(int* arr, int len) {
	int* left = new int[len];
	int* right = new int[len];
	memset(left, 0, sizeof(int) * len);
	memset(right, 0, sizeof(int) * len);
	left[0] = arr[0];
	right[len - 1] = arr[len - 1];
	for (int i = 1;i < len;i ++) {
		left[i] = left[i - 1] > arr[i] ? left[i - 1] : arr[i];
	}
	for (int i = len - 2; i > -1; i --) {
		right[i] = right[i + 1] > arr[i] ? right[i + 1] : arr[i];
	}
	int max = 0;
	for (int i = 0; i < len - 1; i ++) {
		max = max > std::abs(left[i] - right[i + 1]) ? max :
			std::abs(left[i] - right[i + 1]);
	}
	return max;
}

int maxABS3(int* arr, int len) {
	int max = INT_MIN;
	for (int i = 0; i < len; i ++) {
		max = arr[i] > max ? arr[i] : max;
	}
	return max - (arr[0] < arr[len - 1] ? arr[0] : arr[len - 1]);
}

int main() {

	int arr[] = {2,7,3,1,1};
	std::cout << maxABS3(arr, 5) << std::endl;

	return 0;
}