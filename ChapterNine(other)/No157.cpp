/*
【名称】在两个长度相等的排序数组中找到上中位数
【题目】给定两个有序数组arr1,arr2，已知两个数组的长度都为N，求两个数组中所有数的上中位数。
arr1=[1,2,3,4], arr2=[3,4,5,6],总共有8个数，上中位数是第4小的数，返回3.
要求：时间复杂度O(logN),额外空间复杂度O(1)
【难度】尉
*/

#include <iostream>

int getUpMedian(int arr1[], int arr2[], int len) {

	int start1 = 0;
	int end1 = len - 1;
	int start2 = 0;
	int end2 = len - 1;
	int mid1 = 0;
	int mid2 = 0;
	int offset = 0;
	while (start1 < end1) {
		mid1 = (start1 + end1) / 2;
		mid2 = (start2 + end2) / 2;
		offset = ((end1 - start1 + 1) & 1) ^ 1;
		if (arr1[mid1] > arr2[mid2]) {
			end1 = mid1;
			start2 = mid2 + offset;
		} else if (arr1[mid1] < arr2[mid2]) {
			start1 = mid1 + offset;
			end2 = mid2;
		}
		else {
			return arr1[mid1];
		}
	}
	return arr1[start1] < arr2[start2] ? arr1[start1] : arr2[start2];
}

int main() {

	int arr1[] = {0, 1, 2};
	int arr2[] = {3, 4, 5};

	int res = getUpMedian(arr1, arr2, 3);
	std::cout << "res " << res << std::endl;

	return 0;
}