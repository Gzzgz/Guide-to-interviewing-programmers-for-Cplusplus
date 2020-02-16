/*
【名称】汉诺塔问题
【题目】给定一个整数n,代表汉诺塔游戏中从小到大放置的n个圆盘，假设开始时
所有的圆盘都放在左边的柱子上，想按照汉诺塔游戏的要求把所有的圆盘都移到右
边的柱子上。实现函数打印最优移动轨迹。
【进阶题目】给定一个整型数组arr, 其中只含有1，2，3，代表所有圆盘目前的状态，
1代表左柱子，2代表中间柱子，3代表右柱子，arr[i]的值代表第i+1个圆盘的位置。
比如arr[3，3，2，1]，代表第1个圆盘在右柱子上，第2个在右柱子上，第3个在中
柱子上，第4个在左柱子上。如果arr代表的状态时最优移动轨迹过程中出现的状态，
返回arr这种状态时最优移动轨迹中的第几个状态。如果arr代表的状态不是最优移动
轨迹过程中出现的状态，则返回-1
【难度】校
*/
#include <iostream>

void func(int n, std::string from, std::string mid, std::string to) {
	if (n == 1) {
		std::cout << "move from " << from.c_str() << " to " << to.c_str() << std::endl;
	}
	else {
		func(n - 1, from, to, mid);
		func(1, from, mid, to);
		func(n - 1, mid, from, to);
	}
}

void hanoi(int n) {
	if (n > 0) {
		func(n, "left", "mid", "right");
	}
}

int process(int* arr, int i, int from, int mid, int to) {
	if (i == -1) {
		return 0;
	}
	if (arr[i] != from && arr[i] != to) {
		return -1;
	}
	if (arr[i] == from) {
		return process(arr, i - 1, from, to, mid);
	}
	else {
		int rest = process(arr,i - 1, mid, from, to);
		
		if (rest == -1) {
			return -1;
		}
		return (1 << i) + rest;
	}
}

int step1(int* arr, int len) {
	if (len == 0) {
		return -1;
	}
	return process(arr, len - 1, 1, 2, 3);
}

int step2(int* arr, int len) {
	if (len == 0) {
		return -1;
	}
	int from = 1;
	int mid = 2;
	int to = 3;
	int i = len - 1;
	int res = 0;
	int tmp = 0;
	while (i >= 0) {
		if (arr[i] != from && arr[i] != to) {
			return -1;
		}
		if (arr[i] == to) {
			res += 1 << i;
			tmp = from;
			from = mid;
		}
		else {
			tmp = to;
			to = mid;
		}
		mid = tmp;
		i--;
	}
	return res;
}

int main() {

	hanoi(2);

	int arr[] = {3, 3};

	std::cout << step2(arr, 2) << std::endl;

	return 0;
}