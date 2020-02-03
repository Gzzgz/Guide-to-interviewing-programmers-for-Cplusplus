/*
�����ơ�������������ȵ������������ҵ�����λ��
����Ŀ������������������arr1,arr2����֪��������ĳ��ȶ�ΪN��������������������������λ����
arr1=[1,2,3,4], arr2=[3,4,5,6],�ܹ���8����������λ���ǵ�4С����������3.
Ҫ��ʱ�临�Ӷ�O(logN),����ռ临�Ӷ�O(1)
���Ѷȡ�ξ
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