/*
�����ơ�һ�д����������������Լ��
����Ŀ����������������0������M,N����M,N�����Լ��
���Ѷȡ�ʿ
*/

#include <iostream>

int gcd(int m, int n) {
	return n == 0 ? m : gcd(n, m % n);
}

int main() {

	std::cout << gcd(12, 8) << std::endl;

	return 0;
}