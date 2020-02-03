/*
�����ơ��ж������ַ����Ƿ�Ϊ���δ�
����Ŀ�����������ַ���str1, str2����� str1��str2�г��ֵ��ַ�����һ����
ÿ���ַ����ֵĴ���Ҳһ������ô str1, str2��Ϊ���δʡ���ʵ�ֺ����ж�����
�ַ����Ƿ�Ϊ���δʡ�
���Ѷȡ�ʿ
*/

#include <iostream>

bool isDeformation(std::string str1, std::string str2) {

	if (str1 == "" || str2 == "" || str1.length() != str2.length()) {
		return false;
	}
	int map[256] = {0};
	for (int i = 0; i < str1.length(); i ++) {
		map[str1[i]]++;
	}
	for (int i = 0; i < str2.length(); i ++) {
		if (map[str2[i]]-- == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	std::string str1 = "123";
	std::string str2 = "321";
	std::string str3 = "221";

	std::cout << "str1 str2: " << isDeformation(str1, str2) << std::endl;
	std::cout << "str1 str3: " << isDeformation(str1, str3) << std::endl;

	return 0;
}