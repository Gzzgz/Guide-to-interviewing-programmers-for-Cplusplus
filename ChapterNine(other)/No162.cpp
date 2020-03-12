/*
�����ơ�KMP�㷨
����Ŀ�����������ַ���str��match�����ȷֱ�ΪN,M��ʵ��һ���㷨������ַ���str�к����Ӵ�match��
�򷵻�match��str�п�ʼ��λ�ã���������-1
Ҫ�����match���ȴ���strֱ�ӷ���-1�����N>=M��Ҫ��ʱ�临�Ӷ�O(N)
���Ѷȡ���
*/
#include <iostream>
#include <string>


int* getNextArray(std::string ms) {
	if (ms.length() == 1) {
		return new int[1]{-1};
	}
	int* next = new int[ms.length()];
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int cn = 0;
	while (pos < ms.length()) {
		if (ms[pos - 1] == ms[cn]) {
			next[pos++] = ++cn;
		}
		else if (cn > 0) {
			cn = next[cn];
		}
		else {
			next[pos++] = 0;
		}
	}
	return next;
}

int getIndexOf(std::string s, std::string m) {
	if (s.length() < 1 || m.length() < 1 || s.length() < m.length()) {
		return -1;
	}
	int si = 0;
	int mi = 0;
	int* next = getNextArray(m);
	while (si < (int)s.length() && mi < (int)m.length()) {
		if (s[si] == m[mi]) {
			si++;
			mi++;
		}
		else if (next[mi] == -1) {
			si++;
		}
		else {
			mi = next[mi];
		}
	}
	return mi == m.length() ? si - mi : -1;
}


void getNext(std::string p, int* next) {
	next[0] = -1;
	if (p.length() == 1) {
		return;
	}

	int i = 0;
	int j = -1;

	while (i < (int)p.length()) {
		if (j == -1 || p[i] == p[j]) {

			next[++i] = ++j;
			
		}
		else {
			j = next[j];
		}
	}
}

int KMP(std::string t, std::string p) {
	if (t.length() < 1 || p.length() < 1 || t.length() < p.length()) {
		return -1;
	}

	int i = 0;
	int j = 0;
	int* next = new int[p.length()];
	
	getNext(p, next);

	while(((int)p.length() > j) && (i < t.length()))
	{
		if ((j == -1) || (t[i] == p[j])) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == p.length()) {
		return i - j;
	}
	else {
		return -1;
	}
}

int main() {

	std::string s = "abcbbc";
	std::string m = "cbbc";

	std::cout << getIndexOf(s, m) << std::endl;
	std::cout << KMP(s, m) << std::endl;

	return 0;
}