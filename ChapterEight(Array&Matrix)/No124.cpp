/*
【名称】在数组中找到一个局部最小的位置
【题目】定义局部最小的概念，arr长度为1,arr[0]是局部最小，arr长度为N>1时，
如果arr[0]<arr[1]，那么arr[0]是局部最小，如果arr[N-1]<arr[N-2]，那么arr[N-1]
是局部最小；如果0<i<N-1，既有arr[j]<arr[i-1]，又有arr[i]<arr[i+1]，那么arr[i]
是局部最小。
给定无序数组arr，已知arr中任意两个相邻的数都不相等。写一个函数，只需返回arr中
任意一个局部最小出现的位置即可。
【难度】尉
*/

#include <iostream>

int getLessIndex(int* arr, int len) {
	if (len == 0) {
		return -1;
	}
	if (len == 1 || arr[0] < arr[1]) {
		return 0;
	}
	if (arr[len - 1] < arr[len - 2]) {
		return len - 1;
	}
	int left = 1;
	int right = len - 2;
	int mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] > arr[mid - 1]) {
			right = mid - 1;
		}
		else if (arr[mid] > arr[mid + 1]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return left;
}

int main() {

	int arr[] = {3,2,1,4,5};
	std::cout << getLessIndex(arr, 5) << std::endl;

	return 0;
}