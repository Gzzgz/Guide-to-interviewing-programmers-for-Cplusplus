/*
【名称】计算数组的小和
【题目】数组小和的定义如下：
例如数组s=[1,3,5,2,4,6],在s[0]的左边小于或等于s[0]的数的和为0，在s[1]的左边
小于或等于s[1]的数的和为1，在s[2]的左边小于等于s[2]的数的和为1+3=4，在s[3]的
左边小于等于s[3]的数和为1，在s[4]的左边小于等于s[4]的数的和为1+3+2=6，在s[5]
的左边小于等于s[5]的数的和为1+3+5+2+4=15,所以s的小和为0+1+4+1+6+15=27。
给定一个数组s,实现函数返回s的小和。
【难度】校
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