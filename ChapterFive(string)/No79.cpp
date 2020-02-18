/*
【名称】判断字符数组中是否所有的字符都只出现过一次
【题目】给定一个字符类型数组chas[],判断chas中是否所有的字符都只出现过
一次，请根据以下不同的两种要求实现两个函数。
要求：
1.实现时间复杂度为O(N)的方法；
2.在保证额外空间复杂度为O(1)的前提下，请实现时间复杂度尽量低的方法。
【难度】
要求1：士
要求2：尉
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