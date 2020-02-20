/*
【名称】未排序数组中累加和为给定值的最长子数组系列问题
【题目】给定一个无序数组arr，其中元素可正，负，0，给定一个整数k。求arr所有的
子数组中累加和为k的最长子数组长度。
【补充题目】给定一个无序数组arr，其中元素可正，负，0.求arr所有的子数组中正数
与负数个数相等的最长子数组长度
【补充题目】给定一个无序数组arr，其中元素只是1或0,求arr所有的子数组中0和1个数
相等的最长子数组长度。
【难度】尉
*/

#include <iostream>
#include <map>

int maxLength(int* arr, int len, int k) {

	if (len == 0) {
		return 0;
	}
	std::map<int, int> map;
	map.insert(std::pair<int, int>(0, -1));
	int length = 0;
	int sum = 0;
	for (int i = 0; i < len; i ++) {
		sum += arr[i];
		if (map.find(sum - k) != map.end()) {
			length = (i - map[sum - k]) > length ? (i - map[sum - k]) : length;
		}
		if (map.find(sum) == map.end()) {
			map.insert(std::pair<int, int>(sum, i));
		}
	}
	return length;
}

int main() {

	int arr[] = {1,2,3,3};

	std::cout << maxLength(arr, 4, 6) << std::endl;

	return 0;
}