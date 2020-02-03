/*
【名称】不用额外变量交换两个整数的值
【题目】如何不用任何额外变量交换两个整数的值
【难度】士
*/


#include <iostream>

int main() {

	int a = 4;
	int b = 3;

	a ^= b;
	b ^= a;
	a ^= b;
	std::cout << a << " " << b << " " << std::endl;

	return 0;
}