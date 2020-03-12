/*
�����ơ�һ���ַ��������ֵĶ�Ӧ��ϵ
����Ŀ��һ��char���͵�����chs���������е��ַ�����ͬ��
chs=['A', 'B', 'C'],���ַ����������Ķ�Ӧ��ϵ���£�
A,B,C,AA,AB,,,CC,AAA,,,CCC,AAAA...
1,2,3,4, 5    12, 13   39   40
����һ������chs��ʵ�ָ��ݶ�Ӧ��ϵ����ַ����������໥ת��������������
���Ѷȡ�У
*/
#include <iostream>
#include <string>

char getKthCharAtChs(std::string chs, int k) {
	if (k < 1 || k > chs.length()) {
		return  0;
	}
	return chs[k - 1];
}

std::string getString(std::string chs, int n) {
	if (chs.length() == 0 || n < 1) {
		return "";
	}
	int cur = 1;
	int base = chs.length();
	int len = 0;
	while (n >= cur) {
		len++;
		n -= cur;
		cur *= base;
	}
	std::string res = "";
	int index = 0;
	int nCur = 0;
	do {
		cur /= base;
		nCur = n / cur;
		res += getKthCharAtChs(chs, nCur + 1);
		n %= cur;
		index++;
	} while (index < len);
	
	return res;
}

int getNthFromChar(std::string chs, char ch) {
	int res = -1;
	for (int i = 0; i < chs.length(); i ++) {
		if (chs[i] == ch) {
			res = i + 1;
			break;
		}
	}
	return res;
}

int getNum(std::string chs, std::string str) {
	if (chs.length() == 0) {
		return 0;
	}
	int base = chs.length();
	int cur = 1;
	int res = 0;
	for (int i = str.length() - 1; i != -1; i --) {
		res += getNthFromChar(chs, str[i]) * cur;
		cur *= base;
	}
	return res;
}

int main() {

	std::string test = getString("ABCD", 16);

	std::cout << test.c_str() << std::endl;

	std::cout<<getNum("ABCD", test)<<std::endl;

	return 0;
}