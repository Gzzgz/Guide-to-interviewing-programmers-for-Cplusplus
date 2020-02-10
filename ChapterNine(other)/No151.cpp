/*
�����ơ���������ת�������ҵ���Сֵ
����Ŀ����������arr���ܾ���һ����ת����Ҳ����û�У���arr���ܴ����ظ�������
������������[1,2,3,4,5,6,7],������ת����Ϊ[4,5,6,7,1,2,3]�ȣ�����һ��������ת��
����������arr������arr�е���Сֵ��
���Ѷȡ�ξ
*/

#include <iostream>

int getMin(int* arr, int len) {
	int low = 0;
	int high = len - 1;
	int mid = 0;
	while (low < high) {
		if (low == high - 1) {
			break;
		}
		if (arr[low] < arr[high]) {
			return arr[low];
		}
		mid = (low + high) / 2;
		if (arr[low] > arr[mid]) {
			high = mid;
			continue;
		}
		if (arr[mid] > arr[high]) {
			low = mid;
			continue;
		}
		while (low < mid) {
			if (arr[low] == arr[mid]) {
				low++;
			}
			else if (arr[low] < arr[mid]) {
				return arr[low];
			}
			else {
				high = mid;
				break;
			}
		}
	}

	return arr[low] < arr[high] ?  arr[low] : arr[high];
}

int main() {

	int arr[] = {4,5,6,7,1,2,3};
	std::cout << getMin(arr, 7) << std::endl;

	return 0;
}