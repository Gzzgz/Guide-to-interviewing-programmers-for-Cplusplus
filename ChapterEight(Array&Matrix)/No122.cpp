/*
�����ơ������������ۼӺ�����
����Ŀ������һ������arr�����������������ۼӺ͡�
����arr=[1,-2,3,5,-2,6,-1]�����е��������У�[3,5,-2,6]�����ۼӳ����ĺ�12�����Է���12
Ҫ�����arr����ΪN��Ҫ��ʱ�临�Ӷ�ΪO(N),����Ŀռ临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
*/

#include <iostream>

int maxSum(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int max = INT_MIN;
	int cur = 0;
	for (int i = 0; i != len; i ++) {
		cur += arr[i];
		max = max > cur ? max : cur;
		cur = cur < 0 ? 0 : cur;
	}
	return max;
}

int main() {
	int arr[] = {1, -2, 3, 5, -2, 6, -1};
	std::cout << maxSum(arr, 7) << std::endl;

	return 0;
}