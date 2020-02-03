/*
�����ơ������ַ�������Ч�Ժ����Ч����
����Ŀ������һ���ַ���str,�ж��ǲ���������Ч�������ַ���.
��������Ŀ������һ�������ַ���str�����������Ч�����Ӵ���
���Ѷȡ�ԭ���⣺ʿ �������⣺ξ
*/

#include <iostream>


bool isValid(std::string str) {
	if (str == "") {
		return false;
	}
	int status = 0;
	for (int i = 0; i < str.length(); i ++) {
		if (str[i] != ')' && str[i] != '(') {
			return false;
		}
		if (str[i] == ')' && -- status < 0) {
			return false;
		}
		if (str[i] == '(') {
			status++;
		}
	}
	return status == 0;
}

int maxLength(std::string str) {
	if (str == "") {
		return 0;
	}
	int* dp = new int[str.length()];
	memset(dp, 0, sizeof(int) * str.length());

	int pre = 0;
	int res = 0;
	for (int i = 1; i < str.length(); i ++) {
		if (str[i] == ')') {
			pre = i - dp[i - 1] - 1;
			if (pre >= 0 && str[pre] == '(') {
				dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
			}
		}
		res = res > dp[i] ? res : dp[i];
	}
	delete[] dp;
	return res;
}

int main() {

	std::string arr1 = "()(()()(";
	std::string arr2 = "()(()())";

	std::cout << isValid(arr2) << std::endl;
	std::cout << maxLength(arr2) << std::endl;

	return 0;
}