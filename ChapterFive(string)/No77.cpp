/*
�����ơ��滻�ַ������������ֵ�ָ���ַ���
����Ŀ�����������ַ���str,from,to����str������from���Ӵ�ȫ���滻Ϊto�ַ�����
����������from�Ĳ���Ҫ��ֻ�滻��һ��to�ַ������������յĽ���ַ�����
���Ѷȡ�ʿ
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