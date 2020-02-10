/*
�����ơ���ֽ����
����Ŀ�����һ��ֽ�����ŷ��������ϣ�Ȼ���ֽ�����±����Ϸ�����1�Σ�ѹ���ۺ�
��չ������ʱ�ۺ��ǰ���ȥ�ģ����ۺ�ͻ��ķ���ָ��ֽ���ı��档�����ֽ�����±�
���Ϸ���������2�Σ�ѹ���ۺۺ�չ������ʱ�������ۺۣ����ϵ������������ۺۣ����ۺۣ�
���ۺۡ�����һ���������N,����ֽ�������±����Ϸ���������N�Σ�����ϵ��´�ӡ
�����ۺ۵ķ���
���磺N=1��down
N=2, down,down,up
���Ѷȡ�ξ
*/
#include <iostream>


void printProcess(int i, int n, bool down) {
	if (i > n) {
		return;
	}
	printProcess(i + 1, n, true);
	std::string str = down ? "down" : "up";
	std::cout << str.c_str() << std::endl;
	printProcess(i + 1, n, false);
}

void printAllFolds(int n) {
	printProcess(1, n, true);
}


int main() {

	printAllFolds(2);

	return 0;
}