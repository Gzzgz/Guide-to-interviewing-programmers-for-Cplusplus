/*
�����ơ��ж�һ�����Ƿ��ǻ�����
����Ŀ������������ĸ��
1.���һ���Ǹ���������ȫ��Ӧ��������ǻ�������121��22��
2.���һ�������ľ���ֵ������ȫ��Ӧ��Ҳ�ǻ�������-121��-22��
����һ��32λ����num���ж�num�Ƿ��ǻ�������
���Ѷȡ�ʿ
*/
#include <iostream>

bool isPalindrome(int n) {
	if (n == INT_MIN) {
		return false;
	}
	n = std::abs(n);
	int help = 1;
	while (n / help >= 10) {
		help *= 10;
	}
	while (n != 0) {
		if (n / help != n % 10) {
			return false;
		}
		n = (n % help) / 10;
		help /= 100;
	}
	return true;
}

int main() {

	std::cout << isPalindrome(12121) << std::endl;

	return 0;
}