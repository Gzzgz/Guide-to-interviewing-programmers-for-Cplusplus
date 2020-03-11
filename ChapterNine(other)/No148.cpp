/*
【名称】1到n中1出现的次数
【题目】给定一个整数n，返回从1到n的数字中1出现的个数
【难度】校
*/
#include <iostream>

int get1Nums(int num) {
	int res = 0;
	while (num != 0) {
		if (num % 10 == 1) {
			res++;
		}
		num /= 10;
	}
	return res;
}

int solution1(int num) {
	if (num < 1) {
		return 0;
	}
	int count = 0;
	for (int i = 1; i < num + 1; i ++) {
		count += get1Nums(i);
	}
	return count;
}

int powerBaseOf10(int base) {
	return std::pow(10, base);
}

int getLenOfNum(int num) {
	int len = 0;
	while (num != 0) {
		len++;
		num /= 10;
	}
	return len;
}

int solution2(int num) {
	if (num < 1) {
		return 0;
	}
	int len = getLenOfNum(num);
	if (len == 1) {
		return 1;
	}
	int tmp1 = powerBaseOf10(len - 1);
	int first = num / tmp1;
	int firstOneNum = first == 1 ? num % tmp1 + 1 : tmp1;
	int otherOneNum = first * (len - 1) * (tmp1 / 10);
	return firstOneNum + otherOneNum + solution2(num % tmp1);
}

int main() {

	std::cout << solution2(114) << std::endl;

	return 0;
}