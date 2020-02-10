/*
【名称】有关阶乘的两个问题
【题目】给定一个非负整数N,返回N!结果的末尾为0的数量。
例如：5！=120，返回1
【进阶题目】给定一个非负整数N,如果用二进制数表达N！的结果，返回最低位的1在
哪个位置上，认为最右的位置为位置0
【难度】原问题：尉； 进阶问题：校
*/

#include <iostream>

int zeroNum1(int num) {
	if (num < 0) {
		return 0;
	}
	int res = 0;
	int cur = 0;
	for (int i = 5; i < num + 1; i += 5) {
		cur = i;
		while (cur % 5 == 0) {
			res++;
			cur /= 5;
		}
	}
	return res;
}

int zeroNum2(int num) {
	if (num < 0) {
		return 0;
	}
	int res = 0;
	while (num != 0) {
		res += num / 5;
		num /= 5;
	}
	
	return res;
}

int rightOne1(int num) {
	if (num < 1) {
		return -1;
	}
	int res = 0;
	while (num != 0) {
		num >>= 1;
		res += num;
	}
	return res;
}

int rightOne2(int num) {
	if (num < 1) {
		return -1;
	}
	int ones = 0;
	int tmp = num;
	while (tmp != 0) {
		ones += (tmp & 1) != 0 ? 1 : 0;
		tmp >>= 1;
	}
	return num - ones;
}

int main() {

	long n = 1000000000;
	std::cout << zeroNum2(n) << std::endl;
	std::cout << rightOne2(n) << std::endl;

	return 0;
}