/*
�����ơ������ַ���ת��Ϊ��ĸ��ϵ�����
����Ŀ������һ���ַ���str��strȫ���������ַ���ɣ����str��ĳһ����ĳ����
�����ַ���ɵ��Ӵ�ֵ��1-26֮�䣬������Ӵ�����ת��Ϊһ����ĸ���涨"1"ת��
Ϊ��A��...дһ����������str�ж����ֲ�ͬ��ת�������������������
���Ѷȡ�ξ
*/

#include <iostream>
#include <string>

int process(std::string chs, int i) {
	if (i == chs.length()) {
		return 1;
	}
	if (chs[i] == '0') {
		return 0;
	}
	int res = process(chs, i + 1);
	if (i + 1 < chs.length() && (chs[i] - '0') * 10 + chs[i + 1] - '0' < 27) {
		res += process(chs, i + 2);
	}
	return res;
}

int num1(std::string str) {
	if (str == "") {
		return 0;
	}
	return process(str, 0);
}

int num2(std::string str) {
	if (str == "") {
		return 0;
	}
	int cur = str[str.length() - 1] == '0' ? 0 : 1;
	int next = 1;
	int tmp = 0;
	for (int i = str.length() - 2; i >= 0; i --) {
		if (str[i] == '0') {
			next = cur;
			cur = 0;
		}
		else {
			tmp = cur;
			if ((str[i] - '0') * 10 + str[i + 1] - '0' < 27) {
				cur += next;
			}
			next = tmp;
		}
	}
	return cur;
}

int main() {

	std::string str = "1111";

	std::cout << num2(str) << std::endl;

	return 0;                                                                                             
}