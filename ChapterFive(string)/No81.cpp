/*
�����ơ��ַ����ĵ������滻
����Ŀ������һ���ַ������͵�����chas[]��chas�Ұ���ȫ�ǿ��ַ����������
���п��ַ��������뽫����������еĿո��ַ��滻��"%20"������chas�Ұ���
�㹻�󣬿��������滻����Ҫ�Ŀռ䣬������滻������
Ҫ���滻������ʱ�临�Ӷ�ΪO(N),����ռ临�Ӷ�ΪO(1)
��������Ŀ������һ���ַ����͵�����chas[]������ֻ���������ַ��͡�*���ַ���
����������еġ�*���ַ�Ų��chas����ߣ������ַ�Ų��chas���ұߣ�����ɵ��Ժ�����
Ҫ��
1.����������ʱ�临�Ӷ�ΪO(N),����ռ临�Ӷ�ΪO(1)
2.���øı������ַ������ҳ��ֵ�˳��
���Ѷȡ�ʿ
*/

#include <iostream>

std::string replace(std::string str) {
	if (str =="") {
		return "";
	}
	int num = 0;
	int len = 0;
	for (len = 0; len < str.length() && str[len] != 0; len ++) {
		if (str[len] == ' ') {
			num++;
		}
	}
	int j = len + num * 2 - 1;
	for (int i = len - 1; i > -1; i --) {
		if (str[i] != ' ') {
			str[j--] = str[i];
		}
		else {
			str[j --] = '0';
			str[j --] = '2';
			str[j--] = '%';
		}
	}
	return str;
}

std::string modify(std::string str) {
	if (str == "") {
		return "";
	}
	int j = str.length() - 1;
	for (int i = str.length() - 1; i > -1; i --) {
		if (str[i] != '*') {
			str[j--] = str[i];
		}
	}
	for (; j > -1; ) {
		str[j--] = '*';
	}
	return str;
}

int main() {

	std::string str1 = "a b  c###########";
	std::string str2 = "121**345";
	//std::cout << replace(str1).c_str() << std::endl;

	std::cout << modify(str2).c_str() << std::endl;

	return 0;
}