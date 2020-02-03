/*
【名称】在其他数都出现偶数次的数组中找到出现奇数次的数
【题目】给定一个整型数组arr，其中只有一个数出现了奇数次，其他的数都出现
了偶数次，打印这个数。
进阶:有两个数出现了奇数次，其他的数都出现了偶数次，打印这两个数。
要求：时间复杂度为 O(N)，额外空间复杂度为O(1)
【难度】尉
*/

#include <iostream>

int printOddTimesNum1(int arr[], int len) {
	int eO = 0;
	for (int i = 0; i < len; i ++) {
		eO ^= arr[i];
	}
	return eO;
}

void printOddTimesNum2(int arr[], int len) {
	int eO = 0, eOhasOne = 0;
	for (int i = 0; i < len; i ++) {
		eO ^= arr[i];
	}
	int rightOne = eO & (~eO + 1);
	for (int i = 0; i < len; i ++) {
		if ((arr[i] & rightOne) != 0) {
			eOhasOne ^= arr[i];
		}
	}
	std::cout << eOhasOne << " " << (eO ^ eOhasOne) << std::endl;
}

int main() {

	int arr[7] = {1,1,1,2,2,3,3};
	std::cout << printOddTimesNum1(arr, 7) << std::endl;
	int arr2[6] = { 1,1,1,2,3,3 };
	printOddTimesNum2(arr2, 6);

	return 0;
}