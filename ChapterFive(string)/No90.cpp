/*
�����ơ��ҵ���ָ���������ַ�
����Ŀ���������ַ��Ķ������£�
1.�������ַ��ǳ���Ϊ1���߳���2���ַ���
2.������ʽ���Խ���Сд��ĸ��Ҳ�����Ǵ�д��ĸ+Сд��ĸ���������Ǵ�д��ĸ
+��д��ĸ
���ڸ���һ���ַ���str�� strһ���������������ַ���ȷ��ϵĽ��������"eaCCBi",
���������ַ�'e','a', 'CC'�͡�Bi��ƴ�ɡ��ٸ���һ������k,����str�е�λ�á�
�뷵�ر�kλ��ָ�е��������ַ�.
���Ѷȡ�ʿ
*/
#include <iostream>
#include <string>

std::string pointNewStr(std::string str, int k) {

	if (str == "" || k > str.length()) {
		return "";
	}
	int uNum = 0;
	for (int i = k - 1; i >= 0; i --) {
		if (!isupper(str[i])) {
			break;
		}
		uNum++;
	}
	if (uNum & 1 == 1)  {
		return str.substr(k - 1, 2);
	}
	if (isupper(str[k])) {
		return str.substr(k, 2);
	}
	return str.substr(k, 1);
}

int main() {

	std::string str = "aaABCDEcBCg";

	std::cout << pointNewStr(str, 7).c_str() << std::endl;

	return 0;
}