/*
【名称】去掉字符串中连续出现k个0的子串
【题目】给定一个字符串str和一个整数k，如果 str中正好有连续的k个'0'字符
出现时，把k个连续的'0'字符去除，返回处理后的字符串
【难度】士
*/

#include <iostream>

std::string removeKZeros(std::string str, int k) {
	if (str == "" || k < 1) {
		return str;
	}

	int count = 0, start = -1;
	int* flag = new int[str.length()];
	memset(flag, 0, sizeof(int) * str.length());

	for (int i = 0; i < str.length(); i ++) {
		if (str[i] == '0') {
			count++;
			start = (start == -1) ? i : start;
		}
		else {
			if (count == k) {
				while (count -- != 0) {
					flag[start++] = 1;
				}
			}
			count = 0;
			start = -1;
		}
	}
	if (count == k) {
		while (count -- != 0) {
			flag[start++] = 1;
		}
	}

	std::string res = "";
	for (int i = 0; i < str.length(); i ++) {
		if (flag[i] == 0) {
			res += str[i];
		}
	}
	delete[] flag;

	return res;
}


int main() {

	std::string str = "A0000B000";
	int k = 3;
	std::string res = removeKZeros(str, k);
	
	std::cout << res.c_str() << std::endl;

	return 0;
}