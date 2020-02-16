/*
【名称】最长公共子串问题
【题目】给定两个字符串str1,str2，返回两个字符串的最长公共子串
要求：如果str1长度为M, str2长度为N, 实现时间复杂度为O(M*N)，额外空间复杂度为O(1)
【难度】校
*/

#include <iostream>
#include <string>

void getdp(int** dp, std::string str1, std::string str2) {
	for (int i = 0; i < str1.length(); i ++) {
		if (str1[i] == str2[0]) {
			dp[i][0] = 1;
		}
	}
	for (int j = 1; j < str2.length(); j ++) {
		if (str1[0] == str2[j]) {
			dp[0][j] = 1;
		}
	}
	for (int i = 1; i < str1.length(); i ++) {
		for (int j = 1; j < str2.length(); j ++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
}

std::string lcst1(std::string str1, std::string str2) {
	if (str1 == "" || str2 == "") {
		return "";
	}
	int** dp = new int*[str1.length()];
	for (int i = 0; i < str1.length(); i ++) {
		dp[i] = new int[str2.length()];
		for (int j = 0; j < str2.length(); j ++) {
			dp[i][j] = 0;
		}
	}
	getdp(dp, str1, str2);
	int end = 0;
	int max = 0;
	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j ++) {
			if (dp[i][j] > max) {
				end = i;
				max = dp[i][j];
			}
		}
	}
	std::string res = "";
	for (int i = end - max + 1; i < end + 1; i ++) {
		res += std::string(1, str1[i]);
	}
	for (int i = 0; i < str1.length(); i ++) {
		delete[] dp[i];
	}
	delete[] dp;
	return res;
}

std::string lcst2(std::string str1, std::string str2) {
	if (str1 == "" || str2 == "") {
		return "";
	}
	int row = 0;
	int col = str2.length() - 1;
	int max = 0;
	int end = 0;
	while (row < str1.length()) {
		int i = row;
		int j = col;
		int len = 0;
		while (i < str1.length() && j < str2.length()) {
			if (str1[i] != str2[j]) {
				len = 0;
			}
			else {
				len++;
			}
			if (len > max) {
				end = i;
				max = len;
			}
			i ++;
			j ++;
		}
		if (col > 0) {
			col--;
		}
		else {
			row++;
		}
	}
	std::string res = "";
	for (int i = end - max + 1; i < end + 1; i++) {
		res += std::string(1, str1[i]);
	}
	return res;
}


int main() {

	std::string str1 = "1AB2345CD", str2 = "12345EF";

	std::cout << lcst2(str1, str2).c_str() <<std::endl;

	return 0;
}