/*
【名称】找到被指的新类型字符
【题目】新类型字符的定义如下：
1.新类型字符是长度为1或者长度2的字符串
2.表现形式可以仅是小写字母，也可以是大写字母+小写字母，还可以是大写字母
+大写字母
现在给定一个字符串str， str一定是若干新类型字符正确组合的结果。比如"eaCCBi",
由新类型字符'e','a', 'CC'和‘Bi’拼成。再给定一个整数k,代表str中的位置。
请返回被k位置指中的新类型字符.
【难度】士
*/
#include <iostream>
#include <string>

std::string pointNewStr(std::string str, int k) {

	if (str == "" || k > str.length()) {
		return "";
	}
	int uNum = 0;
	for (int i = k - 1; i >= 0; i --) {
		if (!isupper(str[i])) {
			break;
		}
		uNum++;
	}
	if (uNum & 1 == 1)  {
		return str.substr(k - 1, 2);
	}
	if (isupper(str[k])) {
		return str.substr(k, 2);
	}
	return str.substr(k, 1);
}

int main() {

	std::string str = "aaABCDEcBCg";

	std::cout << pointNewStr(str, 7).c_str() << std::endl;

	return 0;
}