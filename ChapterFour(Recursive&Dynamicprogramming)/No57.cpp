/*
�����ơ���Ǯ����С������
����Ŀ����������arr��arr�����е�ֵ���������Ҳ��ظ���ÿ��ֵ����һ����ֵ��
���ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ��ٸ���һ������aim����Ҫ�ҵ�Ǯ���������
aim�����ٻ�����
��������Ŀ����������arr, arr�����е�ֵ����������ÿ��ֵ������һ��Ǯ����ֵ��
�ٸ���һ������aim����Ҫ�ҵ�Ǯ���������aim�����ٻ�����
���Ѷȡ�ξ
*/

#include <iostream>

int minCoins1(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return - 1;
	}
	int max = INT_MAX;
	int** dp = new int*[len];
	for (int i = 0; i < len; i ++) {
		dp[i] = new int[aim + 1];
		for (int j = 0; j < aim + 1; j ++) {
			dp[i][j] = 0;
		}
	}
	for (int j = 1; j <= aim; j ++) {
		dp[0][j] = max;
		if (j - arr[0] >= 0 && dp[0][j - arr[0]] != max) {
			dp[0][j] = dp[0][j - arr[0]] + 1;
		}
	}
	int left = 0;
	for (int i = 1; i < len; i ++) {
		for (int j = 1; j <= aim; j ++) {
			left = max;
			if (j - arr[i] >= 0 && dp[i][j - arr[i]] != max) {
				left = dp[i][j - arr[i]] + 1;
			}
			dp[i][j] = left < dp[i - 1][j] ? left : dp[i - 1][j];
		}
	}
	int r = dp[len - 1][aim] != max ? dp[len - 1][aim] : -1;
	for (int i = 0; i < len; i ++) {
		delete[] dp[i];
	}
	delete[] dp;
	return r;
}

int minCoins2(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return -1;
	}
	int max = INT_MAX;
	int* dp = new int[aim + 1];
	dp[0] = 0;
	for (int j = 1; j <= aim; j ++) {
		dp[j] = max;
		if (j - arr[0] >= 0 && dp[j - arr[0]] != max) {
			dp[j] = dp[j - arr[0]] + 1;
		}
	}
	int left = 0;
	for (int i = 1; i < len; i ++) {
		for (int j = 1; j <= aim; j ++) {
			left = max;
			if (j - arr[i] >= 0 && dp[j - arr[i]] != max) {
				left = dp[j - arr[i]] + 1;
			}
			dp[j] = left < dp[j] ? left : dp[j];
		}
	}
	int r = dp[aim] != max ? dp[aim] : -1;
	delete[] dp;

	return r;
}

int minCoins3(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return -1;
	}
	int max = INT_MAX;
	int** dp = new int*[len];
	for (int i = 0; i < len; i ++) {
		dp[i] = new int[aim + 1];
		for (int j = 0; j < aim + 1; j ++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < aim + 1; i ++) {
		dp[0][i] = max;
	}
	if (arr[0] <= aim) {
		dp[0][arr[0]] = 1;
	}
	int leftup = 0;
	for (int i = 1; i < len; i ++) {
		for (int j = 1; j <= aim; j ++) {
			leftup = max;
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]] != max) {
				leftup = dp[i - 1][j - arr[i]] + 1;
			}
			dp[i][j] = leftup < dp[i - 1][j] ? leftup : dp[i - 1][j];
		}
	}
	int r = dp[len - 1][aim] != max ? dp[len - 1][aim] : -1;
	delete[] dp;
	return r;
}

int minCoins4(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return -1;
	}
	int max = INT_MAX;
	int* dp = new int[aim + 1];
	memset(dp, 0, sizeof(int) * (aim + 1));
	for (int j = 1; j <= aim; j ++) {
		dp[j] = max;
	}
	if(arr[0] <= aim) {
		dp[arr[0]] = 1;
	}
	int leftup = 0;
	for (int i = 1; i < len; i ++) {
		for (int j = aim; j > 0; j--) {
			leftup = max;
			if (j - arr[i] >= 0 && dp[j - arr[i]] != max) {
				leftup = dp[j - arr[i]] + 1;
			}
			dp[j] = leftup < dp[j] ? leftup : dp[j];
		}
	}

	int r = dp[aim] != max ? dp[aim] : -1;
	delete[] dp;
	return r;
}

int main() {

	int arr[3] = {5, 2, 3};

	std::cout << minCoins4(arr, 3, 5) << std::endl;

	return 0;
}