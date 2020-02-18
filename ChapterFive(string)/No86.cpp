/*
【名称】公式字符串求值
【题目】给定一个字符串str，str表示一个公式，公式里可能有整数、加减乘除符号和左右括号，返回公式的计算结果
例如：str="3+1*4",返回7.
【说明】
1.可以认为给定的字符串一定是正确的公式，即不需要对str做公式有效性检查；
2.如果是负数，就需要用括号括起来，比如"4*(-3)",但如果负数作为公示的开头
或括号部分的开头，则可以没有括号，比如"-3*4"和"(-3*4)"都是合法的。
3.不用考虑计算过程中回发生溢出的情况。
【难度】校
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