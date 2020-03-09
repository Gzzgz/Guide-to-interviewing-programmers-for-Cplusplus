/*
【名称】调整[0,x)区间上的数出现的概率
【题目】假设函数Math.random()等概率随机返回一个在[0,1)范围上的数，那么我们
知道，在[0,x)区间上的数出现的概率为x(0<x<=1)，给定一个大于0的整数k，并且可以
使用Math.random()函数，请实现一个函数依然返回在[0,1)范围上的数，但是在[0,x)
区间上的数出现的概率为x^k(0<x<=1)。
【难度】士
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

double rand01() {
	return rand() % 1000 / 1000.0;
}

double randXPowerK(int k) {
	if (k < 1) {
		return 0;
	}
	double res = -1;
	for (int i = 0; i < k; i ++) {
		res = res > rand01() ? res : rand01();
	}
	return res;
}

int main() {

	std::cout << randXPowerK(3) << std::endl;

	return 0;
}