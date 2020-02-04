/*
【名称】数组中子数组的最大累乘积
【题目】给定一个double类型的数组arr，其中的元素可正，负，0，返回子数组累乘的最大乘积。
例如arr=[-2.5,4,0,3,0.5,8,-1],子数组[3, 0.5, 8]累乘可以获得最大的乘积12，所以返回12
【难度】尉
*/

#include <iostream>

double maxProduct(double arr[], int len) {

	if (len == 0) {
		return 0;
	}
	double max = arr[0];
	double min = arr[0];
	double res = arr[0];
	double maxend = 0;
	double minend = 0;
	for (int i = 1; i < len; i ++) {
		maxend = max * arr[i];
		minend = min * arr[i];
		max = (maxend > minend ? maxend : minend) > arr[i] ?
			(maxend > minend ? maxend : minend) : arr[i];
		res = res > max ? res : max;
	}
	return res;
}

int main() {

	double arr[] = {-2.5, 4, 0, 3, 0.5, 8, -1};
	std::cout << maxProduct(arr, 7) << std::endl;

	return 0;
}