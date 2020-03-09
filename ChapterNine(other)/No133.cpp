/*
�����ơ���5�����7���������չ
����Ŀ������һ���ȸ����������1-5�����������rand1To5�����£�
int rand1To5(){
	return (int)(Math.random() * 5) + 1;
}
����֮�⣬����ʹ���κζ����������ƣ�����rand1To5ʵ�ֵȸ����������1-7���������rand1To7
��������Ŀ������һ����p���ʲ���0����1-p���ʲ���1���������rand01p���£�
int rand01p(){
    double p = 0.83;
	return Math.random() < p ? 0:1;
}
����֮�⣬����ʹ���κζ����������ƣ�����rand01pʵ�ֵȸ����������1-6���������rand1To6��
��������Ŀ������һ���ȸ����������1-M���������rand1ToM�����£�
int rand1ToM(int m){
    return (int)(Math.random() * m) + 1��
}
����֮�⣬����ʹ���κζ����������ƣ�����������������ֱ�Ϊm��n������rand1ToM(m)ʵ�ֵȸ���
�������1-n���������rand1ToN��
���Ѷȡ�ԭ���⣺ ξ�� �������⣺ ξ�� �������⣺ У
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

//��m������ת��ʮ������
int getNumFromSysNum(int* mSysNum, int len, int m) {
	int res = 0;
	for (int i = 0; i < len; i ++) {
		res = res * m + mSysNum[i];
	}
	return res;
}

//��valueת��m����
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

// �ȸ����������һ��0-nMsys��Χ������ֻ����ʹ��m���Ʊ��
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
			if (res[index] > nMSys[index]) {//�������ֲ�����
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