/*
�����ơ������������������۳˻�
����Ŀ������һ��double���͵�����arr�����е�Ԫ�ؿ���������0�������������۳˵����˻���
����arr=[-2.5,4,0,3,0.5,8,-1],������[3, 0.5, 8]�۳˿��Ի�����ĳ˻�12�����Է���12
���Ѷȡ�ξ
*/

#include <iostream>

double maxProduct(double arr[], int len) {

	if (len == 0) {
		return 0;
	}
	double max = arr[0];
	double min = arr[0];
	double res = arr[0];
	double maxend = 0;
	double minend = 0;
	for (int i = 1; i < len; i ++) {
		maxend = max * arr[i];
		minend = min * arr[i];
		max = (maxend > minend ? maxend : minend) > arr[i] ?
			(maxend > minend ? maxend : minend) : arr[i];
		res = res > max ? res : max;
	}
	return res;
}

int main() {

	double arr[] = {-2.5, 4, 0, 3, 0.5, 8, -1};
	std::cout << maxProduct(arr, 7) << std::endl;

	return 0;
}