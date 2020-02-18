/*
�����ơ���С�����Ӵ��ĳ���
����Ŀ�������ַ���str1, str2�� ��str1���Ӵ��к���str2�����ַ�����С�Ӵ����ȡ�
���Ѷȡ�У
*/

#include <iostream>
#include <string>


int minLength(std::string str1, std::string str2) {

	if (str1 == "" || str2 == "" || str1.length() < str2.length()) {
		return 0;
	}
	int map[256];
	memset(map, 0, sizeof(int) * 256);
	for (int i = 0; i < str2.length(); i ++) {
		map[str2[i]]++;
	}
	int left = 0; 
	int right = 0;
	int match = str2.length();
	int min = INT_MAX;
	
	while (right != str1.length()) {

		map[str1[right]]--;
		if (map[str1[right]] >= 0) {
			match--;
		}
		if (match == 0) {
			while (map[str1[left]] < 0) {
				map[str1[left++]]++;
			}
			min = min < right - left + 1 ? min : right - left + 1;
			match++;
			map[str1[left++]]++;
		}
		right++;
	}
	return min == INT_MAX ? 0 : min;
}


int main() {

	std::string str1 = "adabbca", str2 = "acb";

	std::cout << minLength(str1, str2) << std::endl;

	return 0;
}