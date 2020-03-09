/*
【名称】蓄水池算法
【题目】有一个机器按自然数序列的方式吐出球（1，2，3...），你有一个袋子，袋子
最多只能装下K个球，并且除袋子外，没有更多空间。设计一种选择方式，使得当机器
吐出第N号球的时候（N>K）,袋子中的球是K个，同时可以保证从1号到N号球中的每一个，
被选进袋子的概率都是K/N。有一个只能装下10个球的袋子，当吐出100个球时，袋子里
有10个球，且1-100号中的每一个球被选中的概率都是10/100.然后继续吐球。当吐出1000
个球时，袋子里有10个球，且1-1000中的每一个球被选中的概率都是10/1000.当吐出i个
球时，袋子里有10个球，且1-i号中的每一个球被选中的概率都是10/i.
【难度】尉
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

int rand(int max) {
	return rand() % max + 1;
}

int* getKNumsRand(int k, int max) {
	if (max < 1 || k < 1) {
		return nullptr;
	}
	int len = k < max ? k : max;
	int* res = new int[len];
	memset(res,0, sizeof(int) * len );
	for (int i = 0; i < len; i ++) {
		res[i] + i + 1;
	}
	for (int i = k + 1; i < max + 1; i ++) {
		if (rand(i) <= k) {
			res[rand(k) - 1] = i;
		}
	}
	return res;
}

int main() {
	std::srand(time(NULL));

	int* res = getKNumsRand(10, 100);
	for (int i = 0; i < 10; i ++) {
		std::cout << res[i] << std::endl;
	}
	return 0;
}