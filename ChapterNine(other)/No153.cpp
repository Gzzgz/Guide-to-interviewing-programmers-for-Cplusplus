/*
�����ơ����ǹ�����
����Ŀ��һȺ��������Ϸ���������������Ϸ�÷������ǹ���Ҫ�����£�
1.ÿ�����Ӳ��ܵ÷ֶ��٣�����ֵ�1���ǹ���
2.�����������ڵĺ���֮�䣬�÷ֽ϶�ĺ��ӱ����ö�һЩ�ǹ���
����һ������arr����÷����飬�뷵��������Ҫ�����ǹ���
arr=[1,2,2],�ǹ�����[1,2,1],����4
��������Ŀ��
3.�����������ں���֮������÷�һ�����ǹ���������ͬ��
arr=[1,2,2],�ǹ�����[1,2,2]������5.
Ҫ��ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1).
���Ѷȡ�У
*/
#include <iostream>

int rightCands(int left, int right) {
	int n = right - left + 1;
	return n + n * (n - 1) / 2;
}

int nextMinIndex1(int* arr, int len, int start) {
	for (int i = start; i != len - 1; i ++) {
		if (arr[i] <= arr[i + 1]) {
			return i;
		}
	}
	return len - 1;
}

int candy1(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 0;
	}
	int index = nextMinIndex1(arr, len, 0);
	int res = rightCands(0, index++);
	int lbase = 1;
	int next = 0;
	int rcands = 0;
	int rbase = 0;
	while (index != len) {
		if (arr[index] > arr[index - 1]) {
			res += ++lbase;
			index++;
		}
		else if (arr[index] < arr[index - 1]) {
			next = nextMinIndex1(arr, len, index - 1);//index
			rcands = rightCands(index - 1, next++);
			rbase = next - index + 1;
			res += rcands + (rbase > lbase ? -lbase : -rbase);
			lbase = 1;
			index = next;
		}
		else {
			res += 1;
			lbase = 1;
			index++;
		}
	}
	return res;
}

int* rightCandsAndBase(int* arr, int left, int right) {
	int base = 1;
	int cands = 1;
	for (int i = right - 1; i >= left; i --) {
		if(arr[i] == arr[i + 1]){
			cands += base;
		}
		else {
			cands += ++base;
		}
	}
	return new int[2] {cands, base};
}

int nextMinIndex2(int* arr, int len, int start) {
	for (int i = start; i != len - 1; i ++) {
		if (arr[i] < arr[i + 1]) {
			return i;
		}
	}
	return len - 1;
}

int candy2(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 0;
	}
	int index = nextMinIndex2(arr, len, 0);
	int* data = rightCandsAndBase(arr, 0, index++);
	int res = data[0];
	int lbase = 1;
	int same = 1;
	int next = 0;
	while (index != len) {
		if (arr[index] > arr[index - 1]) {
			res += ++lbase;
			same = 1;
			index++;
		}
		else if (arr[index] < arr[index - 1]) {
			next = nextMinIndex2(arr, len, index - 1);// index
			data = rightCandsAndBase(arr, index - 1, next ++);
			if (data[1] <= lbase) {
				res += data[0] - data[1];
			}
			else {
				res += -lbase * same + data[0] - data[1] + data[1] * same;
			}
			index = next;
			lbase = 1;
			same = 1;
		}
		else {
			res += lbase;
			same++;
			index++;
		}
	}
	return res;
}

int main() {

	int arr[] = {1,4,5,9,3,2};
	std::cout << candy2(arr, 6) << std::endl;

	return 0;
}