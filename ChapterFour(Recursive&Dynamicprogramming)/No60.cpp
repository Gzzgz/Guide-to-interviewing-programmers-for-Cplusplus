/*
�����ơ���ŵ������
����Ŀ������һ������n,����ŵ����Ϸ�д�С������õ�n��Բ�̣����迪ʼʱ
���е�Բ�̶�������ߵ������ϣ��밴�պ�ŵ����Ϸ��Ҫ������е�Բ�̶��Ƶ���
�ߵ������ϡ�ʵ�ֺ�����ӡ�����ƶ��켣��
��������Ŀ������һ����������arr, ����ֻ����1��2��3����������Բ��Ŀǰ��״̬��
1���������ӣ�2�����м����ӣ�3���������ӣ�arr[i]��ֵ�����i+1��Բ�̵�λ�á�
����arr[3��3��2��1]�������1��Բ�����������ϣ���2�����������ϣ���3������
�����ϣ���4�����������ϡ����arr�����״̬ʱ�����ƶ��켣�����г��ֵ�״̬��
����arr����״̬ʱ�����ƶ��켣�еĵڼ���״̬�����arr�����״̬���������ƶ�
�켣�����г��ֵ�״̬���򷵻�-1
���Ѷȡ�У
*/
#include <iostream>

void func(int n, std::string from, std::string mid, std::string to) {
	if (n == 1) {
		std::cout << "move from " << from.c_str() << " to " << to.c_str() << std::endl;
	}
	else {
		func(n - 1, from, to, mid);
		func(1, from, mid, to);
		func(n - 1, mid, from, to);
	}
}

void hanoi(int n) {
	if (n > 0) {
		func(n, "left", "mid", "right");
	}
}

int process(int* arr, int i, int from, int mid, int to) {
	if (i == -1) {
		return 0;
	}
	if (arr[i] != from && arr[i] != to) {
		return -1;
	}
	if (arr[i] == from) {
		return process(arr, i - 1, from, to, mid);
	}
	else {
		int rest = process(arr,i - 1, mid, from, to);
		
		if (rest == -1) {
			return -1;
		}
		return (1 << i) + rest;
	}
}

int step1(int* arr, int len) {
	if (len == 0) {
		return -1;
	}
	return process(arr, len - 1, 1, 2, 3);
}

int step2(int* arr, int len) {
	if (len == 0) {
		return -1;
	}
	int from = 1;
	int mid = 2;
	int to = 3;
	int i = len - 1;
	int res = 0;
	int tmp = 0;
	while (i >= 0) {
		if (arr[i] != from && arr[i] != to) {
			return -1;
		}
		if (arr[i] == to) {
			res += 1 << i;
			tmp = from;
			from = mid;
		}
		else {
			tmp = to;
			to = mid;
		}
		mid = tmp;
		i--;
	}
	return res;
}

int main() {

	hanoi(2);

	int arr[] = {3, 3};

	std::cout << step2(arr, 2) << std::endl;

	return 0;
}