/*
�����ơ������Ķ����Ʊ�����ж��ٸ�1
����Ŀ������һ��32λ����n,��Ϊ0�������������ظ����������Ʊ����1�ĸ���
���Ѷȡ�ξ
*/

#include <iostream>

int count1(int n) {
	int res = 0;
	while (n != 0) {
		res += n & 1;
		n >>= 1;
	}
	return res;
}

int count2(int n) {
	int res = 0;
	while (n != 0) {
		n &= (n - 1);
		res++;
	}
	return res;
}

int count3(int n) {
	int res = 0;
	while (n != 0) {
		n -= n & (~n + 1);
		res++;
	}
	return res;
}

int count4(int n) {
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}

int main() {

	int a = 12;
	std::cout << count1(a) << std::endl;
	std::cout << count2(a) << std::endl;
	std::cout << count3(a) << std::endl;
	std::cout << count4(a) << std::endl;

	return 0;
}