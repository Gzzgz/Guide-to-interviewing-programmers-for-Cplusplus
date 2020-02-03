/*
�����ơ�ƴ�������ַ��������ֵ�˳����С�Ĵ�д�ַ���
����Ŀ������һ���ַ������͵�����strs,���ҵ�һ��ƴ��˳��ʹ�ý����е�
�ַ���ƴ��������ɵĴ�д�ַ��������п��������ֵ�˳����С�ģ����������
��д�ַ�����
���Ѷȡ�У
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int compare(std::string a, std::string b) {
	return (a + b) < (b + a) ? 1 : 0;
}

std::string lowestString(std::vector<std::string> strs) {
	if (strs.size() == 0) {
		return "";
	}
	sort(strs.begin(), strs.end(), compare);
	std::string res = "";
	for (int iter = 0; iter < strs.size(); iter++) {
		res += strs[iter];
	}
	return res;
}

int main() {

	std::vector<std::string> strs = {"bg", "be"};
	std::string res = lowestString(strs);

	std::cout << "res " << res << std::endl;

	return 0;
}