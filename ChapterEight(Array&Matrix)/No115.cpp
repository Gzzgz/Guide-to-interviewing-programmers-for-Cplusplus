/*
【名称】不重复打印排序数组中相加和为给定值的所有二元组和三元组
【题目】给定排序数组arr和整数k,不重复打印arr中所有相加和为k的不降序二元组。例如
arr=[-8,-4,-3,0,1,2,4,5,8,9]，k=10，打印结果为：
1，9
2，8
【补充题目】给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序三元组。
例如：arr=[-8,-4,-3,0,1,2,4,5,8,9]，k=10，打印结果为：
-4，5，9
-3，4，9
-3，5，8
 0，1，9
 0，2，8
 1，4，5
【难度】尉
*/

#include <iostream>

void printUniquePair(int* arr, int len, int k) {

	if (len < 2) {
		return;
	}
	int left = 0;
	int right = len - 1;
	while (left < right) {
		
		if (arr[left] + arr[right] < k) {
			left++;
		}
		else if (arr[left] + arr[right] > k) {
			right--;
		}
		else {
			if (left == 0 || arr[left - 1] != arr[left]) {
				std::cout << arr[left] << " " << arr[right] << std::endl;
			}
			left++;
			right--;
		}
	}
}


void printRest(int* arr, int len, int f, int left, int right, int k) {

	while (left < right) {
		if (arr[left] + arr[right] < k) {
			left++;
		}
		else if (arr[left] + arr[right] > k) {
			right--;
		}
		else {
			if (left == f + 1 || arr[left - 1] != arr[left]) {
				std::cout << arr[f] << "," << arr[left] << "," << arr[right] << std::endl;
			}
			left++;
			right--;
		}
	}
}

void printUniqueTriad(int* arr, int len, int k) {

	if (len < 3) {
		return;
	}
	for (int i = 0; i < len - 2; i ++) {
		if (i== 0 || arr[i] != arr[i - 1]) {
			printRest(arr,len, i, i + 1, len - 1, k - arr[i]);
		}
	}
}

int main() {

	int arr[] = {-8, -4, -3, 0, 1, 2, 4, 5, 8, 9};
	int k = 10;

	printUniquePair(arr, 10, k);

	printUniqueTriad(arr, 10, k);

	return 0;
}