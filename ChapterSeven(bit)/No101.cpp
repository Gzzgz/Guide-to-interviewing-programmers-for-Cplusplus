/*
�����ơ����ö��������������������ֵ
����Ŀ����β����κζ��������������������ֵ
���Ѷȡ�ʿ
*/


#include <iostream>

int main() {

	int a = 4;
	int b = 3;

	a ^= b;
	b ^= a;
	a ^= b;
	std::cout << a << " " << b << " " << std::endl;

	return 0;
}