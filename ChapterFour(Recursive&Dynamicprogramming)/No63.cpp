/*
【名称】最小编辑代价
【题目】给定两个字符串str1,str2，再给定三个整数ic, dc, rc，分别代表插入、
删除和替换 一个字符的代价，返回将str1编辑成str2的最小代价。
【难度】校
*/
#include <iostream>
#include <string>

int minCost1(std::string str1, std::string str2, int ic, int dc, int rc) {

	int row = str1.length() + 1;
	int col = str2.length() + 1;
	int** dp = new int*[row];
	for (int i = 0; i < row; i ++) {
		dp[i] = new int[col];
		for (int j = 0; j < col; j ++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < row; i ++) {
		dp[i][0] = dc * i;
	}
	for (int j = 1; j < col; j ++) {
		dp[0][j] = ic * j;
	}
	for (int i = 1; i < row; i ++) {
		for (int j = 1; j < col; j ++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + rc;
			}
			dp[i][j] = dp[i][j] < dp[i][j - 1] + ic ? dp[i][j] : dp[i][j - 1] + ic;
			dp[i][j] = dp[i][j] < dp[i - 1][j] + dc ? dp[i][j] : dp[i - 1][j] + dc;
		}
	}
	int res = dp[row - 1][col - 1];
	for (int i = 0; i < row; i ++) {
		delete[] dp[i];
	}
	delete[] dp;
	return res;
}

int minCost2(std::string str1, std::string str2, int ic, int dc, int rc) {
	std::string longs = str1.length() >= str2.length() ? str1 : str2;
	std::string shorts = str1.length() < str2.length() ? str1 : str2;
	if (str1.length() < str2.length()) {
		int tmp = ic;
		ic = dc;
		dc = tmp;
	}
	int* dp = new int[shorts.length() + 1];
	for (int i = 1; i <= shorts.length() + 1; i ++) {
		dp[i] = ic * i;
	}
	for (int i = 1; i <= longs.length(); i ++) {
		int pre = dp[0];
		dp[0] = dc * i;
		for (int j = 1; j <= shorts.length(); j ++) {
			int tmp = dp[j];
			if (longs[i - 1] == shorts[j - 1]) {
				dp[j] = pre;
			}
			else {
				dp[j] = pre + rc;
			}
			dp[j] = dp[j] < dp[j - 1] + ic ? dp[j] : dp[j - 1] + ic;
			dp[j] = dp[j] < tmp + dc ? dp[j] : tmp + dc;
			pre = tmp;
		}
	}
	int res = dp[shorts.length()];
	delete[] dp;
	return res;

}

int main() {

	std::string str1 = "abc", str2 = "adc";
	int ic = 5, dc = 3, rc = 2;

	std::cout << minCost2(str1, str2, ic, dc, rc) << std::endl;

	return 0;
}