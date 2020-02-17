/*
�����ơ���������ַ�ʹ�ַ������嶼�ǻ����ַ���
����Ŀ������һ���ַ���str�����������str������λ������ַ����뷵�������
�ַ����ٵ�����£���str���嶼�ǻ����ַ�����һ�ֽ����
��������Ŀ������һ���ַ���str���ٸ���str��������������ַ���strlps����
����������ַ����ٵ�����£���str���嶼�ǻ����ַ�����һ�ֽ������������
��ԭ�������һ��������������ʱ�临�Ӷȱ�ԭ�����ʵ�ֵͣ�
���Ѷȡ�У
*/
#include <iostream>
#include <string>

void getDP(int** dp, std::string str) {

	for (int j = 1; j < str.length(); j ++) {

		dp[j - 1][j] = (str[j - 1] == str[j]) ? 0 : 1;

		for (int i = j - 2; i > -1; i --) {
			if (str[i] == str[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
			else {
				dp[i][j] = dp[i + 1][j] < dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
				dp[i][j] += 1;
			}
		}
	}
}

std::string getPalindrome1(std::string str) {
	if (str.length() < 2) {
		return str;
	}
	int** dp = new int*[str.length()];
	for (int i = 0; i < str.length(); i ++) {
		dp[i] = new int[str.length()];
		for (int j = 0; j < str.length(); j ++) {
			dp[i][j] = 0;
		}
	}
	getDP(dp, str);

	char* res = new char[str.length() + dp[0][str.length() - 1]];
	int i = 0;
	int j = str.length() - 1;
	int resl = 0;
	int resr = str.length() + dp[0][str.length() - 1] - 1;
	while (i <= j) {
		if (str[i] == str[j]) {
			res[resl++] = str[i++];
			res[resr--] = str[j--];
		}else if(dp[i][j - 1] < dp[i + 1][j]) {
			res[resl++] = str[j];
			res[resr--] = str[j --];
		}
		else {
			res[resl++] = str[i];
			res[resr--] = str[i ++];
		}
	}
	std::string r(res);
	delete[] res;

	for (int i = 0; i < str.length(); i ++) {
		delete[] dp[i];
	}
	delete[] dp;

	return r;
}

void set(char* res, int resl, int resr, std::string str, 
	int ls, int le, int rs, int re) {
	for (int i = ls; i < le; i ++) {
		res[resl++] = str[i];
		res[resr--] = str[i];
	}
	for (int i = re; i > rs; i --) {
		res[resl++] = str[i];
		res[resr--] = str[i];
	}
}

std::string getPalindrome2(std::string str, std::string strlps) {
	if (str == "") {
		return "";
	}
	char* res = new char[2 * str.length() - strlps.length()];
	int sl = 0;
	int sr = str.length() - 1;
	int lpsl = 0;
	int lpsr = strlps.length() - 1;
	int resl = 0;
	int resr = 2 * str.length() - strlps.length() - 1;
	int tmpl = 0;
	int tmpr = 0;
	while (lpsl <= lpsr) {
		tmpl = sl;
		tmpr = sr;
		while (str[sl] != strlps[lpsl]) {
			sl++;
		}
		while (str[sr] != strlps[lpsr]) {
			sr--;
		}
		set(res, resl, resr, str, tmpl, sl, sr, tmpr);
		resl += sl - tmpl + tmpr - sr;
		resr -= sl - tmpl + tmpr - sr;
		res[resl++] = str[sl++];
		res[resr--] = str[sr--];
		lpsl++;
		lpsr--;
	}
	std::string r(res);
	delete[] res;

	return r;
}

int main() {

	std::string str1 = "A1B21C", strlps = "121";

	std::cout << getPalindrome2(str1, strlps).c_str() << std::endl;

	return 0;
}