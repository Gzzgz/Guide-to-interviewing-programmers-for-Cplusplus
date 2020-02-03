/*
【名称】字符串中数字子串的求和
【题目】给定一个字符串str，求其中全部数字字串所代表的数字之和
要求：
1.忽略小数点字符，例“A1.3”，其中包含两个数字1和3
2.如果紧贴数字子串的左侧出现字符"-",当连续出现的数量为奇数时，则数字为负。
连续出现的数量为偶数时，则数字为正，例如“A-1BC--12”，其中包含数字-1，12
【难度】士
*/

#include <iostream>

int numSum(std::string str) {
	if (str == "") {
		return 0;
	}
	int res = 0;
	int num = 0;
	bool posi = true;
	int cur = 0;
	for (int i = 0; i < str.length(); i ++) {
		cur = str[i] - '0';
		if (cur < 0 || cur > 9) {
			res += num;
			num = 0;
			if (str[i] == '-') {
				if (i - 1 > -1 && str[i - 1] == '-') {
					posi = !posi;
				}
				else {
					posi = false;
				}
			}
			else {
				posi = true;
			}
		}
		else {
			num = num * 10 + (posi ? cur : -cur);
		}
	}
	res += num;
	return res;
}

int main() {

	std::string str1 = "A1CD2E33";
	std::string str2 = "A-1B--2C--D6E";

	std::cout << numSum(str2) << std::endl;

	return 0;
}