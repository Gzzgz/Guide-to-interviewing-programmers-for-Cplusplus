/*
【名称】两个有序数组间相加和的TOP K问题
【题目】给定两个有序数组arr1,arr2,再给定一个整数k,返回来自arr1,arr2的两个数
相加和最大的前k个，两个数必须分别来自两个数组。
arr1=[1,2,3,,4,5],arr2=[3,5,7,9,11],k=4，返回[16,15,14,14]
要求：时间复杂度O(klogk)
【难度】尉
*/
#include <iostream>
#include <string>
#include <set>

struct HeapNode {
	int row;
	int col;
	int value;
	HeapNode(){}
	HeapNode(int row, int col, int value) :row(row),
		col(col), value(value) {}
};

void addPositionToSet(int row, int col, std::set<std::string>& set) {
	set.insert(std::to_string(row) + "_" + std::to_string(col));
}

bool isContains(int row, int col, std::set<std::string>& set) {
	return set.find(std::to_string(row) + "_" + std::to_string(col)) != set.end();
}

void swap(HeapNode* heap, int index1, int index2) {
	HeapNode tmp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tmp;
}

void heapInsert(HeapNode* heap, int index, int row, int col,
	int value) {
	heap[index] = HeapNode(row, col, value);
	int parent = (index - 1) / 2;
	while (index != 0) {
		if (heap[index].value > heap[parent].value) {
			swap(heap, parent, index);
			index = parent;
			parent = (index - 1) / 2;
		}
		else {
			break;
		}
	}
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

HeapNode popHead(HeapNode* heap, int heapSize) {
	HeapNode res = heap[0];
	swap(heap, 0, heapSize - 1);
	heap[--heapSize] = HeapNode(-1, -1, -1);
	heapify(heap, 0, heapSize);
	return res;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int* topKSum(int* a1, int len1, int* a2, int len2, int topk) {
	if (a1 == nullptr || a2 == nullptr || len1 == 0 ||len2 == 0
		|| topk < 1) {
		return nullptr;
	}
	topk = min(topk, len1 * len2);
	HeapNode* heap = new HeapNode[topk + 1];
	int heapSize = 0;
	int headR = len1 - 1;
	int headC = len2 - 1;
	int upr = -1;
	int upc = -1;
	int leftr = -1;
	int leftc = -1;
	heapInsert(heap, heapSize++, headR, headC, a1[headR] + a2[headC]);
	
	std::set<std::string>set;
	int* res = new int[topk];
	memset(res, 0, sizeof(int) * topk);
	int resIndex = 0;

	while (resIndex != topk) {
		HeapNode head = popHead(heap, heapSize--);
		res[resIndex++] = head.value;
		headR = head.row;
		headC = head.col;
		upr = headR - 1;
		upc = headC;
		if (headR != 0 && !isContains(upr, upc, set)) {
			heapInsert(heap, heapSize++, upr, upc, a1[upr] + a2[upc]);
			addPositionToSet(upr, upc, set);
		}
		leftr = headR;
		leftc = headC - 1;
		if (headC != 0 && !isContains(leftr, leftc, set)) {
			heapInsert(heap, heapSize++, leftr, leftc, a1[leftr] + a2[leftc]);
			addPositionToSet(leftr, leftc, set);
		}
	}
	return res;
}

int main() {

	int arr1[] = {1,2,3,4,5};
	int arr2[] = {3,5,7,9,11};

	int* res = topKSum(arr1, 5, arr2, 5, 4);
	for (int i = 0; i < 4; i ++) {
	std::cout << res[i] << std::endl;
	}

	return 0;
}