/*
【名称】将整数字符串转成整数值
【题目】给定一个字符串str，如果str符合日常书写的整数形式，并且属于32位
整数的范围，返回str所代表的整数值，否则返回0.
【难度】尉
*/

#include <iostream>
#include <vector>

bool isValid(std::string str) {
	if (str[0] != '-' && (str[0] < '0' || str[0] > '9')) {
		return false;
	}
	if (str[0] == '-' && (str.size() == 1 || str[1] == '0')) {
		return false;
	}
	if (str[0] == '0' && str.size() > 1) {
		return false;
	}
	for (int i = 1; i < str.size(); i ++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

int convert(std::string str) {
	if (str == "") {
		return 0;
	}
	if (!isValid(str)) {
		return 0;
	}
	bool posi = (str[0] == '-' ? false : true);
	int minq = INT_MIN / 10;
	int minr = INT_MIN % 10;
	int res = 0;
	int cur = 0;
	for (int i = posi ? 0 : 1; i < str.length(); i ++) {
		cur = '0' - str[i];
		if (res < minq || (res == minq && cur < minr)) {
			return 0;
		}
		res = res * 10 + cur;
	}
	if (posi && res == INT_MIN) {
		return 0;
	}
	return posi ? -res : res;
}

int main() {

	std::vector<std::string> strs = {"123", "023", "A13", "0", "2147483647",
	"2147483648", "-123"};

	for (int i = 0; i < strs.size(); i ++) {
		std::cout << convert(strs[i]) << std::endl;
	}

	return 0;
}