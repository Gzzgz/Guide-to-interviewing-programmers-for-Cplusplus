/*
【名称】数字的英文表达和中文表达
【题目】给定一个32位整数num，写两个函数分别返回num的英文与中文表达字符串。
num=319
英文：three hundres nineteen
中文：三百一十九
【难度】校
*/
#include <iostream>
#include <string>

std::string num1To19(int num) {
	if (num < 1 || num > 19) {
		return "";
	}
	std::string names[] = {"One ", "Two ", "Three ", "Four ", "Five ",
	"Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
	"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Sevenlteen ",
	"Eighteen ", "Nineteen "};
	return names[num - 1];
}

std::string num1To99(int num) {
	if (num < 1 || num > 99) {
		return "";
	}
	if (num < 20) {
		return num1To19(num);
	}
	int high = num / 10;
	std::string tyNames[] = {"Twenty ", "Thirty ", "Forty ", "Fifty ",
	"Sixty ", "Seventy ", "Eighty ", "Ninety "};
	return tyNames[high - 2] + num1To19(num % 10);
}

std::string Enum1To999(int num) {
	if (num < 1 || num > 999) {
		return "";
	}
	if (num < 100) {
		return num1To99(num);
	}
	int high = num / 100;
	return num1To19(high) + "Hundred " + num1To99(num % 100);
}

std::string getNumEngExp(int num) {
	if (num == 0) {
		return "Zero";
	}
	std::string res = "";
	if (num < 0) {
		res = "Negative, ";
	}
	if (num == INT_MIN) {
		res += "Two Billion, ";
		num %= -2000000000;
	}
	num = std::abs(num);
	int high = 1000000000;
	int highIndex = 0;
	std::string names[] = {"Billion", "Million", "Thousand", ""};
	while (num != 0) {
		int cur = num / high;
		num %= high;
		if (cur != 0) {
			res += Enum1To999(cur);
			res += names[highIndex] + (num == 0 ? " " : ", ");
		}
		high /= 1000;
		highIndex++;
	}
	return res;
}

std::string num1To9(int num) {
	if (num < 1 || num > 9) {
		return "";
	}
	std::string names[] = {"一", "二", "三", "四", "五", "六", "七", "八", "九"};
	return names[num - 1];
}

std::string num1To99(int num, bool hasBai) {
	if (num < 1 || num > 99) {
		return "";
	}
	if (num < 10) {
		return num1To9(num);
	}
	int shi = num / 10;
	if (shi == 1 && (!hasBai)) {
		return "十" + num1To9(num % 10);
	}
	else {
		return num1To9(shi) + "十" + num1To9(num % 10);
	}
}

std::string num1To999(int num) {
	if (num < 1 || num > 999) {
		return "";
	}
	if (num < 100) {
		return num1To99(num, false);
	}
	std::string res = num1To9(num / 100) + "百";
	int rest = num % 100;
	if (rest == 0) {
		return res;
	}
	else if(rest >= 10){
		res += num1To99(rest, true);
	}
	else {
		res += "零" + num1To9(rest);
	}
	return res;
}

std::string num1To9999(int num) {
	if (num < 1 || num > 9999) {
		return "";
	}
	if (num < 1000) {
		return num1To999(num);
	}
	std::string res = num1To9(num / 1000) + "千";
	int rest = num % 1000;
	if (rest == 0) {
		return res;
	}
	else if (rest >= 100) {
		res += num1To999(rest);
	}
	else {
		res += "零" + num1To99(rest, false);
	}
	return res;
}

std::string num1To99999999(int num) {
	if (num < 1 || num > 99999999) {
		return "";
	}
	int wan = num / 10000;
	int rest = num % 10000;
	if (wan == 0) {
		return num1To9999(rest);
	}
	std::string res = num1To9999(wan) + "万";
	if (rest == 0) {
		return res;
	}
	else {
		if (rest < 1000) {
			return res + "零" + num1To999(rest);
		}
		else {
			return res + num1To9999(rest);
		}
	}
}

std::string getNumChiExp(int num) {
	if (num == 0) {
		return "零";
	}
	std::string res = num < 0 ? "负" : "";
	int yi = std::abs(num / 1000000000);
	int rest = std::abs(num % 1000000000);
	if (yi == 0) {
		return res + num1To99999999(rest);
	}
	res += num1To9999(yi) + "亿";
	if (rest == 0) {
		return res;
	}
	else {
		if (rest < 10000000) {
			return res + "零" + num1To99999999(rest);
		}
		else {
			return res + num1To99999999(rest);
		}
	}
}

int main() {

	std::cout << getNumEngExp(319) << std::endl;
	std::cout << getNumChiExp(319) << std::endl;

	return 0;
}