/*
�����ơ�����[0,x)�����ϵ������ֵĸ���
����Ŀ�����躯��Math.random()�ȸ����������һ����[0,1)��Χ�ϵ�������ô����
֪������[0,x)�����ϵ������ֵĸ���Ϊx(0<x<=1)������һ������0������k�����ҿ���
ʹ��Math.random()��������ʵ��һ��������Ȼ������[0,1)��Χ�ϵ�����������[0,x)
�����ϵ������ֵĸ���Ϊx^k(0<x<=1)��
���Ѷȡ�ʿ
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

double rand01() {
	return rand() % 1000 / 1000.0;
}

double randXPowerK(int k) {
	if (k < 1) {
		return 0;
	}
	double res = -1;
	for (int i = 0; i < k; i ++) {
		res = res > rand01() ? res : rand01();
	}
	return res;
}

int main() {

	std::cout << randXPowerK(3) << std::endl;

	return 0;
}