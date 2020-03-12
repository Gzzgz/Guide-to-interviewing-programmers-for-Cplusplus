/*
�����ơ�Manacher�㷨
����Ŀ������һ���ַ���str,����str������Ӵ����ȡ�
��������Ŀ�������ַ���str��ͨ������ַ��ķ�ʽʹ��str���嶼��ɻ����ַ�����
��Ҫ��ֻ����str��ĩβ����ַ����뷵����str������ӵ�����ַ�����
Ҫ�����str����N,���ԭ����ͽ��������ʱ�临�Ӷ�O(N)
���Ѷȡ���
*/
#include <iostream>
#include <string>


std::string manacherString(std::string str) {
	char* res = new char[str.length() * 2 + 1];
	int index = 0;
	for (int i = 0; i < str.length() * 2 + 1;i ++) {
		res[i] = (i & 1) == 0 ? '#' : str[index++];
	}
	return std::string(res, str.length() * 2 + 1);
}

int minf(int a, int b) {
	return a < b ? a : b;
}

int maxf(int a, int b) {
	return a > b ? a : b;
}

int maxLcpsLength(std::string str) {
	if (str == "" || str.length() == 0) {
		return 0;
	}
	std::string charArr = manacherString(str);
	int* pArr = new int[charArr.length()];
	int index = -1;
	int pR = -1;
	int max = INT_MIN;
	for (int i = 0; i < charArr.length(); i ++) {
		pArr[i] = pR > i ? minf(pArr[2 * index - i], pR - i) : 1;
		while (i + pArr[i] < charArr.length() && (i - pArr[i] > -1)) {
			if (charArr[i + pArr[i]] == charArr[i - pArr[i]]) {
				pArr[i]++;
			}
			else {
				break;
			}
		}
		if (i + pArr[i] > pR) {
			pR = i + pArr[i];
			index = i;
		}
		max = maxf(max, pArr[i]);
	}
	return max - 1;
}

std::string shortestEnd(std::string str) {
	if (str == "" || str.length() == 0) {
		return "";
	}
	std::string charArr = manacherString(str);
	int* pArr = new int[charArr.length()];
	int index = -1;
	int pR = -1;
	int max = INT_MIN;
	for (int i = 0; i < charArr.length(); i++) {
		pArr[i] = pR > i ? minf(pArr[2 * index - i], pR - i) : 1;
		while (i + pArr[i] < charArr.length() && (i - pArr[i] > -1)) {
			if (charArr[i + pArr[i]] == charArr[i - pArr[i]]) {
				pArr[i]++;
			}
			else {
				break;
			}
		}
		if (i + pArr[i] > pR) {
			pR = i + pArr[i];
			index = i;
		}
		if (pR == charArr.length()) {
			max = pArr[i];
			break;
		}
	}
	char* res = new char[str.length() - max + 1];
	for (int i = 0; i < str.length() - max + 1; i ++) {
		res[str.length() - max + 1 - 1 - i] = charArr[i * 2 + 1];
	}
	return std::string(res, str.length() - max + 1);
}


int main(){

	std::string str = "ab12321b";
	std::cout << maxLcpsLength(str) << std::endl;
	std::cout << shortestEnd(str) << std::endl;

	return 0;
}