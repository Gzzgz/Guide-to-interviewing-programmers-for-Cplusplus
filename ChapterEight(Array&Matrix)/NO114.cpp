/*
�����ơ���Ŀ�����������ĳ���
����Ŀ���ȸ�������������Ķ��塣���һ�����������֮��ÿ������������ľ���ֵ
��Ϊ1���������Ϊ���������顣����[5,3,4,6,2]����֮��Ϊ[2,3,4,5,6], ����ÿ����
��������ľ���ֵ����1�������������Ϊ���������顣 ����һ����������arr���뷵������
��������������ĳ��ȡ�����[5,5,3,2,6,4,3]����������������Ϊ[5,3,2,6,4]������
����5.
���Ѷȡ�ξ
*/

#include <iostream>
#include <algorithm>
#include <set>

bool compare(int a, int b) {
	return a <= b;
}

bool isIntegrated(int* arr, int len, int left, int right) {

	int* newarr = new int[right - left + 1];
	for (int i = 0; i < right - left + 1; i ++) {
		newarr[i] = arr[left + i];
	}
	std::sort(newarr, newarr + right - left + 1, compare);
	
	for (int i = 1; i < right - left + 1; i ++) {
		if (newarr[i - 1] != newarr[i] - 1) {
			delete[] newarr;
			return false;
		}
	}
	delete[] newarr;

	return true;
}

int getLIL1(int* arr, int len) {

	if (len == 0) {
		return 0;
	}
	int length = 0;
	for (int i = 0; i < len; i ++) {
		for (int j = i; j < len; j ++) {
			if (isIntegrated(arr, len, i, j)) {
				length = length > (j - i + 1) ? length : (j - i + 1);
			}
		}
	}
	return length;
}

int getLIL2(int* arr, int length) {
	if (length == 0) {
		return 0;
	}
	int len = 0;
	int max = 0;
	int min = 0;
	
	std::set<int> set;
	for (int i = 0; i < length; i ++) {
		max = INT_MIN;
		min = INT_MAX;
		for (int j = i; j < length; j ++) {
			if (set.find(arr[j]) != set.end()) {
				break;
			}
			set.insert(arr[j]);
			max = max > arr[j] ? max : arr[j];
			min = min < arr[j] ? min : arr[j];
			if (max - min == j - 1) {
				len = len > (j - i + 1) ? len : (j - i + 1);
			}
		}
		set.clear();
	}
	return len;
}

int main() {

	int arr[] = {3,3,4,5,6,7, 6};

	std::cout << getLIL1(arr, 7) << std::endl;

	std::cout << getLIL2(arr, 7) << std::endl;

	return 0;
}