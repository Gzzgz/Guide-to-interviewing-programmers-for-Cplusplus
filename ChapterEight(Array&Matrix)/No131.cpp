/*
�����ơ�������δ���ֵ���С������
����Ŀ������һ��������������arr���ҵ�������δ���ֵ���С������
arr=[-1,2,3,4],����1
���Ѷȡ�ξ
*/

#include <iostream>

int missNum(int arr[], int len) {
	int left = 0;
	int right = len;
	while (left < right) {
		if (arr[left] == left + 1) {
			left++;
		}
		else if (arr[left] > right ||arr[left] <= left 
			|| arr[arr[left] - 1] == arr[left]) {
			arr[left] = arr[--right];
		}
		else {
			int tmp = arr[left];
			arr[left] = arr[arr[left] - 1];
			arr[tmp - 1] = tmp;
		}
	}
	return left + 1;
}



int main() {
	int arr[] = {5,4,3,2,1};
	std::cout << missNum(arr, 5) << std::endl;
	return 0;
}