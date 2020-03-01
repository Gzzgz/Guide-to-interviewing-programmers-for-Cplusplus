/*
�����ơ�������Ӿ���Ĵ�С
����Ŀ������һ�����;���map�����е�ֵֻ��0��1���֣�����ȫ��1�����о��������У����ľ�������Ϊ1��������
���Ѷȡ�У
*/

#include <iostream>
#include <stack>


int maxRecFromBottom(int height[], int len) {

	if (height == NULL || len == 0) {
		return 0;
	}
	int maxArea = 0;
	std::stack<int> rec_stack;
	for (int i = 0; i < len; i ++) {
		while (!rec_stack.empty() && height[i] <= height[rec_stack.top()]) {
			int j = rec_stack.top();
			rec_stack.pop();
			int k = rec_stack.empty() ? -1 : rec_stack.top();
			int curArea = (i - k - 1) * height[j];
			maxArea = (maxArea > curArea) ? maxArea : curArea;
		}
		rec_stack.push(i);
	}
	while (!rec_stack.empty()) {
		int j = rec_stack.top();
		rec_stack.pop();
		int k = rec_stack.empty() ? -1 : rec_stack.top();
		int curArea = (len - k - 1) * height[j];
		maxArea = (maxArea > curArea) ? maxArea : curArea;
	}
	return maxArea;
}

int maxRecSize(int map[][4], int len_r, int len_c) {

	if (map == nullptr || len_r == 0 || len_c == 0) {
		return 0;
	}
	int maxArea = 0;
	int* height = new int[len_c];
	memset(height, 0, sizeof(int) * len_c);

	for (int i = 0; i < len_r; i ++) {
		for (int j = 0; j < len_c; j ++) {
			height[j] = (map[i][j] == 0) ? 0 : height[j] + 1;
		}
		int com_res = maxRecFromBottom(height, len_c);
		maxArea = (com_res > maxArea) ? com_res : maxArea;
	}
	delete[] height;

	return maxArea;
}

int main() {

	int len_r = 3, len_c = 4;
	int  intArray[3][4] = { 1,0,1,1, 1,1,1,1, 1,1,1,0 };

	int res = maxRecSize(intArray, len_r, len_c);
	std::cout << res << std::endl;

	return 0;
}