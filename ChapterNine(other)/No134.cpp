/*
【名称】一行代码求两个数的最大公约数
【题目】给定两个不等于0的整数M,N，求M,N的最大公约数
【难度】士
*/

#include <iostream>

int gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m % n);
}

int main() {

	std::cout << gcd(12, 8) << std::endl;

	return 0;
}