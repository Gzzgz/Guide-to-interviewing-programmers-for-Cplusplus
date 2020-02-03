/*
【名称】找到字符串的最长无重复字符子串
【题目】给定一个字符串str，返回str的最长无重复字符子串的长度
例如：
str = "abcd",返回4
str = "aabcb",返回3
要求：如果str的长度为N,请实现时间复杂度为O(N)的方法
【难度】尉
*/

#include <iostream>

int maxUnique(std::string str) {
	if (str == "") {
		return 0;
	}
	int map[256];
	for (int i = 0; i < 256; i ++) {
		map[i] = -1;
	}
	int len = 0;
	int pre = -1;
	int cur = 0;
	for (int i = 0; i != str.length(); i ++) {
		pre = (pre > map[str[i]]) ? pre : map[str[i]];
		cur = i - pre;
		map[str[i]] = i;
		len = len > cur ? len : cur;
	}
	return len;
}

int main() {

	std::string str1 = "abcd";
	std::string str2 = "aabcb";

	std::cout << maxUnique(str2) << std::endl;

	return 0;
}