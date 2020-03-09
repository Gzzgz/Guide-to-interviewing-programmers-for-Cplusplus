/*
�����ơ���N�����ֵȸ��ʴ�ӡM����
����Ŀ������һ������N����ŷ�ظ�Ԫ�ص�����arr��һ������n��ʵ�ֺ����ȸ������
��ӡarr�е�M������
Ҫ��1.��ͬ������Ҫ�ظ���ӡ��
2.ʱ�临�Ӷ�O(M)���ռ临�Ӷ�O(1)
3.���Ըı�arr���顣
���Ѷȡ�ʿ
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int* arr, int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void printRandM(int* arr, int len, int m) {
	if (arr == nullptr || len == 0 || m < 0) {
		return;
	}
	m = len < m ? len : m;
	int count = 0;
	int i = 0;
	while (count < m) {
		i = (int)(rand() % 100 / 100.0 * (len - count));
		std::cout << arr[i] << " ";
		swap(arr, len - count++ - 1, i);
	}
	std::cout << std::endl;
}

int main() {
	srand(time(NULL));
	int arr[] = {1,2,3,4,5,6,7};
	printRandM(arr, 7, 5);

	return 0;
}