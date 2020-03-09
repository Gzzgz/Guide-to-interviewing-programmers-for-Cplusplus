/*
�����ơ���ˮ���㷨
����Ŀ����һ����������Ȼ�����еķ�ʽ�³���1��2��3...��������һ�����ӣ�����
���ֻ��װ��K���򣬲��ҳ������⣬û�и���ռ䡣���һ��ѡ��ʽ��ʹ�õ�����
�³���N�����ʱ��N>K��,�����е�����K����ͬʱ���Ա�֤��1�ŵ�N�����е�ÿһ����
��ѡ�����ӵĸ��ʶ���K/N����һ��ֻ��װ��10����Ĵ��ӣ����³�100����ʱ��������
��10������1-100���е�ÿһ����ѡ�еĸ��ʶ���10/100.Ȼ��������򡣵��³�1000
����ʱ����������10������1-1000�е�ÿһ����ѡ�еĸ��ʶ���10/1000.���³�i��
��ʱ����������10������1-i���е�ÿһ����ѡ�еĸ��ʶ���10/i.
���Ѷȡ�ξ
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