/*
�����ơ���ʽ�ַ�����ֵ
����Ŀ������һ���ַ���str��str��ʾһ����ʽ����ʽ��������������Ӽ��˳����ź��������ţ����ع�ʽ�ļ�����
���磺str="3+1*4",����7.
��˵����
1.������Ϊ�������ַ���һ������ȷ�Ĺ�ʽ��������Ҫ��str����ʽ��Ч�Լ�飻
2.����Ǹ���������Ҫ������������������"4*(-3)",�����������Ϊ��ʾ�Ŀ�ͷ
�����Ų��ֵĿ�ͷ�������û�����ţ�����"-3*4"��"(-3*4)"���ǺϷ��ġ�
3.���ÿ��Ǽ�������лط�������������
���Ѷȡ�У
*/

#include <iostream>
#include <string>
#include <deque>
#include <vector>


int getNum(std::deque<std::string>& deq) {
	int res = 0;
	bool add = true;
	std::string cur = "";
	int num = 0;

	while (!deq.empty()) {
		cur = deq.front();
		deq.pop_front();

		if (cur == "+") {
			add = true;
		}
		else if (cur == "-") {
			add = false;
		}
		else {
			num = atoi(cur.c_str());
			res += add ? num : (-num);
		}
	}

	return res;
}

void addNum(std::deque<std::string>& deq, int num) {
	if (!deq.empty()) {
		int cur = 0;
		std::string top = deq.back();
		deq.pop_back();

		if (top == "+" || top == "-") {
			deq.push_back(top);
		}
		else {
			cur = atoi(deq.back().c_str());
			deq.pop_back();
			num = (top == "*") ? (cur * num) : (cur / num);
		}
	}
	deq.push_back(std::to_string(num));
}

std::vector<int> value(std::string str, int i) {

	std::deque<std::string> deq;
	int pre = 0;
	std::vector<int> bra(2);

	while (i < str.length() && str[i] != ')'){
		
		if (str[i] >= '0' && str[i] <= '9') {
			pre = pre * 10 + str[i ++] - '0';
		}
		else if (str[i] != '(') {
			addNum(deq, pre);
			deq.push_back(str.substr(i++, 1));
			pre = 0;
		}
		else {
			bra = value(str, i + 1);
			pre = bra[0];
			i = bra[1] + 1;
		}
	}
	addNum(deq, pre);
	return std::vector<int> {getNum(deq), i};
}

int getValue(std::string str) {
	return value(str, 0)[0];
}

int main() {

	std::string str = "48*((70-65)-43)+8*1";

	std::cout << getValue(str) << std::endl;

	return 0;
}