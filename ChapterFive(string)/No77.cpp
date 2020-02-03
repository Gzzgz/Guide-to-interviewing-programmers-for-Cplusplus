/*
【名称】替换字符串中连续出现的指定字符串
【题目】给定三个字符串str,from,to，把str中所有from的子串全部替换为to字符串，
对连续出现from的部分要求只替换成一个to字符串，返回最终的结果字符串。
【难度】士
*/

#include <iostream>

void clear(std::string& str, int end, int len) {
	while (len -- != 0) {
		str[end--] = '#';
	}
}

std::string replace(std::string str, std::string from, std::string to) {
	if (str == "" || from == "" || to == "") {
		return str;
	}
	int match = 0;
	for (int i = 0; i < str.length(); i ++) {
		if (str[i] == from[match++]) {
			if (match == from.length()) {
				clear(str, i, from.length());
				match = 0;
			}
		}else{
			match = 0;
		}
	}
	std::string res = "";
	std::string cur = "";
	for (int i = 0; i < str.length(); i ++) {
		if (str[i] != '#') {
			cur += std::string(1, str[i]);
		}
		if (str[i] == '#' && (i == 0 || str[i - 1] != '#')) {
			res += cur + to;
			cur = "";
		}
	}
	if (cur != "") {
		res += cur;
	}
	return res;
}

int main() {

	std::string str = "123abc";
	std::string from = "abc";
	std::string to = "4567";

	std::cout << replace(str,from,to).c_str() << std::endl;
	return 0;
}