/*
【名称】只用位运算不用算术运算实现整数的加减乘除运算
【题目】给定两个32位整数a,b，可正，负，0。不能使用算术运算符，分别实现
a,b的加减乘除运算。
要求：如果给定的a,b执行加减乘除的某些结果本来就会导致数据的溢出，那么
你实现的函数不必对那些结果负责。
【难度】尉
*/

#include <iostream>

int add(int a, int b) {
	int sum = a;
	while (b != 0) {
		sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return sum;
}

int negNum(int n) {
	return add(~n, 1);
}

int minus(int a, int b) {
	return add(a, negNum(b));
}

int multi(int a, int b) {
	int res = 0;
	while (b != 0) {
		if ((b & 1) != 0) {
			res = add(res, a);
		}
		a <<= 1;
		b >>= 1;
	}
	return res;
}

bool isNeg(int n) {
	return n < 0;
}

int div_(int a, int b) {
	int x = isNeg(a) ? negNum(a) : a;
	int y = isNeg(b) ? negNum(b) : b;
	int res = 0;
	for (int i = 31; i > -1; i = minus(i, 1)) {
		if ((x >> i) >= y) {
			res |= (1 << i);
			x = minus(x, y << i);
		}
	}
	return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

int divide(int a, int b) {
	if (b == 0) {
		return INT_MAX;
	}
	if (a == INT_MIN && b == INT_MIN) {
		return 1;
	}else if(b == INT_MIN){
		return 0;
	}
	else if (a == INT_MIN) {
		int res = div_(add(a, 1), b);
		return add(res, div_(minus(a, multi(res, b)), b));
	}
	else {
		return div_(a, b);
	}
}

int main() {

	std::cout << add(12, 4) << std::endl;
	std::cout << minus(12, 4) << std::endl;
	std::cout << multi(12, 4) << std::endl;
	std::cout << divide(12, 4) << std::endl;

	return 0;
}