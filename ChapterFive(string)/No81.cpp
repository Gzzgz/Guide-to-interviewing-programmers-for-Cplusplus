/*
【名称】字符串的调整与替换
【题目】给定一个字符串类型的数组chas[]，chas右半区全是空字符，左半区不
含有空字符。现在想将左半区中所有的空格字符替换成"%20"，假设chas右半区
足够大，可以满足替换所需要的空间，请完成替换函数。
要求：替换函数的时间复杂度为O(N),额外空间复杂度为O(1)
【补充题目】给定一个字符类型的数组chas[]，其中只含有数字字符和“*”字符，
现在想把所有的“*”字符挪到chas的左边，数字字符挪到chas的右边，请完成调试函数。
要求：
1.调整函数的时间复杂度为O(N),额外空间复杂度为O(1)
2.不得改变数字字符从左到右出现的顺序。
【难度】士
*/

#include <iostream>

std::string replace(std::string str) {
	if (str =="") {
		return "";
	}
	int num = 0;
	int len = 0;
	for (len = 0; len < str.length() && str[len] != 0; len ++) {
		if (str[len] == ' ') {
			num++;
		}
	}
	int j = len + num * 2 - 1;
	for (int i = len - 1; i > -1; i --) {
		if (str[i] != ' ') {
			str[j--] = str[i];
		}
		else {
			str[j --] = '0';
			str[j --] = '2';
			str[j--] = '%';
		}
	}
	return str;
}

std::string modify(std::string str) {
	if (str == "") {
		return "";
	}
	int j = str.length() - 1;
	for (int i = str.length() - 1; i > -1; i --) {
		if (str[i] != '*') {
			str[j--] = str[i];
		}
	}
	for (; j > -1; ) {
		str[j--] = '*';
	}
	return str;
}

int main() {

	std::string str1 = "a b  c###########";
	std::string str2 = "121**345";
	//std::cout << replace(str1).c_str() << std::endl;

	std::cout << modify(str2).c_str() << std::endl;

	return 0;
}