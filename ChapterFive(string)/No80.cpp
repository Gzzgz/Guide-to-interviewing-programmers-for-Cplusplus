/*
【名称】在有序但含有空的数组中查找字符串
【题目】给定一个字符串数组strs[], 在str中有些位置为null, 但在不为null
的位置上，其字符串是按照字典顺序由小到大依次出现的。再给定一个字符串str,
请返回str在 strs中出现的最左的位置。
【难度】尉
*/

#include <iostream>
#include <vector>


int getIndex(std::vector<std::string> strs, std::string str) {
	if (strs.size() == 0 || str=="" || str == "null") {
		return -1;
	}
	int res = -1;
	int left = 0;
	int right = strs.size() - 1;
	int mid = 0;
	int i = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (strs[mid] != "null" && strs[mid] == str) {
			res = mid;
			right = mid - 1;
		} else if (strs[mid] != "null") {
			if (strs[mid][0] - str[0] < 0) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		else {
			i = mid;
			while (strs[i] == "null" && --i >= left) {
				;
			}
			if (i < left || strs[i][0] - str[0] < 0) {
				left = mid + 1;
			}
			else {
				res = strs[i] == str ? i : res;
				right = i - 1;
			}
		}
	}
	return res;
}

int main() {

	std::vector<std::string> strs = {"null", "a", "null", "a",
	"b", "null", "null", "c", "null", "d"};

	std::cout << getIndex(strs, "a") << std::endl;
	std::cout << getIndex(strs, "c") << std::endl;
	std::cout << getIndex(strs, "e") << std::endl;
	std::cout << getIndex(strs, "null") << std::endl;

	return 0;
}