/*
【名称】最长公共子序列问题
【题目】给定两个字符串str1,str2，返回两个字符串的最长公共子序列
【难度】尉
*/

#include <iostream>
#include <string>

void getdp(int** dp, std::string str1, std::string str2) {

	dp[0][0] = str1[0] == str2[0] ? 1 : 0;
	for (int i = 1; i < str1.length(); i ++) {
		int tmp = str1[i] == str2[0] ? 1 : 0;
		dp[i][0] = dp[i - 1][0] > tmp ? dp[i - 1][0] : tmp;
	}
	for (int j = 1; j < str2.length(); j ++) {
		int tmp = str1[0] == str2[j] ? 1 : 0;
		dp[0][j] = dp[0][j - 1] > tmp ? dp[0][j - 1] : tmp;
	}
	for (int i = 1; i < str1.length(); i ++) {
		for (int j = 1; j < str2.length(); j ++) {
			dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			if (str1[i] == str2[j]) {
				dp[i][j] = (dp[i][j] > (dp[i - 1][j - 1] + 1)) ? dp[i][j] : (dp[i - 1][j - 1] + 1);
			}
		}
	}
	
}

std::string lcse(std::string str1, std::string str2) {
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
	int m = str1.length() - 1;
	int n = str2.length() - 1;
	int index = dp[m][n] - 1;
	char* res = new char[dp[m][n]];

	while (index >= 0) {
		if (n > 0 && dp[m][n] == dp[m][n - 1]) {
			n--;
		}
		else if (m > 0 && dp[m][n] == dp[m - 1][n]) {
			m--;
		}
		else {
			res[index --] = str1[m];
			m--;
			n--;
			
		}
	}

	for (int i = 0; i < str1.length(); i ++) {
		delete[] dp[i];
	}
	delete[] dp;

	std::string rr(res);
	delete[] res;

	return rr;
}

int main() {

	std::string str1 = "1A2C3D4B56";
	std::string str2 = "B1D23CA45B6A";

	std::cout << lcse(str1, str2).c_str() << std::endl;

	return 0;
}