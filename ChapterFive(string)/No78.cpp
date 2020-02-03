/*
【名称】字符串的统计字符串
【题目】给定一个字符串str，返回str的统计字符串。例如：“aaabbadddffc”
的哦统计字符串为"a_3_b_2_a_1_d_3_f_2_c_1"
【补充题目】给定一个字符串的统计字符串cstr，再给定一个整数index，返回
cstr所代表的原始字符串上的第index个字符。例如：“a_1_b_100”所代表的
原始字符串上第0个字符是'a',第50个字符是'b'.
【难度】士
*/

#include <iostream>
#include <string>

std::string getCountString(std::string str) {
	if (str == "") {
		return "";
	}
	std::string res(1, str[0]);
	int num = 1;
	for (int i = 1; i < str.size(); i ++) {
		if (str[i] != str[i - 1]) {
			res += "_" + std::to_string(num) + "_" + std::string(1, str[i]);
			num = 1;
		}
		else {
			num++;
		}
	}
	return res += "_" + std::to_string(num);
}

char getCharAt(std::string str, int index) {
	if (str == "") {
		return '#';
	}
	bool stage = true;
	char cur = '#';
	int num = 0;
	int sum = 0;
	for (int i = 0; i != str.length(); i ++) {
		if (str[i] == '_') {
			stage = !stage;
		}
		else if (stage) {
			sum += num;
			if (sum > index) {
				return cur;
			}
			num = 0;
			cur = str[i];
		}
		else {
			num = num * 10 + str[i] - '0';
		}
	}
	return sum + num > index ? cur : '#';
}

int main() {

	std::string str = "aaabbadddffc";
	//std::cout << getCountString(str).c_str() << std::endl;

	std::string str1 = "a_1_b_100";
	std::cout <<getCharAt(str1, 0) << std::endl;
	return 0;
}