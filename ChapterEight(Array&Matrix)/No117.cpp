/*
�����ơ�δ�����������ۼӺ�Ϊ����ֵ���������ϵ������
����Ŀ������һ����������arr������Ԫ�ؿ���������0������һ������k����arr���е�
���������ۼӺ�Ϊk��������鳤�ȡ�
��������Ŀ������һ����������arr������Ԫ�ؿ���������0.��arr���е�������������
�븺��������ȵ�������鳤��
��������Ŀ������һ����������arr������Ԫ��ֻ��1��0,��arr���е���������0��1����
��ȵ�������鳤�ȡ�
���Ѷȡ�ξ
*/

#include <iostream>
#include <map>

int maxLength(int* arr, int len, int k) {

	if (len == 0) {
		return 0;
	}
	std::map<int, int> map;
	map.insert(std::pair<int, int>(0, -1));
	int length = 0;
	int sum = 0;
	for (int i = 0; i < len; i ++) {
		sum += arr[i];
		if (map.find(sum - k) != map.end()) {
			length = (i - map[sum - k]) > length ? (i - map[sum - k]) : length;
		}
		if (map.find(sum) == map.end()) {
			map.insert(std::pair<int, int>(sum, i));
		}
	}
	return length;
}

int main() {

	int arr[] = {1,2,3,3};

	std::cout << maxLength(arr, 4, 6) << std::endl;

	return 0;
}