/*
�����ơ�δ�����������ۼӺ�С�ڻ���ڸ���ֵ��������鳤��
����Ŀ������һ����������arr������Ԫ�ؿ���������0,����һ������k,��arr���е���
�������ۼӺ�С�ڻ����k��������鳤��.
���磺arr=[3,-2,-4,0,6],k=-2����Ӻ�С�ڻ����-2���������Ϊ{3,-2,-4,0},���Խ������4.
���Ѷȡ�У
*/

#include <iostream>


int getLessIndex(int* arr, int len, int num) {

	int low = 0;
	int high = len - 1;
	int mid = 0;
	int res = -1;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] >= num) {
			res = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return res;
}

int maxLength(int* arr, int len, int k) {

	int* h = new int[len + 1];
	memset(h, 0, sizeof(int) * (len + 1));
	
	int sum = 0;
	h[0] = sum;
	for (int i = 0; i != len; i ++) {
		sum += arr[i];
		h[i + 1] = sum > h[i] ? sum : h[i];
	}
	sum = 0;
	int res = 0;
	int pre = 0;
	int length = 0;
	for (int i = 0; i != len; i ++) {
		sum += arr[i];
		pre = getLessIndex(h, len + 1, sum - k);
		length = pre == -1 ? 0 : i - pre + 1;
		res = res > length ? res : length;
	}
	delete[] h;

	return res;
}

int main(){

	int arr[] = {3, -2, -4, 0, 6};
	int k = -2;

	std::cout << maxLength(arr, 5, k) << std::endl;

	return 0;
}
