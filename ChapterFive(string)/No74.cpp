/*
�����ơ�ȥ���ַ�������������k��0���Ӵ�
����Ŀ������һ���ַ���str��һ������k����� str��������������k��'0'�ַ�
����ʱ����k��������'0'�ַ�ȥ�������ش������ַ���
���Ѷȡ�ʿ
*/

#include <iostream>

std::string removeKZeros(std::string str, int k) {
	if (str == "" || k < 1) {
		return str;
	}

	int count = 0, start = -1;
	int* flag = new int[str.length()];
	memset(flag, 0, sizeof(int) * str.length());

	for (int i = 0; i < str.length(); i ++) {
		if (str[i] == '0') {
			count++;
			start = (start == -1) ? i : start;
		}
		else {
			if (count == k) {
				while (count -- != 0) {
					flag[start++] = 1;
				}
			}
			count = 0;
			start = -1;
		}
	}
	if (count == k) {
		while (count -- != 0) {
			flag[start++] = 1;
		}
	}

	std::string res = "";
	for (int i = 0; i < str.length(); i ++) {
		if (flag[i] == 0) {
			res += str[i];
		}
	}
	delete[] flag;

	return res;
}


int main() {

	std::string str = "A0000B000";
	int k = 3;
	std::string res = removeKZeros(str, k);
	
	std::cout << res.c_str() << std::endl;

	return 0;
}