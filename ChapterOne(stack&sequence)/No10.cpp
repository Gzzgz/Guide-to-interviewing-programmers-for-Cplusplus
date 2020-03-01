/*
�����ơ����ֵ��ȥ��СֵС�ڵ���num��������ĸ���
����Ŀ��
��Ҫ��O(N)
���Ѷȡ�У
*/
#include <iostream>
#include <deque>


int getNum(int* arr, int len, int num) {

	if (len == 0) {
		return 0;
	}
	std::deque<int> qmin, qmax;
	int i = 0;
	int j = 0;
	int res = 0;

	while (i < len) {
		while (j < len) {
			while (!qmin.empty() && arr[qmin.back()] >= arr[j]) {
				qmin.pop_back();
			}
			qmin.push_back(j);
			while (!qmax.empty() && arr[qmax.back()] <= arr[j]) {
				qmax.pop_back();
			}
			qmax.push_back(j);
			if (arr[qmax.front()] - arr[qmin.front()] > num) {
				break;
			}
			j++;
		}
		if (qmin.front() == i) {
			qmin.pop_front();
		}
		if (qmax.front() == i) {
			qmax.pop_front();
		}
		res += j - i;
		i++;
	}

	return res;
}

int main() {

	int arr[] = {1,2,3,4,5,6};

	std::cout << getNum(arr, 3, 1) << std::endl;

	return 0;
}