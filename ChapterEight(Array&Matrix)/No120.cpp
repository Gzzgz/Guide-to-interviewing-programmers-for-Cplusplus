/*
�����ơ���Ȼ�����������
����Ŀ������һ������ΪN����������arr��������N��������ȵ���Ȼ��1-N����ʵ��arr
�����򣬵��ǲ�Ҫ���±�0~N-1λ���ϵ���ͨ��ֱ�Ӹ�ֵ�ķ�ʽ�滻��1-N
Ҫ��ʱ�临�Ӷ�ΪO(N),����ռ临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
*/

#include <iostream>

void sort1(int* arr, int len) {
	int tmp = 0;
	int next = 0;
	for (int i = 0; i != len; i ++) {
		tmp = arr[i];
		while (arr[i] != i + 1) {
			next = arr[tmp - 1];
			arr[tmp - 1] = tmp;
			tmp = next;
		}
	}
}

void sort2(int* arr, int len) {
	int tmp = 0;
	for (int i = 0; i != len; i ++) {
		while (arr[i] != i + 1) {
			tmp = arr[arr[i] - 1];
			arr[arr[i] - 1] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main() {

	int arr[] = {5, 4, 3, 1, 2};
	
	sort1(arr, 5);
	sort2(arr, 5);

	for (int i = 0; i < 5; i ++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}