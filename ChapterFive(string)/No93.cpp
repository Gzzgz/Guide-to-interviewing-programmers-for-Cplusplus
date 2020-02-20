/*
�����ơ��ַ���ƥ������
����Ŀ�������ַ���str�����о��Բ���'.','*'���ٸ����ַ���exp,���п��Ժ���'.', '*',
'*'�ַ�������exp�����ַ���������������'*'�ַ������ڡ�exp�е�'.'�����κ�һ���ַ���
exp�е�'*'��ʾ��*����ǰһ���ַ�������0�����߶������дһ���������ж�str�Ƿ��ܱ�
expƥ�䡣
���Ѷȡ�У
*/

#include <iostream>
#include <string>


bool isValid(std::string s, std::string e) {

	for (int i = 0; i < s.length(); i ++) {
		if (s[i] == '*' || s[i] == '.') {
			return false;
		}
	}
	for (int i = 0; i < e.length(); i ++) {
		if (e[i] == '*' && (i == 0 || e[i - 1] == '*')) {
			return false;
		}
	}
	return true;
}

bool process(std::string s, std::string e, int si, int ei) {
	
	if (ei == e.length()) {
		return si == s.length();
	}
	if (ei + 1 == e.length() || e[ei + 1] != '*') {
		return si != s.length() && (e[ei] == s[si] || e[ei] == '.')
			&& process(s, e, si + 1, ei + 1);
	}
	while (si != s.length() && (e[ei] == s[si] || e[ei] == '.')) {
		if (process(s, e, si, ei + 2)) {
			return true;
		}
		si++;
	}
	return process(s, e, si, ei + 2);
}

bool isMatch(std::string str1, std::string str2) {

	if (str1 == "" || str2 == "") {
		return false;
	}
	return isValid(str1, str2) ? process(str1, str2, 0, 0) : false;
}

void initDP(std::string s, std::string e, bool** dp) {
	int slen = s.length();
	int elen = e.length();
	dp[slen][elen] = true;
	for (int j = elen - 2; j > -1; j -= 2) {
		if (e[j] != '*' && e[j + 1] == '*') {
			dp[slen][j] = true;
		}
		else {
			break;
		}
	}
	if (slen > 0 && elen > 0) {
		if (e[elen - 1] == '.' || s[slen - 1] == e[elen - 1]) {
			dp[slen - 1][elen - 1] = true;
		}
	}
}

bool isMatchDP(std::string str, std::string exp) {

	if (str == "" || exp == "") {
		return false;
	}
	if (!isValid(str, exp)) {
		return false;
	}
	bool** dp = new bool*[str.length() + 1];
	for (int i = 0; i < str.length() + 1; i ++) {
		dp[i] = new bool[exp.length() + 1];
		for (int j = 0; j < exp.length() + 1; j ++) {
			dp[i][j] = false;
		}
	}
	initDP(str, exp, dp);

	for (int i = str.length() - 1; i > -1; i --) {
		for (int j = exp.length() - 2; j > -1; j --) {
			if (exp[j + 1] != '*') {
				dp[i][j] = (str[i] == exp[j] || exp[j] == '.') && (dp[i + 1][j + 1]);
			}
			else {
				int si = i;
				while (si != str.length() && (str[si] == exp[j] || exp[j] == '.')) {
					if (dp[si][j + 2]) {
						dp[i][j] = true;
						break;
					}
					si++;
				}
				if (dp[i][j] != true) {
					dp[i][j] = dp[si][j + 2];
				}
			}
		}
	}
	bool r = dp[0][0];
	for (int i = 0; i < str.length() + 1; i ++) {
		delete[] dp[i];
	}
	delete[] dp;

	return r;
}

int main() {

	std::string str1 = "abcd", str2 = ".*";

	std::cout << isMatch(str1, str2) << std::endl;
	std::cout << isMatchDP(str1, str2) << std::endl;

	return 0;
}