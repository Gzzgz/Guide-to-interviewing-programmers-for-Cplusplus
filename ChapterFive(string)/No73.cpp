/*
�����ơ��ַ����������Ӵ������
����Ŀ������һ���ַ���str��������ȫ�������ִ������������֮��
Ҫ��
1.����С�����ַ�������A1.3�������а�����������1��3
2.������������Ӵ����������ַ�"-",���������ֵ�����Ϊ����ʱ��������Ϊ����
�������ֵ�����Ϊż��ʱ��������Ϊ�������硰A-1BC--12�������а�������-1��12
���Ѷȡ�ʿ
*/

#include <iostream>

int numSum(std::string str) {
	if (str == "") {
		return 0;
	}
	int res = 0;
	int num = 0;
	bool posi = true;
	int cur = 0;
	for (int i = 0; i < str.length(); i ++) {
		cur = str[i] - '0';
		if (cur < 0 || cur > 9) {
			res += num;
			num = 0;
			if (str[i] == '-') {
				if (i - 1 > -1 && str[i - 1] == '-') {
					posi = !posi;
				}
				else {
					posi = false;
				}
			}
			else {
				posi = true;
			}
		}
		else {
			num = num * 10 + (posi ? cur : -cur);
		}
	}
	res += num;
	return res;
}

int main() {

	std::string str1 = "A1CD2E33";
	std::string str2 = "A-1B--2C--D6E";

	std::cout << numSum(str2) << std::endl;

	return 0;
}