/*
【名称】换钱的方法数
【题目】给定数组arr, arr中所有的值都为正数且不重复。每个值代表一种面值的货币，
每种面值的货币可以使用任意张，再给定一个整数aim代表要找的钱数，求换钱有多少种方法。
【难度】尉
*/

#include <iostream>

int process1(int* arr, int len, int index, int aim) {
	int res = 0;
	if (index == len) {
		res = aim == 0 ? 1 : 0;
	}
	else {
		for (int i = 0; arr[index] * i <= aim; i ++) {
			res += process1(arr, len, index + 1, aim - arr[index] * i);
		}
	}
	return res;
}

int coins1(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return 0;
	}
	return process1(arr, len, 0, aim);
}

int process2(int* arr, int len, int index, int aim, int** map) {
	int res = 0;
	if (index == len) {
		res = aim == 0 ? 1 : 0;
	}
	else {
		int mapvalue = 0;
		for (int i = 0; arr[index] * i <= aim; i ++) {
			mapvalue = map[index + 1][aim - arr[index] * i];
			if (mapvalue != 0) {
				res += mapvalue == -1 ? 0 : mapvalue;
			}
			else {
				res += process2(arr, len, index + 1, aim - arr[index] * i, map);
			}
		}
	}
	map[index][aim] = res == 0 ? -1 : res;
	return res;
}

int coins2(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return 0;
	}
	int** map = new int*[len + 1];
	for (int i = 0; i <= len; i ++) {
		map[i] = new int[aim + 1];
		for (int j = 0; j < aim + 1; j ++) {
			map[i][j] = 0;
		}
	}
	int res = process2(arr, len, 0, aim, map);
	for (int i = 0; i < len + 1; i ++) {
		delete[] map[i];
	}
	delete[] map;
	return res;
}

int coins3(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return 0;
	}
	int ** dp = new int*[len];
	for (int i = 0; i < len; i ++) {
		dp[i] = new int[aim + 1];
		for (int j = 0; j < aim + 1; j ++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < len; i ++) {
		dp[i][0] = 1;
	}
	for (int j = 1; arr[0] * j <= aim; j ++) {
		dp[0][arr[0] * j] = 1;
	}
	int num = 0;
	for (int i = 1; i < len; i ++) {
		for (int j = 1; j <= aim; j ++) {
			num = 0;
			for (int k = 0; j - arr[i] * k >= 0; k ++) {
				num += dp[i - 1][j - arr[i] * k];
			}
			dp[i][j] = num;
		}
	}
	int res = dp[len - 1][aim];
	for (int i = 0; i < len; i ++) {
		delete[] dp[i];
	}
	delete[] dp;
	return res;
}

int coins4(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return 0;
	}
	int ** dp = new int*[len];
	for (int i = 0; i < len; i++) {
		dp[i] = new int[aim + 1];
		for (int j = 0; j < aim + 1; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < len; i++) {
		dp[i][0] = 1;
	}
	for (int j = 1; arr[0] * j <= aim; j++) {
		dp[0][arr[0] * j] = 1;
	}
	for (int i = 1; i < len; i ++) {
		for (int j = 1; j <= aim; j ++) {
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += j - 2 * arr[i] >= 0 ? dp[i][j - 2 * arr[i]] + 1 : 0;
		}
	}
	int res = dp[len - 1][aim];
	for (int i = 0; i < len; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	return res;
}

int coins5(int* arr, int len, int aim) {
	if (len == 0 || aim < 0) {
		return 0;
	}
	int* dp = new int[aim + 1];
	for (int i = 0; arr[0] * i <= aim; i ++) {
		dp[arr[0] * i] = 1;
	}
	for (int i = 1; i < len; i ++) {
		for (int j = 1; j <= aim; j ++) {
			dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
		}
	}
	int res = dp[aim];
	delete[] dp;
	return res;
}

int main() {

	int arr[4] = {5, 10, 25, 1};
	int aim = 15;

	std::cout << coins5(arr, 4, aim) << std::endl;


	return 0;
}