/*
�����ơ������partition����
����Ŀ������һ����������arr������arrʹ������������߲���û���ظ�Ԫ��������
�����ñ�֤�Ҳ����Ƿ�����
���磺arr=[1,2,2,2,3,3,4,5,6,6,7,7,8,8,8,9],������arr=[1,2,3,4,5,6,7,8,9,...]
��������Ŀ��
����һ������arr������ֻ������0��1��2����ֵ����ʵ��arr������.
��һ���ʷ�Ϊ����һ�����飬����ֻ�к�������ͻ�����ʵ�ֺ���ȫ������������
������м䣬��������ұߣ�
��һ���ʷ�Ϊ����һ�����飬�ٸ���һ��ֵk,��ʵ�ֱ�kС�����������������ߣ�����
k����������������м䣬��k�����������������ұ�
Ҫ��:1.������Ŀʵ�ֵ�ʱ�临�Ӷ�ΪO(N);����ռ临�Ӷ�O(1)
���Ѷȡ�ʿ
*/

#include <iostream>

void leftUnique(int* arr, int len) {
	if (len < 2) {
		return;
	}
	int u = 0;
	int i = 1;
	while (i != len) {
		if (arr[i++] != arr[u]) {
			int tmp = arr[u+1];
			arr[++u] = arr[i - 1];
			arr[i - 1] = tmp;
		}
	}
}

void sort(int* arr, int len) {
	if (len < 2) {
		return;
	}
	int left = -1;
	int index = 0;
	int right = len;
	while (index < right) {
		if (arr[index] == 0) {
			int tmp = arr[left + 1];
			arr[++left] = arr[index];
			arr[index++] = tmp;
		}
		else if (arr[index] == 2) {
			int tmp = arr[index];
			arr[index] = arr[right - 1];
			arr[--right] = tmp;
		}
		else {
			index++;
		}
	}
}

int main() {

	int arr[15] = {1,2,2,2,3, 3,4,5,6,7, 7,8,8,8,9};
	leftUnique(arr, 15);
	for (int i = 0; i < 15; i ++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int arr1[8] = {0,1,1,2,0,1,1,2};
	sort(arr1, 8);
	for (int i = 0; i < 8; i ++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}