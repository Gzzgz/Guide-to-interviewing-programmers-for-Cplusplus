/*
�����ơ��ж������ַ����Ƿ�Ϊ��ת��
����Ŀ�����һ���ַ���str�����ַ���strǰ������Ĳ���Ų�������γɵ��ַ���
����str����ת�ʡ�����str=��12345��,str����ת����"12345","23451", "34512",
"45123","51234".���������ַ���a,b�����ж�a��b�Ƿ�Ϊ��ת�ʡ�
Ҫ�����a��b���Ȳ�һ������ôa,b��Ȼ����Ϊ��ת�ʣ�����ֱ�ӷ���false����
a��b����һ������ΪN,Ҫ��ⷨ��ʱ�临�Ӷ�ΪO(N)
���Ѷȡ�ʿ
*/

#include <iostream>


bool isRotation(std::string a, std::string b) {
	if (a == "" || b == "" || a.length() != b.length()) {
		return false;
	}
	std::string b2 = b + b;
	return b2.find(a) != -1;
}

int main() {

	std::string arr1 = "abcd";
	std::string arr2 = "cdab";
	std::string arr3 = "cdba";

	std::cout << "arr1 arr2: " << isRotation(arr1, arr2) << std::endl;
	std::cout << "arr1 arr3: " << isRotation(arr1, arr3) << std::endl;

	return 0;
}