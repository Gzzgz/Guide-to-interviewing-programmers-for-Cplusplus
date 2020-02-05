/*
【名称】数组得partition调整
【题目】给定一个有序数组arr，调整arr使得这个数组的左边部分没有重复元素且升序，
而不用保证右部分是否有序。
例如：arr=[1,2,2,2,3,3,4,5,6,6,7,7,8,8,8,9],调整后arr=[1,2,3,4,5,6,7,8,9,...]
【补充题目】
给定一个数组arr，其中只可能有0，1，2三个值，请实现arr的排序.
另一种问法为：有一个数组，其中只有红球，蓝球和黄球，请实现红球全放在数组的左边
蓝球放中间，黄球放在右边；
另一种问法为：有一个数组，再给定一个值k,请实现比k小的数都放在数组的左边，等于
k的数都放在数组的中间，比k大的数都放在数组的右边
要求:1.所有题目实现的时间复杂度为O(N);额外空间复杂度O(1)
【难度】士
*/

#include <iostream>

void leftUnique(int* arr, int len) {
	if (len < 2) {
		return;
	}
	int u = 0;
	int i = 1;
	while (i != len) {
		if (arr[i++] != arr[u]) {
			int tmp = arr[u+1];
			arr[++u] = arr[i - 1];
			arr[i - 1] = tmp;
		}
	}
}

void sort(int* arr, int len) {
	if (len < 2) {
		return;
	}
	int left = -1;
	int index = 0;
	int right = len;
	while (index < right) {
		if (arr[index] == 0) {
			int tmp = arr[left + 1];
			arr[++left] = arr[index];
			arr[index++] = tmp;
		}
		else if (arr[index] == 2) {
			int tmp = arr[index];
			arr[index] = arr[right - 1];
			arr[--right] = tmp;
		}
		else {
			index++;
		}
	}
}

int main() {

	int arr[15] = {1,2,2,2,3, 3,4,5,6,7, 7,8,8,8,9};
	leftUnique(arr, 15);
	for (int i = 0; i < 15; i ++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int arr1[8] = {0,1,1,2,0,1,1,2};
	sort(arr1, 8);
	for (int i = 0; i < 8; i ++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}