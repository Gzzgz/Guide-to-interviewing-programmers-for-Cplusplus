/*
【名称】在有序旋转数组中找到最小值
【题目】有序数组arr可能经过一次旋转处理，也可能没有，且arr可能存在重复的数。
例如有序数组[1,2,3,4,5,6,7],可以旋转处理为[4,5,6,7,1,2,3]等，给定一个可能旋转过
的有序数组arr，返回arr中的最小值。
【难度】尉
*/

#include <iostream>

int getMin(int* arr, int len) {
	int low = 0;
	int high = len - 1;
	int mid = 0;
	while (low < high) {
		if (low == high - 1) {
			break;
		}
		if (arr[low] < arr[high]) {
			return arr[low];
		}
		mid = (low + high) / 2;
		if (arr[low] > arr[mid]) {
			high = mid;
			continue;
		}
		if (arr[mid] > arr[high]) {
			low = mid;
			continue;
		}
		while (low < mid) {
			if (arr[low] == arr[mid]) {
				low++;
			}
			else if (arr[low] < arr[mid]) {
				return arr[low];
			}
			else {
				high = mid;
				break;
			}
		}
	}

	return arr[low] < arr[high] ?  arr[low] : arr[high];
}

int main() {

	int arr[] = {4,5,6,7,1,2,3};
	std::cout << getMin(arr, 7) << std::endl;

	return 0;
}