/*
【名称】分糖果问题
【题目】一群孩子做游戏，现在请你根据游戏得分来发糖果，要求如下：
1.每个孩子不管得分多少，起码分到1个糖果；
2.任意两个相邻的孩子之间，得分较多的孩子必须拿多一些糖果；
给定一个数组arr代表得分数组，请返回最少需要多少糖果。
arr=[1,2,2],糖果分配[1,2,1],返回4
【进阶题目】
3.任意两个相邻孩子之间如果得分一样，糖果数必须相同；
arr=[1,2,2],糖果分配[1,2,2]，返回5.
要求：时间复杂度O(N),空间复杂度O(1).
【难度】校
*/
#include <iostream>

int rightCands(int left, int right) {
	int n = right - left + 1;
	return n + n * (n - 1) / 2;
}

int nextMinIndex1(int* arr, int len, int start) {
	for (int i = start; i != len - 1; i ++) {
		if (arr[i] <= arr[i + 1]) {
			return i;
		}
	}
	return len - 1;
}

int candy1(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 0;
	}
	int index = nextMinIndex1(arr, len, 0);
	int res = rightCands(0, index++);
	int lbase = 1;
	int next = 0;
	int rcands = 0;
	int rbase = 0;
	while (index != len) {
		if (arr[index] > arr[index - 1]) {
			res += ++lbase;
			index++;
		}
		else if (arr[index] < arr[index - 1]) {
			next = nextMinIndex1(arr, len, index - 1);//index
			rcands = rightCands(index - 1, next++);
			rbase = next - index + 1;
			res += rcands + (rbase > lbase ? -lbase : -rbase);
			lbase = 1;
			index = next;
		}
		else {
			res += 1;
			lbase = 1;
			index++;
		}
	}
	return res;
}

int* rightCandsAndBase(int* arr, int left, int right) {
	int base = 1;
	int cands = 1;
	for (int i = right - 1; i >= left; i --) {
		if(arr[i] == arr[i + 1]){
			cands += base;
		}
		else {
			cands += ++base;
		}
	}
	return new int[2] {cands, base};
}

int nextMinIndex2(int* arr, int len, int start) {
	for (int i = start; i != len - 1; i ++) {
		if (arr[i] < arr[i + 1]) {
			return i;
		}
	}
	return len - 1;
}

int candy2(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 0;
	}
	int index = nextMinIndex2(arr, len, 0);
	int* data = rightCandsAndBase(arr, 0, index++);
	int res = data[0];
	int lbase = 1;
	int same = 1;
	int next = 0;
	while (index != len) {
		if (arr[index] > arr[index - 1]) {
			res += ++lbase;
			same = 1;
			index++;
		}
		else if (arr[index] < arr[index - 1]) {
			next = nextMinIndex2(arr, len, index - 1);// index
			data = rightCandsAndBase(arr, index - 1, next ++);
			if (data[1] <= lbase) {
				res += data[0] - data[1];
			}
			else {
				res += -lbase * same + data[0] - data[1] + data[1] * same;
			}
			index = next;
			lbase = 1;
			same = 1;
		}
		else {
			res += lbase;
			same++;
			index++;
		}
	}
	return res;
}

int main() {

	int arr[] = {1,4,5,9,3,2};
	std::cout << candy2(arr, 6) << std::endl;

	return 0;
}