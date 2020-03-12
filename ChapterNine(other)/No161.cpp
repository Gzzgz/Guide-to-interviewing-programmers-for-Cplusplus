/*
【名称】Manacher算法
【题目】给定一个字符串str,返回str最长回文子串长度。
【进阶题目】给定字符串str想通过添加字符的方式使得str整体都变成回文字符串，
但要求只能在str的末尾添加字符，请返回在str后面添加的最短字符串。
要求：如果str长度N,解决原问题和进阶问题的时间复杂度O(N)
【难度】将
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