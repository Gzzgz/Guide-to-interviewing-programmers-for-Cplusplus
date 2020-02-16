/*
�����ơ���Ծ��Ϸ
����Ŀ����������arr��arr[i]=k������Դ�λ��i������1-k�����룬����arr[2]==3,
�����λ��2��������λ��3��4��5�������λ��0������������������������arr����λ����
Ҫ�����arr����ΪN,Ҫ��ʵ��ʱ�临�Ӷ�ΪO(N),����ռ临�Ӷ�ΪO(1)�ķ���
���Ѷȡ�ʿ
*/

#include <iostream>

int jump(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int jump = 0;
	int cur = 0;
	int next = 0;
	for (int i = 0; i < len; i ++) {
		if (cur < i) {
			jump++;
			cur = next;
		}
		next = next > (i + arr[i]) ? next : (i + arr[i]);
	}
	return jump;
}

int main() {

	int arr[] = {3,2,3,1,1,4};
	std::cout << jump(arr, 6) << std::endl;

	return 0;
}