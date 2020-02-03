/*
�����ơ��ҵ��ַ���������ظ��ַ��Ӵ�
����Ŀ������һ���ַ���str������str������ظ��ַ��Ӵ��ĳ���
���磺
str = "abcd",����4
str = "aabcb",����3
Ҫ�����str�ĳ���ΪN,��ʵ��ʱ�临�Ӷ�ΪO(N)�ķ���
���Ѷȡ�ξ
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