/*
【名称】翻转字符串
【题目】给定一个字符类型的数组chas，请在单词间做逆序调整。只要做到单词顺序逆序即可，对
空格的位置没有特别要求。
【补充题目】给定一个字符类型的数组chas和一个整数size，请把大小为size的
左半区整体移到右半区，右半区整体移到左边。
要求：如果chas长度为N,两道题都要求时间复杂度为O(N),额外空间复杂度为O(1)
【难度】士
*/

#include <iostream>

void reverse(std::string& str, int start, int end) {
	char tmp = 0;
	while (start < end) {
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

std::string rotateWord(std::string str) {

	if (str == "") {
		return str;
	}
	reverse(str, 0, str.length() - 1);
	int left = -1;
	int right = -1;
	for (int i = 0; i < str.length(); i ++) {
		if (str[i] != ' ') {
			left = (i == 0 || str[i - 1] == ' ') ? i : left;
			right = (i == str.length() - 1 || str[i + 1] == ' ') ? i : right;
		}
		if (left != -1 && right != -1) {
			reverse(str, left, right);
			left = -1;
			right = -1;
		}
	}

	return str;
}

std::string rotate1(std::string str, int size) {
	if (str == "" || size <= 0 || size >= str.length()) {
		return "";
	}
	reverse(str, 0, size - 1);
	reverse(str, size, str.length() - 1);
	reverse(str, 0, str.length() - 1);

	return str;
}

void exchange(std::string& str, int start, int end, int size) {
	int i = end - size + 1;
	char tmp = 0;
	while (size -- != 0) {
		tmp = str[start];
		str[start] = str[i];
		str[i] = tmp;
		start++;
		i++;
	}
}

std::string rotate2(std::string str, int size) {

	if (str == "" || size <= 0 || size >= str.length()) {
		return "";
	}
	int start = 0;
	int end = str.length() - 1;
	int lpart = size;
	int rpart = str.length() - size;
	int s = lpart < rpart ? lpart : rpart;
	int d = lpart - rpart;
	while (true) {
		exchange(str, start, end, s);
		if (d == 0) {
			break;
		}
		else if (d > 0) {
			start += s;
			lpart = d;
		}
		else {
			end -= s;
			rpart = -d;
		}
		s = lpart < rpart ? lpart : rpart;
		d = lpart - rpart;
	}
	return str;
}

int main() {

	std::string str1 = "dog loves pig";
	std::string str2 = "ABCDE";

	//std::cout << rotateWord(str1).c_str() << std::endl;
	//std::cout << rotate1(str2, 3).c_str() << std::endl;
	std::cout << rotate2(str2, 3).c_str() << std::endl;

	return 0;
}