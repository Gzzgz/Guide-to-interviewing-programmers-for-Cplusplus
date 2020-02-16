/*
�����ơ�N�ʺ�����
����Ŀ��N�ʺ�������ָ��NXN��������Ҫ��N���ʺ�Ҫ���κ������ʺ�ͬ�У���ͬ�У�
Ҳ����ͬһб���ϣ�����һ������n,����n�ʺ�İڷ��ж�����
���Ѷȡ�У
*/
#include <iostream>

bool isVaild(int* record, int i, int j) {
	for (int k = 0; k < i; k ++) {
		if (j == record[k] || std::abs(record[k] - j) == std::abs(i - k)) {
			return false;
		}
	}
	return true;
}

int process1(int i, int* record, int len) {
	if (i == len) {
		return 1;
   }
	int res = 0;
	for (int j = 0; j < len; j ++) {
		if (isVaild(record, i, j)) {
			record[i] = j;
			res += process1(i + 1, record, len);
		}
	}
	return res;
}

int num1(int n) {
	if (n < 1) {
		return 0;
	}
	int* record = new int[n];
	memset(record, 0, sizeof(int) * n);
	int r = process1(0, record, n);
	delete[] record;
	return r;
}

int process2(int upperLim, int colLim, int leftDiaLim, int rightDiaLim) {
	if (colLim == upperLim) {
		return 1;
	}
	int pos = 0;
	int mostRightOne = 0;
	pos = upperLim & (~(colLim | leftDiaLim | rightDiaLim));
	int res = 0;
	while (pos != 0) {
		mostRightOne = pos & (~pos + 1);//�����������ұߵ�1����λ��
		pos -= mostRightOne;
		res += process2(upperLim, colLim | mostRightOne,
			(leftDiaLim | mostRightOne)<<1, (rightDiaLim | mostRightOne)>>1);
	}
	return res;
}


int num2(int n) {
	if (n < 1 || n > 32) {
		return 0;
	}
	int upperLim = n == 32 ? -1 : (1 << n) - 1;
	return process2(upperLim, 0, 0, 0);
}

int main() {

	std::cout << num2(8) << std::endl;

	return 0;
}