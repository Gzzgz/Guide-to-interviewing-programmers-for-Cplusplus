/*
【名称】邮局选址问题
【题目】一条直线上有居民点，邮局只能建在居民点上。给定一个有序整型数组arr,
每个值表示居民点的一维坐标，再给定一个正数num，表示邮局数量。选择num个居民
点建立num个邮局，使所有的居民点到邮局的总距离最短，返回最短的总距离。
【难度】校
*/
#include <iostream>


int minDistances1(int* arr, int len, int num) {
	if (arr == nullptr || num < 1 || len < num) {
		return 0;
	}
	int** w = new int*[len + 1];
	for (int i = 0; i < len + 1; i++) {
		w[i] = new int[len + 1];
		for (int j = 0; j < len + 1; j++) {
			w[i][j] = 0;
		}
	}
	for (int i = 0; i < len; i ++) {
		for (int j = i + 1; j < len; j ++) {
			w[i][j] = w[i][j - 1] + arr[j] - arr[(i + j) / 2];
		}
	}
	int** dp = new int*[num];
	for (int i = 0; i < num; i ++) {
		dp[i] = new int[len];
	}
	for (int j = 0; j < len; j ++) {
		dp[0][j] = w[0][j];
	}
	for (int i = 1; i < num; i ++) {
		for (int j = i + 1; j < len; j ++) {
			dp[i][j] = INT_MAX;
			for (int k = 0; k <= j; k ++) {
				dp[i][j] = dp[i][j] < dp[i - 1][k] + w[k + 1][j] ?
					dp[i][j] : dp[i - 1][k] + w[k + 1][j];
			}
		}
	}
	return dp[num - 1][len - 1];
}

int minDistances2(int* arr, int len, int num) {
	if (arr == nullptr || num < 1 || len < num) {
		return 0;
	}
	int** w = new int*[len + 1];
	for (int i = 0; i < len + 1; i ++) {
		w[i] = new int[len + 1];
		for (int j = 0; j < len + 1; j ++) {
			w[i][j] = 0;
		}
	}
	for (int i = 0; i < len; i ++) {
		for (int j = i + 1; j < len; j ++) {
			w[i][j] = w[i][j - 1] + arr[j] - arr[(i + j) / 2];
		}
	}
	int** dp = new int*[num];
	int** s = new int*[num];
	for (int i = 0; i < num; i ++) {
		dp[i] = new int[len];
		s[i] = new int[len];
	}
	for (int j = 0; j < len; j++) {
		dp[0][j] = w[0][j];
		s[0][j] = 0;
	}
	int mink = 0;
	int maxk = 0;
	int cur = 0;
	for (int i = 1; i < num; i ++) {
		for (int j = len - 1; j > i; j --) {
			mink = s[i - 1][j];
			maxk = j == len - 1 ? len - 1 : s[i][j + 1];
			dp[i][j] = INT_MAX;
			for (int k = mink; k <= maxk; k ++) {
				cur = dp[i - 1][k] + w[k + 1][j];
				if (cur <= dp[i][j]) {
					dp[i][j] = cur;
					s[i][j] = k;
				}
			}
		}
	}
	return dp[num - 1][len - 1];
}

int main() {

	int arr[] = {1,2,3,4,5,1000};
	std::cout << minDistances1(arr, 6, 2) << std::endl;

	return 0;
}