/*
【名称】判断一个数是否是回文数
【题目】定义回文数的概念：
1.如果一个非负数左右完全对应，则该数是回文数：121，22；
2.如果一个负数的绝对值左右完全对应，也是回文数：-121，-22；
给定一个32位整数num，判断num是否是回文数。
【难度】士
*/
#include <iostream>

bool isPalindrome(int n) {
	if (n == INT_MIN) {
		return false;
	}
	n = std::abs(n);
	int help = 1;
	while (n / help >= 10) {
		help *= 10;
	}
	while (n != 0) {
		if (n / help != n % 10) {
			return false;
		}
		n = (n % help) / 10;
		help /= 100;
	}
	return true;
}

int main() {

	std::cout << isPalindrome(12121) << std::endl;

	return 0;
}