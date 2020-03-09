/*
【名称】从5随机到7随机及其扩展
【题目】给定一个等概率随机产生1-5的随机函数，rand1To5，如下：
int rand1To5(){
	return (int)(Math.random() * 5) + 1;
}
除此之外，不能使用任何额外的随机机制，请用rand1To5实现等概率随机产生1-7的随机函数rand1To7
【补充题目】给定一个以p概率产生0，以1-p概率产生1的随机函数rand01p如下：
int rand01p(){
    double p = 0.83;
	return Math.random() < p ? 0:1;
}
除此之外，不能使用任何额外的随机机制，请用rand01p实现等概率随机产生1-6的随机函数rand1To6。
【进阶题目】给定一个等概率随机产生1-M的随机函数rand1ToM，如下：
int rand1ToM(int m){
    return (int)(Math.random() * m) + 1；
}
除此之外，不能使用任何额外的随机机制，有两个输入参数，分别为m，n，请用rand1ToM(m)实现等概率
随机产生1-n的随机函数rand1ToN。
【难度】原问题： 尉； 补充问题： 尉； 进阶问题： 校
*/
#include <iostream>
#include <cstdlib>
#include <ctime>


int rand1To5() {
	return std::rand() % 5 + 1;
}

int rand1To7() {
	int num = 0;
	do {
		num = (rand1To5() - 1) * 5 + rand1To5() - 1;
	} while (num > 20);
	return num % 7 + 1;
}

double rand01p() {
	double p = 0.83;
	return rand() % 100 / 100.0 < p ? 0 : 1;
}

int rand01() {
	int num;
	do {
		num = rand01p();
	} while (num == rand01p());
	return num;
}

int rand0To3() {
	return rand01() * 2 + rand01();
}

int rand1To6() {
	int num = 0;
	do {
		num = rand0To3() * 4 + rand0To3();
	} while (num > 11);
	return num % 6 + 1;
}

int rand1ToM(int m) {
	return std::rand() % m + 1;
}

//把m进制数转成十进制数
int getNumFromSysNum(int* mSysNum, int len, int m) {
	int res = 0;
	for (int i = 0; i < len; i ++) {
		res = res * m + mSysNum[i];
	}
	return res;
}

//把value转成m进制
int* getMSysNum(int value, int m) {
	int* res = new int[32];
	memset(res, 0, sizeof(int) * 32);
	int index = 31;
	while (value != 0) {
		res[index--] = value % m;
		value /= m;
	}
	return res;
}

// 等概率随机产生一个0-nMsys范围的数，只不过使用m进制表达
int* getRanMSysNumLessN(int* nMSys, int len, int m) {
	int * res = new int[len];
	memset(res, 0, sizeof(int) * len);

	int start = 0;
	while (nMSys[start] == 0) {
		start++;
	}
	int index = start;
	bool lastEqual = true;
	while (index < len) {
		res[index] = rand1ToM(m) - 1;
		if (lastEqual) {
			if (res[index] > nMSys[index]) {//超出部分不考虑
				index = start;
				lastEqual = true;
				continue;
			}else{
				lastEqual = res[index] == nMSys[index];
			}
		}
		index++;
	}
	return res;
}

int rand1ToN(int n, int m) {
	int* nMsys = getMSysNum(n - 1, m);
	int* randNum = getRanMSysNumLessN(nMsys, 32, m);
	return getNumFromSysNum(randNum, 32, m) + 1;
}

int main() {
	std::srand(time(NULL));

	for (int i = 0; i < 10; i ++) {
		//std::cout << rand1To6() << std::endl;
		std::cout << rand1ToN(7, 5) << std::endl;
	}

	return 0;
}