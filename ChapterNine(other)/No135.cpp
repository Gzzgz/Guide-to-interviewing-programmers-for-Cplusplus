/*
�����ơ��йؽ׳˵���������
����Ŀ������һ���Ǹ�����N,����N!�����ĩβΪ0��������
���磺5��=120������1
��������Ŀ������һ���Ǹ�����N,����ö����������N���Ľ�����������λ��1��
�ĸ�λ���ϣ���Ϊ���ҵ�λ��Ϊλ��0
���Ѷȡ�ԭ���⣺ξ�� �������⣺У
*/

#include <iostream>

int zeroNum1(int num) {
	if (num < 0) {
		return 0;
	}
	int res = 0;
	int cur = 0;
	for (int i = 5; i < num + 1; i += 5) {
		cur = i;
		while (cur % 5 == 0) {
			res++;
			cur /= 5;
		}
	}
	return res;
}

int zeroNum2(int num) {
	if (num < 0) {
		return 0;
	}
	int res = 0;
	while (num != 0) {
		res += num / 5;
		num /= 5;
	}
	
	return res;
}

int rightOne1(int num) {
	if (num < 1) {
		return -1;
	}
	int res = 0;
	while (num != 0) {
		num >>= 1;
		res += num;
	}
	return res;
}

int rightOne2(int num) {
	if (num < 1) {
		return -1;
	}
	int ones = 0;
	int tmp = num;
	while (tmp != 0) {
		ones += (tmp & 1) != 0 ? 1 : 0;
		tmp >>= 1;
	}
	return num - ones;
}

int main() {

	long n = 1000000000;
	std::cout << zeroNum2(n) << std::endl;
	std::cout << rightOne2(n) << std::endl;

	return 0;
}