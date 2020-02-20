/*
�����ơ����������С��
����Ŀ������С�͵Ķ������£�
��������s=[1,3,5,2,4,6],��s[0]�����С�ڻ����s[0]�����ĺ�Ϊ0����s[1]�����
С�ڻ����s[1]�����ĺ�Ϊ1����s[2]�����С�ڵ���s[2]�����ĺ�Ϊ1+3=4����s[3]��
���С�ڵ���s[3]������Ϊ1����s[4]�����С�ڵ���s[4]�����ĺ�Ϊ1+3+2=6����s[5]
�����С�ڵ���s[5]�����ĺ�Ϊ1+3+5+2+4=15,����s��С��Ϊ0+1+4+1+6+15=27��
����һ������s,ʵ�ֺ�������s��С�͡�
���Ѷȡ�У
*/
#include <iostream>


int merge(int* s, int left, int mid, int right) {
	int* h = new int[right - left + 1];
	memset(h, 0, sizeof(int) * (right - left + 1));

	int hi = 0;
	int i = left;
	int j = mid + 1;
	int smallSum = 0;

	while (i <= mid && j <= right) {
		if (s[i] <= s[j]) {
			smallSum += s[i] * (right - j + 1);
			h[hi ++] = s[i ++];
		}
		else {
			h[hi ++] = s[j ++];
		}
	}
	while (i <= mid) {
		h[hi++] = s[i ++];
	}
	while (j <= right) {
		h[hi++] = s[j++];
	}
	for (int k = 0; k < (right - left + 1); k ++) {
		s[left++] = h[k];
	}
	delete[] h;

	return smallSum;
}

int func(int* s, int left, int right) {
	if (left == right) {
		return 0;
	}
	int mid = (left + right) / 2;

	int a = func(s, left, mid);
	int b = func(s, mid + 1, right);
	return a + b + merge(s, left, mid, right);
}

int getSmallSum(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	return func(arr, 0, len - 1);
}

int main() {

	int arr[6] = {1,3,5,2,4,6};

	std::cout << getSmallSum(arr, 6) << std::endl;

	return 0;
}