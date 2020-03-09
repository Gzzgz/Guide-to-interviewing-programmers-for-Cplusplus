/*
�����ơ�����leftMax��rightMax֮��ľ���ֵ
����Ŀ������һ������ΪN(N>1)����������arr�����Ի��ֳ������������֣��󲿷�
Ϊarr[0...K]���Ҳ���Ϊarr[K+1...N-1]��K����ȡֵ�ķ�Χ[0,N-2].����ô�໮��
�����У��󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ�У�����Ƕ��١�
����[2,7,3,1,1],���󲿷�Ϊ[2,7],�в���Ϊ[3,1,1]ʱ���󲿷��е����ֵ��ȥ�Ҳ���
���ֵ�ľ���ֵΪ4�����󲿷�Ϊ[2,7,3]���Ҳ���Ϊ[1,1]ʱ���󲿷��е����ֵ��ȥ
�Ҳ������ֵ�ľ���ֵΪ6.���кܶ໮�ַ����������շ���6.
���Ѷȡ�У
*/
#include <iostream>

int maxABS1(int* arr, int len) {
	int res = INT_MIN;
	int maxLeft = 0;
	int maxRight = 0;
	for (int i = 0; i < len - 1; i++) {
		maxLeft = INT_MIN;
		for (int j = 0; j < i + 1; j ++) {
			maxLeft = arr[j] > maxLeft ? arr[j] : maxLeft;
		}
		maxRight = INT_MIN;
		for (int j = i + 1; j < len; j ++) {
			maxRight = arr[j] > maxRight ? arr[j] : maxRight;
		}
		res = res >= std::abs(maxLeft - maxRight) ? res : std::abs(maxLeft - maxRight);
	}

	return res;
}

int maxABS2(int* arr, int len) {
	int* left = new int[len];
	int* right = new int[len];
	memset(left, 0, sizeof(int) * len);
	memset(right, 0, sizeof(int) * len);
	left[0] = arr[0];
	right[len - 1] = arr[len - 1];
	for (int i = 1;i < len;i ++) {
		left[i] = left[i - 1] > arr[i] ? left[i - 1] : arr[i];
	}
	for (int i = len - 2; i > -1; i --) {
		right[i] = right[i + 1] > arr[i] ? right[i + 1] : arr[i];
	}
	int max = 0;
	for (int i = 0; i < len - 1; i ++) {
		max = max > std::abs(left[i] - right[i + 1]) ? max :
			std::abs(left[i] - right[i + 1]);
	}
	return max;
}

int maxABS3(int* arr, int len) {
	int max = INT_MIN;
	for (int i = 0; i < len; i ++) {
		max = arr[i] > max ? arr[i] : max;
	}
	return max - (arr[0] < arr[len - 1] ? arr[0] : arr[len - 1]);
}

int main() {

	int arr[] = {2,7,3,1,1};
	std::cout << maxABS3(arr, 5) << std::endl;

	return 0;
}