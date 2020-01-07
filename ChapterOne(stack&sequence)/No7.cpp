/*
�����ơ����ɴ������ֵ����
����Ŀ����һ����������arr��һ����СΪw�Ĵ��ڴ����������߻������ұߣ�����ÿ�����ұ߻�һ��λ�á�
��ʵ��һ���������������Ϊn - w + 1������res,res[i]��ʾÿһ�ִ���״̬�µ����ֵ��
���Ѷȡ�ξ
*/

#include <iostream>
#include <deque>


void getMaxWindow(int arr[], int arr_len, int w, int* res) {

	if (w < 1 || arr_len < 1 || arr_len < w)
		return ;
	std::deque<int> qmax(0);

	int index = 0;
	for (int i = 0; i < arr_len; i++) {
		while (!qmax.empty() && arr[qmax.back()] <= arr[i]) {
			qmax.pop_back();
		}
		qmax.push_back(i);
		if (qmax.front() == i - w) {
			qmax.pop_front();
		}
		if (i >= w - 1) {
			res[index++] = arr[qmax.front()];
		}
	}
}

int main() {

	int intArry[] = {4, 3, 5, 4, 3, 3, 6, 7};
	int len = 8, w = 3;
	int* res = new int[len - w + 1];
	getMaxWindow(intArry, 8, 3, res);

	for (int i = 0; i < len - w + 1; i++)
		std::cout << res[i] << std::endl;

	delete[] res;

	return 0;
}