/*
【名称】找到无序数组中最小的k个数
【题目】给定一个无序的整型数组arr，找到其中最小的k个数。
要求：如果数组arr的长度为N,排序后自然可以得到最小的k个数，此时时间复杂
度与排序的时间复杂度相同，均为O(NlogN)。本题要求读者实现时间复杂度为O(Nlogk)
和O(N)的方法。
【难度】O(Nlogk): 尉， O(N): 将
*/

#include <iostream>
#include <vector>

int medianOfMedians(int* arr, int begin, int end);

void swap(int* arr, int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void heapify(int* arr, int len, int index, int heapSize) {
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int largest = index;
	while (left < heapSize) {
		if (arr[left] > arr[index]) {
			largest = left;
		}
		if (right < heapSize && arr[right] > arr[largest]) {
			largest = right;
		}
		if (largest != index) {
			swap(arr, largest, index);
		}
		else {
			break;
		}
		index = largest;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}

void heapInsert(int* arr, int len, int value, int index) {
	arr[index] = value;
	while (index != 0) {
		int parent = (index - 1) / 2;
		if (arr[parent] < arr[index]) {
			swap(arr, parent, index);
			index = parent;
		}
		else {
			break;
		}
	}
}

std::vector<int> getMinKNumsByHeap(int* arr, int len, int k) {
	
	std::vector<int> kheap(k);
	if (k < 1 || k > len) {
		return kheap;
	}

	for (int i = 0; i < k; i ++) {
		heapInsert(kheap.data(), k, arr[i], i);
	}
	for (int i = k; i != len; i ++) {
		if (arr[i] < kheap[0]) {
			kheap[0] = arr[i];
			heapify(kheap.data(), k, 0, k);
		}
	}
	return kheap;
}


void insertionSort(int* arr, int begin, int end) {
	for (int i = begin + 1; i != end + 1; i ++) {
		for (int j = i; j != begin; j --) {
			if (arr[j - 1] > arr[j]) {
				swap(arr, j - 1, j);
			}
			else {
				break;
			}
		}
	}
}

int getMedian(int* arr, int begin, int end) {
	insertionSort(arr, begin, end);
	int sum = end + begin;
	int mid = (sum / 2) + (sum % 2);
	return arr[mid];
}

std::vector<int> partition(int* arr, int begin, int end, int pivotValue) {
	int small = begin - 1;
	int cur = begin;
	int big = end + 1;
	while (cur != big) {
		if (arr[cur] < pivotValue) {
			swap(arr, ++small, cur++);
		}
		else if (arr[cur] > pivotValue) {
			swap(arr, cur, -- big);
		}
		else {
			cur++;
		}
	}
	std::vector<int> range(2);
	range[0] = small + 1;
	range[1] = big - 1;
	return range;
}

std::vector<int> copyArray(int* arr, int len) {
	std::vector<int> res(len);
	for (int i = 0; i != res.size(); i ++) {
		res[i] = arr[i];
	}
	return res;
}

int select(int* arr, int begin, int end, int i) {
	if (begin == end) {
		return arr[begin];
	}
	int pivot = medianOfMedians(arr, begin, end);
	std::vector<int> pivotRange = partition(arr, begin, end, pivot);
	if (i >= pivotRange[0] && i <= pivotRange[1]) {
		return arr[i];
	}
	else if (i < pivotRange[0]) {
		return select(arr, begin, pivotRange[0] - 1, i);
	}
	else {
		return select(arr, pivotRange[1] + 1, end, i);
	}

}

int medianOfMedians(int* arr, int begin, int end) {
	int num = end - begin + 1;
	int offset = num % 5 == 0 ? 0 : 1;
	std::vector<int> marr(num / 5 + offset, 0);
	for (int i = 0; i < num / 5 + offset; i ++) {
		int beginI = begin + i * 5;
		int endI = beginI + 4;
		marr[i] = getMedian(arr, beginI, end < endI ? end : endI);
	}
	return select(marr.data(), 0, marr.size() - 1, marr.size() / 2);
}

int getMinKthByBFPRT(int* arr, int len, int k) {
	std::vector<int> copyarr = copyArray(arr, len);
	return select(copyarr.data(), 0, copyarr.size() - 1, k - 1);
}

std::vector<int> getMinKNumsByBFPRT(int* arr, int len, int k) {
	std::vector<int> res(len);
	for (int i = 0; i < len; i ++) {
		res[i] = arr[i];
	}
	if (k < 1 || k > len) {
		return res;
	}
	int minKth = getMinKthByBFPRT(arr, len, k);
	res.clear();
	res.resize(k, 0);
	int index = 0;
	for (int i = 0; i != len; i ++) {
		if (arr[i] < minKth) {
			res[index++] = arr[i];
		}
	}
	for (; index != res.size(); index ++) {
		res[index] = minKth;
	}
	return res;
}

int main() {

	int arr[] = {6,5,4,3, 3,2,1};
	int top = 3;

	//std::vector<int> res = getMinKNumsByHeap(arr, 7, top);

	std::vector<int> res = getMinKNumsByBFPRT(arr, 7, top);

	for (int i = 0; i < top; i ++) {
		std::cout << res[i] << std::endl;
	}

	return 0;
}