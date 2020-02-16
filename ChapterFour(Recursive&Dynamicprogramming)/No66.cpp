/*
【名称】数字字符串转换为字母组合的种数
【题目】给定一个字符串str，str全部由数字字符组成，如果str种某一个或某相邻
两个字符组成的子串值在1-26之间，则这个子串可以转换为一个字母。规定"1"转换
为“A”...写一个函数，求str有多少种不同的转换结果，并返回种数。
【难度】尉
*/

#include <iostream>
#include <string>

int process(std::string chs, int i) {
	if (i == chs.length()) {
		return 1;
	}
	if (chs[i] == '0') {
		return 0;
	}
	int res = process(chs, i + 1);
	if (i + 1 < chs.length() && (chs[i] - '0') * 10 + chs[i + 1] - '0' < 27) {
		res += process(chs, i + 2);
	}
	return res;
}

int num1(std::string str) {
	if (str == "") {
		return 0;
	}
	return process(str, 0);
}

int num2(std::string str) {
	if (str == "") {
		return 0;
	}
	int cur = str[str.length() - 1] == '0' ? 0 : 1;
	int next = 1;
	int tmp = 0;
	for (int i = str.length() - 2; i >= 0; i --) {
		if (str[i] == '0') {
			next = cur;
			cur = 0;
		}
		else {
			tmp = cur;
			if ((str[i] - '0') * 10 + str[i + 1] - '0' < 27) {
				cur += next;
			}
			next = tmp;
		}
	}
	return cur;
}

int main() {

	std::string str = "1111";

	std::cout << num2(str) << std::endl;

	return 0;                                                                                             
}