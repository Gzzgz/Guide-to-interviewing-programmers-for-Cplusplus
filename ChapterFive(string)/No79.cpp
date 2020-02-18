/*
�����ơ��ж��ַ��������Ƿ����е��ַ���ֻ���ֹ�һ��
����Ŀ������һ���ַ���������chas[],�ж�chas���Ƿ����е��ַ���ֻ���ֹ�
һ�Σ���������²�ͬ������Ҫ��ʵ������������
Ҫ��
1.ʵ��ʱ�临�Ӷ�ΪO(N)�ķ�����
2.�ڱ�֤����ռ临�Ӷ�ΪO(1)��ǰ���£���ʵ��ʱ�临�ӶȾ����͵ķ�����
���Ѷȡ�
Ҫ��1��ʿ
Ҫ��2��ξ
*/
#include <iostream>
#include <string>

bool isUnique1(std::string str) {
	if (str == "") {
		return true;
	}
	bool map[256];
	for (int i = 0; i < 256; i ++) {
		map[i] = false;
	}
	for (int i = 0; i < str.length(); i ++) {
		if (map[str[i]]) {
			return false;
		}
		map[str[i]] = true;
	}
	return true;
}

void swap(std::string& str, int index1, int index2) {

	char tmp = str[index1];
	str[index1] = str[index2];
	str[index2] = tmp;
}

void heapify(std::string& str, int i, int size) {

	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;

	while (left < size) {
		if (str[left] > str[i]) {
			largest = left;
		}
		if (right < size && str[right] > str[largest]){
			largest = right;
		}
		if (largest != i) {
			swap(str, largest, i);
		}
		else {
			break;
		}
		i = largest;
		left = i * 2 + 1;
		right = i * 2 + 2;
	}
}

void heapInsert(std::string& str, int i) {

	int parent = 0;
	while (i != 0) {
		parent = (i - 1) / 2;
		if (str[parent] < str[i]) {
			swap(str, parent, i);
			i = parent;
		}
		else {
			break;
		}
	}
}

void heapSort(std::string& str) {

	for (int i = 0; i < str.length(); i ++) {
		heapInsert(str, i);
	}
	for (int i = str.length() - 1; i > 0; i --) {
		swap(str, 0, i);
		heapify(str, 0, i);
	}
}

bool isUnique2(std::string str) {

	if (str == "") {
		return false;
	}
	heapSort(str);

	for (int i = 1; i < str.length(); i ++) {

		if (str[i] == str[i - 1]) {
			return false;
		}
	}
	return true;
}



int main() {

	std::string str = "abcc";

	std::cout << isUnique2(str) << std::endl;


	return 0;
}