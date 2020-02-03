/*
【名称】拼接所有字符串产生字典顺序最小的大写字符串
【题目】给定一个字符串类型的数组strs,请找到一种拼接顺序，使得将所有的
字符串拼接起来组成的大写字符串是所有可能性中字典顺序最小的，并返回这个
大写字符串。
【难度】校
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int compare(std::string a, std::string b) {
	return (a + b) < (b + a) ? 1 : 0;
}

std::string lowestString(std::vector<std::string> strs) {
	if (strs.size() == 0) {
		return "";
	}
	sort(strs.begin(), strs.end(), compare);
	std::string res = "";
	for (int iter = 0; iter < strs.size(); iter++) {
		res += strs[iter];
	}
	return res;
}

int main() {

	std::vector<std::string> strs = {"bg", "be"};
	std::string res = lowestString(strs);

	std::cout << "res " << res << std::endl;

	return 0;
}