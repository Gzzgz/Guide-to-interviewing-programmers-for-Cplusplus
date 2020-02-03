/*
�����ơ��������ٷָ���
����Ŀ������һ���ַ���str�����ذ�strȫ���гɻ����Ӵ�����С�ָ���
���Ѷȡ�ξ
*/

#include <iostream>

int minCut(std::string str) {
	if (str == "") {
		return 0;
	}
	int* dp = new int[str.length() + 1];
	dp[str.length()] = -1;
	bool** p = new bool*[str.length()];
	for (int i = 0; i < str.length(); i ++) {
		p[i] = new bool[str.length()];
		memset(p[i], 0, sizeof(bool) * str.length());
	}
	
	for (int i = str.length() - 1; i >= 0; i --) {
		dp[i] = INT_MAX;
		for (int j = i; j < str.length(); j ++) {
			if (str[i] == str[j] && ((j - i) < 2 || p[i + 1][j - 1])) {
				p[i][j] = true;
				dp[i] = dp[i] < dp[j + 1] + 1 ? dp[i] : dp[j + 1] + 1;
			}
		}
	}
	for (int i = 0; i < str.length(); i++) {
		delete[] p[i];
	}
	delete[] p;

	int res = dp[0];
	delete[] dp;

	return res;
}

int main() {

	std::string str1 = "aba";
	std::string str2 = "acdcdcdad";

	std::cout <<minCut(str2) << std::endl;

	return 0;
}