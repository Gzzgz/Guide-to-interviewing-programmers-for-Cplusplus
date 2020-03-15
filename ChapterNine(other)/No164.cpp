/*
【名称】画匠问题
【题目】给定一个整型数组arr，数组中的每个值都是正数，表示完成一幅画需要的时间，
再给定一个整数num表示画匠的数量，每个画匠只能画连在一起的画作。所有的画家
并行工作，请返回完成所有的画作需要的最少时间。
【难度】校
*/
#include <iostream>

int maxf(int a, int b) {
	return a > b ? a : b;
}

int minf(int a, int b) {
	return a < b ? a : b;
}

int solution1(int* arr, int len, int num) {
	if (arr == nullptr || len == 0 || num < 1) {
		return 0;
	}
	int* sumArr = new int[len];
	int* map = new int[len];
	sumArr[0] = arr[0];
	map[0] = arr[0];
	for (int i = 1; i < len; i ++) {
		sumArr[i] = sumArr[i - 1] + arr[i];
		map[i] = sumArr[i];
	}
	for (int i = 1; i < num; i ++) {
		for (int j = len - 1; j > i - 1; j --) {
			int min = INT_MAX;
			for (int k = i - 1; k < j; k ++) {
				int cur = maxf(map[k], sumArr[j] - sumArr[k]);
				min = minf(min, cur);
			}
			map[j] = min;
		}
	}
	return map[len - 1];
}

int solution2(int* arr, int len, int num) {
	if (arr == nullptr || len == 0 || num < 1) {
		return 0;
	}
	int* sumArr = new int[len];
	int* map = new int[len];
	memset(sumArr, 0, sizeof(int) * len);
	memset(map, 0, sizeof(int) * len);
	sumArr[0] = arr[0];
	map[0] = arr[0];
	for (int i = 1; i < len; i ++) {
		sumArr[i] = sumArr[i - 1] + arr[i];
		map[i] = sumArr[i];
	}
	int* cands = new int[len];
	memset(cands, 0, sizeof(int) * len);
	for (int i = 1; i < num; i ++) {
		for (int j = len - 1; j > i - 1; j --) {
			int minPar = cands[j];
			int maxPar = j == len - 1 ? j : cands[j + 1];
			int min = INT_MAX;
			for (int k = minPar; k < maxPar + 1; k ++) {
				int cur = maxf(map[k], sumArr[j] - sumArr[k]);
				if (cur <= min) {
					min = cur;
					cands[j] = k;
				}
			}
			map[j] = min;
		}
	}
	return map[len - 1];
}

int getNeedNum(int* arr, int len, int lim) {
	int res = 1;
	int stepSum = 0;
	for (int i = 0; i < len; i ++) {
		if (arr[i] > lim) {
			return INT_MAX;
		}
		stepSum += arr[i];
		if (stepSum > lim) {
			res++;
			stepSum = arr[i];
		}
	}
	return res;
}

int solution3(int* arr, int len, int num) {
	if (arr == nullptr || len == 0 || num < 1) {
		return 0;
	}
	if (len < num) {
		int max = INT_MIN;
		for (int i = 0; i < len; i ++) {
			max = maxf(max, arr[i]);
		}
		return max;
	}
	else {
		int minSum = 0;
		int maxSum = 0;
		for (int i = 0; i < len; i ++) {
			maxSum += arr[i];
		}
		while (minSum != maxSum - 1) {
			int mid = (minSum + maxSum) / 2;
			if (getNeedNum(arr,len, mid) > num) {
				minSum = mid;
			}
			else {
				maxSum = mid;
			}
		}
		return maxSum;
	}
}

int main() {

	int arr[] = {1,1,1,4,3};
	std::cout << solution3(arr, 5, 3) << std::endl;

	return 0;
}
