/*
�����ơ��ַ����Ľ������
����Ŀ�����������ַ���str1,str2,aim�����aim�����ҽ���������str1,str2��
�����ַ���������aim������str1���ַ�֮�䱣��ԭ����str1�е�˳������str2
���ַ�֮�䱣��ԭ����str2�е�˳����ô��aim��str1,str2�Ľ�����ɡ�ʵ��һ
���������ж�aim�Ƿ���str1,str2������ɡ�
���Ѷȡ�У
*/
#include <iostream>
#include <string>


bool isCross1(std::string str1, std::string str2, std::string aim) {
	if (str1 == "" || str2 == "") {
		return false;
	}
	if (str1.length() + str2.length() != aim.length()) {
		return false;
	}
	bool** dp = new bool*[str1.length() + 1];
	for (int i = 0; i <= str1.length(); i ++) {
		dp[i] = new bool[str2.length() + 1];
		for (int j = 0; j <= str2.length(); j ++) {
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	for (int i = 1; i <= str1.length(); i ++) {
		if (str1[i - 1] != aim[i - 1]) {
			break;
		}
		dp[i][0] = true;
	}
	for (int j = 1; j <= str2.length(); j ++) {
		if (str2[j - 1] != aim[j - 1]) {
			break;
		}
		dp[0][j] = true;
	}
	for (int i = 1; i <= str1.length(); i ++) {
		for (int j = 1; j <= str2.length(); j ++) {
			if ((str1[i - 1] == aim[i + j - 1] && dp[i - 1][j])
				|| (str2[j - 1] == aim[i + j - 1] && dp[i][j - 1])) {
				dp[i][j] = true;
			}
		}
	}
	bool res = dp[str1.length()][str2.length()];
	for (int i = 0; i < str1.length(); i ++) {
		delete[] dp[i];
	}
	delete[] dp;

	return res;
}

bool isCross2(std::string str1, std::string str2, std::string aim) {
	if (str1 == "" || str2 == "") {
		return false;
	}
	if (str1.length() + str2.length() != aim.length()) {
		return false;
	}
	std::string longs = str1.length() >= str2.length() ? str1 : str2;
	std::string shorts = str1.length() < str2.length() ? str1 : str2;
	bool* dp = new bool[shorts.length() + 1];
	for (int i = 0; i < shorts.length() + 1; i ++) {
		dp[i] = false;
	}
	dp[0] = true;
	for (int i = 1; i <= shorts.length(); i ++) {
		if (shorts[i - 1] != aim[i - 1]) {
			break;
		}
		dp[i] = true;
	}
	for (int i = 1; i <= longs.length(); i ++) {
		dp[0] = dp[0] && (longs[i - 1] == aim[i - 1]);
		for (int j = 1; j <= shorts.length(); j ++) {
			if (((longs[i - 1] == aim[i + j - 1]) && dp[j])
				|| ((shorts[j - 1] == aim[i + j - 1]) && dp[j - 1])) {
				dp[j] = true;
			}
			else {
				dp[j] = false;
			}
		}
	}
	bool res = dp[shorts.length()];
	delete[] dp;
	return res;
}

int main() {

	std::string str1 = "AB", str2 = "12";

	std::cout << isCross2(str1, str2, "AB12") << std::endl;

	return 0;
}