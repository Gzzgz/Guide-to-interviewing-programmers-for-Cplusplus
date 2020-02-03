/*
【名称】判断两个字符串是否互为变形词
【题目】给定两个字符串str1, str2，如果 str1和str2中出现的字符种类一样且
每种字符出现的次数也一样，那么 str1, str2互为变形词。请实现函数判断两个
字符串是否互为变形词。
【难度】士
*/

#include <iostream>

bool isDeformation(std::string str1, std::string str2) {

	if (str1 == "" || str2 == "" || str1.length() != str2.length()) {
		return false;
	}
	int map[256] = {0};
	for (int i = 0; i < str1.length(); i ++) {
		map[str1[i]]++;
	}
	for (int i = 0; i < str2.length(); i ++) {
		if (map[str2[i]]-- == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	std::string str1 = "123";
	std::string str2 = "321";
	std::string str3 = "221";

	std::cout << "str1 str2: " << isDeformation(str1, str2) << std::endl;
	std::cout << "str1 str3: " << isDeformation(str1, str3) << std::endl;

	return 0;
}