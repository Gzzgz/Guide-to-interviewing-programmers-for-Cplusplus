/*
�����ơ������������������ҵ���kС����
����Ŀ������������������arr1,arr2���ٸ���һ������k,�������е����е�kС������
Ҫ�����arr1����N,arr2����M,ʱ�临�Ӷ�O(log(min(M,N))),����ռ临�Ӷ�O(1)
���Ѷȡ���
*/
#include <iostream>

int getUpMedian(int* a1, int s1, int e1, int* a2, int s2, int e2) {
	int mid1 = 0;
	int mid2 = 0;
	int offset = 0;
	while (s1 < e1) {
		mid1 = (s1 + e1) / 2;
		mid2 = (s2 + e2) / 2;
		offset = ((e1 - s1 + 1) & 1) ^ 1;
		if (a1[mid1] > a2[mid2]) {
			e1 = mid1;
			s2 = mid2 + offset;
		}else if(a1[mid1] < a2[mid2]) {
			s1 = mid1 + offset;
			e2 = mid2;
		}
		else {
			return a1[mid1];
		}
	}
	return a1[s1] < a2[s2] ? a1[s1] : a2[s2];
}

int findKthNum(int* arr1, int len1, int* arr2, int len2, int kth) {
	if (arr1 == nullptr || arr2 == nullptr) {
		return -1;
	}
	if (kth < 1 || kth > len1 + len2) {
		return -1;
	}
	int* longs = len1 > len2 ? arr1 : arr2;
	int* shorts = len1 < len2 ? arr1 : arr2;
	int lo = len1 > len2 ? len1 : len2;
	int sh = len1 < len2 ? len1 : len2;
	if (kth <= sh) {
		return getUpMedian(shorts, 0, kth - 1, longs, 0, kth - 1);
	}
	if (kth > lo) {
		if (shorts[kth - lo - 1] >= longs[lo - 1]) {
			return shorts[kth - lo - 1];
		}
		if (longs[kth - sh - 1] >= shorts[sh - 1]) {
			return longs[kth - sh - 1];
		}
		return getUpMedian(shorts, kth - lo, sh - 1, longs, kth - sh, lo - 1);
	}
	if (longs[kth - sh - 1] >= shorts[sh - 1]) {
		return longs[kth - sh - 1];
	}
	return getUpMedian(shorts, 0, sh - 1, longs, kth - sh, kth - 1);
}

int main() {

	int arr1[] = {1,2,3,4,5};
	int arr2[] = {3,4,5};
	std::cout << findKthNum(arr1, 5, arr2, 3, 4) << std::endl;

	return 0;
}