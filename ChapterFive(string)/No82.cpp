/*
�����ơ���ת�ַ���
����Ŀ������һ���ַ����͵�����chas�����ڵ��ʼ������������ֻҪ��������˳�����򼴿ɣ���
�ո��λ��û���ر�Ҫ��
��������Ŀ������һ���ַ����͵�����chas��һ������size����Ѵ�СΪsize��
����������Ƶ��Ұ������Ұ��������Ƶ���ߡ�
Ҫ�����chas����ΪN,�����ⶼҪ��ʱ�临�Ӷ�ΪO(N),����ռ临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
*/

#include <iostream>

void reverse(std::string& str, int start, int end) {
	char tmp = 0;
	while (start < end) {
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

std::string rotateWord(std::string str) {

	if (str == "") {
		return str;
	}
	reverse(str, 0, str.length() - 1);
	int left = -1;
	int right = -1;
	for (int i = 0; i < str.length(); i ++) {
		if (str[i] != ' ') {
			left = (i == 0 || str[i - 1] == ' ') ? i : left;
			right = (i == str.length() - 1 || str[i + 1] == ' ') ? i : right;
		}
		if (left != -1 && right != -1) {
			reverse(str, left, right);
			left = -1;
			right = -1;
		}
	}

	return str;
}

std::string rotate1(std::string str, int size) {
	if (str == "" || size <= 0 || size >= str.length()) {
		return "";
	}
	reverse(str, 0, size - 1);
	reverse(str, size, str.length() - 1);
	reverse(str, 0, str.length() - 1);

	return str;
}

void exchange(std::string& str, int start, int end, int size) {
	int i = end - size + 1;
	char tmp = 0;
	while (size -- != 0) {
		tmp = str[start];
		str[start] = str[i];
		str[i] = tmp;
		start++;
		i++;
	}
}

std::string rotate2(std::string str, int size) {

	if (str == "" || size <= 0 || size >= str.length()) {
		return "";
	}
	int start = 0;
	int end = str.length() - 1;
	int lpart = size;
	int rpart = str.length() - size;
	int s = lpart < rpart ? lpart : rpart;
	int d = lpart - rpart;
	while (true) {
		exchange(str, start, end, s);
		if (d == 0) {
			break;
		}
		else if (d > 0) {
			start += s;
			lpart = d;
		}
		else {
			end -= s;
			rpart = -d;
		}
		s = lpart < rpart ? lpart : rpart;
		d = lpart - rpart;
	}
	return str;
}

int main() {

	std::string str1 = "dog loves pig";
	std::string str2 = "ABCDE";

	//std::cout << rotateWord(str1).c_str() << std::endl;
	//std::cout << rotate1(str2, 3).c_str() << std::endl;
	std::cout << rotate2(str2, 3).c_str() << std::endl;

	return 0;
}