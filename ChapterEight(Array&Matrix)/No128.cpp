/*
�����ơ���������λ��ֵ���۳�����
����Ŀ������һ����������arr�����ز�������λ��ֵ���۳�����
����arr=[2,3,1,4],����[12,8,24,6]�������Լ��⣬����λ���ϵ��۳�
Ҫ��ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
��������Ŀ����ʱ��Ϳռ临�Ӷ�Ҫ�󲻱䣬���Ҳ�����ʹ�ó���
*/

#include <iostream>
#include <vector>

std::vector<int> product1(int* arr, int len) {
	std::vector<int> res(len);
	if (len < 2) {
		return res;
	}
	int count = 0;
	int all = 1;
	for (int i = 0; i != len; i ++) {
		if (arr[i] != 0) {
			all *= arr[i];
		}
		else {
			count++;
		}
	}
	if (count == 0) {
		for (int i = 0; i < len; i ++) {
			res[i] = all / arr[i];
		}
	}
	if (count == 1) {
		for (int i = 0; i != len; i ++) {
			if (arr[i] == 0) {
				res[i] = all;
			}
		}
	}
	return res;
}

std::vector<int> product2(int* arr, int len) {
	std::vector<int> res(len);
	if (len < 2) {
		return res;
	}
	res[0] = arr[0];
	for (int i = 1; i < len; i ++) {
		res[i] = res[i - 1] * arr[i];
	}
	int tmp = 1;
	for (int i = len - 1; i > 0; i --) {
		res[i] = res[i - 1] * tmp;
		tmp *= arr[i];
	}
	res[0] = tmp;
	return res;
}

int main() {

	int arr[] = {2,3,1,4};
	//std::vector<int> res = product1(arr, 4);
	std::vector<int> res = product2(arr, 4);
	for (int i = 0; i < 4; i ++) {
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}