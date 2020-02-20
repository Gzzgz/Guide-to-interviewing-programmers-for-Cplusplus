/*
【名称】打印N个数组整体最大的TopK
【题目】有N个长度不一的数组，所有的数组都是有序的，请从大到小打印这N个数组
整体最大的前K个数。
要求：1.如果所有数组的元素个数小于K,则从大到校打印所有的数
2.要求时间复杂度为O(KlogN)
【难度】尉
*/

#include <iostream>


class HeapNode{

public:
	int value;
	int arrNum;
	int index;

	HeapNode() {};

	HeapNode(int _value, int _arrNum, int _index) {
		value = _value;
		arrNum = _arrNum;
		index = _index;
	}
};


void swap(HeapNode* heap, int index1, int index2) {
	HeapNode tmp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tmp;
}

void heapify(HeapNode* heap, int index, int heapSize) {

	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largest = index;
	while (left < heapSize) {
		if (heap[left].value > heap[index].value) {
			largest = left;
		}
		if (right < heapSize && heap[right].value > heap[largest].value) {
			largest = right;
		}
		if (largest != index) {
			swap(heap, largest, index);
		}
		else {
			break;
		}
		index = largest;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}

void heapInsert(HeapNode* heap, int index) {
	
	while (index != 0) {

		int parent = (index - 1) / 2;
		if (heap[parent].value < heap[index].value) {
			swap(heap, parent, index);
			index = parent;
		}
		else {
			break;
		}
	}
}

void printTopK(int** matrix, int topK, int rows, int* cols) {

	int heapSize = rows;
	HeapNode* heap = new HeapNode[heapSize];
	for (int i = 0; i != heapSize; i ++) {
		int index = cols[i] - 1;
		heap[i].value = matrix[i][index];
		heap[i].arrNum = i;
		heap[i].index = index;
		heapInsert(heap, i);
	}
	std::cout << "TOP " << topK << " : ";
	for (int i = 0; i != topK; i ++) {
		if (heapSize == 0) {
			break;
		}
		std::cout << heap[0].value << " ";
		if (heap[0].index != 0) {
			heap[0].value = matrix[heap[0].arrNum][--heap[0].index];
		}
		else {
			swap(heap, 0, --heapSize);
		}
		heapify(heap, 0, heapSize);
	}
}

int main() {

	int arr[] = {219, 405, 538, 845, 971,   148, 558,   52, 99, 348, 691 };
	int cols[] = {5, 2, 4};
	int count = 0;
	int** m = new int*[3];
	for (int i = 0; i < 3; i ++) {
		m[i] = new int[cols[i]];
		for (int j = 0; j < cols[i]; j ++) {
			m[i][j] = arr[count++];
		}
	}

	printTopK(m, 5, 3, cols);

	return 0;
}