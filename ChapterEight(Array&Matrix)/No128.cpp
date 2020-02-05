/*
【名称】不包含本位置值得累乘数组
【题目】给定一个整数数组arr，返回不包含本位置值得累乘数组
例如arr=[2,3,1,4],返回[12,8,24,6]，即除自己外，其他位置上得累乘
要求：时间复杂度O(N),空间复杂度O(1)
【进阶题目】对时间和空间复杂度要求不变，而且不可以使用除法
*/

#include <iostream>
#include <vector>

std::vector<int> product1(int* arr, int len) {
	std::vector<int> res(len);
	if (len < 2) {
		return res;
	}
	int count = 0;
	int all = 1;
	for (int i = 0; i != len; i ++) {
		if (arr[i] != 0) {
			all *= arr[i];
		}
		else {
			count++;
		}
	}
	if (count == 0) {
		for (int i = 0; i < len; i ++) {
			res[i] = all / arr[i];
		}
	}
	if (count == 1) {
		for (int i = 0; i != len; i ++) {
			if (arr[i] == 0) {
				res[i] = all;
			}
		}
	}
	return res;
}

std::vector<int> product2(int* arr, int len) {
	std::vector<int> res(len);
	if (len < 2) {
		return res;
	}
	res[0] = arr[0];
	for (int i = 1; i < len; i ++) {
		res[i] = res[i - 1] * arr[i];
	}
	int tmp = 1;
	for (int i = len - 1; i > 0; i --) {
		res[i] = res[i - 1] * tmp;
		tmp *= arr[i];
	}
	res[0] = tmp;
	return res;
}

int main() {

	int arr[] = {2,3,1,4};
	//std::vector<int> res = product1(arr, 4);
	std::vector<int> res = product2(arr, 4);
	for (int i = 0; i < 4; i ++) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}