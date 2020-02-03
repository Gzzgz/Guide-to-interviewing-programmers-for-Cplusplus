/*
�����ơ������καȽ��ж��ҳ��������нϴ����
����Ŀ����������32λ����a,b������a��b�нϴ�ġ�
Ҫ�󣺲����καȽ��жϡ�
���Ѷȡ�У
*/

#include <iostream>

int flip(int n) {
	return n ^ 1;
}

int sign(int n) {
	return flip((n >> 31) & 1);
}

int getMax1(int a, int b) {
	int c = a - b;
	int scA = sign(c);
	int scB = flip(scA);
	return a * scA + b * scB;
}

int getMax2(int a, int b) {
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	int difSab = sa ^ sb;
	int sameSab = flip(difSab);
	int returnA = difSab * sa + sameSab * sc;
	int returnB = flip(returnA);

	return a * returnA + b * returnB;
}

int main() {

	std::cout << getMax1(12, 2) << std::endl;
	std::cout << getMax2(12, 2) << std::endl;
	return 0;
}