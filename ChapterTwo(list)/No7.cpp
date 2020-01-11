/*
【名称】生成窗口最大值数组
【题目】有一个整型数组arr和一个大小为w的窗口从数组的最左边滑倒最右边，窗口每次向右边滑一个位置。
请实现一个函数，输出长度为n - w + 1的数组res,res[i]表示每一种窗口状态下的最大值。
【难度】尉
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