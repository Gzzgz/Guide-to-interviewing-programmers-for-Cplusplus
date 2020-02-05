/*
【名称】未排序正数数组中累加和为给定值的最长子数组长度
【题目】给定一个数组arr，该数组无序，但每个值均为正数，再给定一个正数k。求arr
的所有子数组中所有元素相加和为k的最长子数组长度。
例如arr=[1,2,1,1,1],k=3
累加和为3的最长子数组为[1,1,1]，所以结果返回3.
【难度】尉
*/

#include <iostream>


int getMaxLength(int* arr, int length, int k) {
	if (length == 0 || k <= 0) {
		return 0;
	}
	int left = 0;
	int right = 0;
	int sum = arr[0];
	int len = 0;
	while (right < length) {
		if (sum == k) {
			len = len > (right - left + 1) ? len : (right - left + 1);
			sum -= arr[left ++];
		}
		else if (sum < k) {
			right++;
			if (right == length) {
				break;
			}
			sum += arr[right];
		}
		else {
			sum -= arr[left++];
		}
	}
	return len;
}

int main() {

	int arr[] = {1,2,1,1,1};
	std::cout << getMaxLength(arr, 5, 3) << std::endl;

	return 0;
}