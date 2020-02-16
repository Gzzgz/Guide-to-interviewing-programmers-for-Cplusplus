/*
【名称】表达式得到期望结果的组成种数
【题目】给定一个只由0，1，&，|，^， 5种字符组成的字符串express，再给定
一个布尔值desired，返回express能有多少种组合方式，可以达到desired的结果
【难度】校
*/

#include <iostream>
#include <string>

bool isValid(std::string exp) {
	if ((exp.length() & 1) == 0) {
		return false;
	}
	for (int i = 0; i < exp.length(); i += 2) {
		if ((exp[i] != '1') && (exp[i] != '0')) {
			return false;
		}
	}
	for (int i = 1; i < exp.length(); i += 2) {
		if ((exp[i] != '&') && (exp[i] != '|') && (exp[i] != '^')) {
			return false;
		}
	}
	return true;
}

int p(std::string exp, bool desired, int left, int right) {
	if (left == right) {
		if (exp[left] == '1') {
			return desired ? 1 : 0;
		}
		else {
			return desired ? 0 : 1;
		}
	}
	int res = 0;
	if (desired) {
		for (int i = left + 1; i < right; i += 2) {
			switch (exp[i])
			{
			case '&': 
				res += p(exp, true , left, i - 1) * p (exp, true, i + 1, right);
				break;
			case '|': 
				res += p(exp, true, left, i - 1) * p(exp, false, i + 1, right);
				res += p(exp, false, left, i - 1) * p(exp, true, i + 1, right);
				res += p(exp, true, left, i - 1) * p(exp, true, i + 1, right);
				break;
			case '^': 
				res += p(exp, true, left, i - 1) * p(exp, false, i + 1, right);
				res += p(exp, false, left, i -1) * p(exp, true, i + 1, right);
				break;

			default:
				break;
			}
		}
	}
	else {
		for (int i = left + 1; i < right; i += 2) {
			switch (exp[i]) {
			case '&': 
				res += p(exp, false, left, i - 1) * p(exp, true, i + 1, right);
				res += p(exp, true, left, i - 1) * p(exp, false, i + 1, right);
				res += p(exp, false, left, i - 1) * p(exp, false, i + 1, right);
				break;
			case '|':
				res += p(exp, false, left, i - 1) * p(exp, false, i + 1, right);
				break;
			case '^':
				res += p(exp, true, left, i - 1) * p(exp, true, i + 1, right);
				res += p(exp, false, left, i -1) * p(exp, false, i + 1, right);
				break;
			}
		}
	}
	return res;
}

int num1(std::string exp, bool desired) {
	if (exp == "") {
		return 0;
	}
	if (isValid(exp) == false){
		return 0;
	}
	return p(exp, desired, 0, exp.length() - 1);
}

int num2(std::string exp, bool desired) {
	if (exp == "") {
		return 0;
	}
	if (isValid(exp) == false) {
		return 0;
	}
	int** t = new int*[exp.length()];
	int** f = new int*[exp.length()];
	for (int i = 0; i < exp.length(); i ++) {
		t[i] = new int[exp.length()];
		f[i] = new int[exp.length()];
		for (int j = 0; j < exp.length(); j ++) {
			t[i][j] = 0;
			f[i][j] = 0;
		}
	}
	t[0][0] = exp[0] == '0' ? 0 : 1;
	f[0][0] = exp[0] == '1' ? 0 : 1;
	for (int i = 2; i < exp.length(); i += 2) {
		t[i][i] = exp[i] == '0' ? 0 : 1;
		f[i][i] = exp[i] == '1' ? 0 : 1;
		for (int j = i - 2; j >= 0; j -= 2) {
			for (int k = j; k < i; k += 2) {
				if (exp[k + 1] == '&') {
					t[j][i] += t[j][k] * t[k + 2][i];
					f[j][i] += (f[j][k] + t[j][k]) * f[k + 2][i] + f[j][k] * t[k + 2][i];
				}
				else if (exp[k + 1] == '|') {
					t[j][i] += (f[j][k] + t[j][k]) * t[k + 2][i] + t[j][k] * f[k + 2][i];
					f[j][i] += f[j][k] * f[k + 2][i];
				}
				else {
					t[j][i] += f[j][k] * t[k + 2][i] + t[j][k] * f[k + 2][i];
					f[j][i] += f[j][k] * f[k + 2][i] + t[j][k] * t[k + 2][i];
				}
			}
		}
	}
	int res = desired ? t[0][exp.length() - 1] : f[0][exp.length() - 1];
	for (int i = 0; i < exp.length(); i ++) {
		delete[] t[i];
		delete[] f[i];
	}
	delete[] t;
	delete[] f;

	return res;
}

int main() {

	std::string exp = "1^0|0|1";
	std::cout << num2(exp, false) << std::endl;

	return 0;
}