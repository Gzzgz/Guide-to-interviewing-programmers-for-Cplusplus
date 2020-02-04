/*
�����ơ����������ҵ�һ���ֲ���С��λ��
����Ŀ������ֲ���С�ĸ��arr����Ϊ1,arr[0]�Ǿֲ���С��arr����ΪN>1ʱ��
���arr[0]<arr[1]����ôarr[0]�Ǿֲ���С�����arr[N-1]<arr[N-2]����ôarr[N-1]
�Ǿֲ���С�����0<i<N-1������arr[j]<arr[i-1]������arr[i]<arr[i+1]����ôarr[i]
�Ǿֲ���С��
������������arr����֪arr�������������ڵ���������ȡ�дһ��������ֻ�践��arr��
����һ���ֲ���С���ֵ�λ�ü��ɡ�
���Ѷȡ�ξ
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