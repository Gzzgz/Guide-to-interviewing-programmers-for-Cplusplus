/*
【名称】路径数组变为统计数组
【题目】给定一个路径数组paths,表示一张图。paths[i]==j，代表城市i连向城市j，
如果paths[i]==i,则表示i城市是首都，一张图里只会有一个首都且图中除首都都指向
自己之外不会有环。统计数组为nums=[1,1,3,2,3,0,0,0,0,0],nums[i]==j代表距离为i
的城市有j座。要求实现一个void类型的函数，输入一个路径数组paths,直接在原数组
上调整，使之变为nums数组，即paths=[9,1,4,9,0,4,8,9,0,1]经过这个函数处理后变成
[1,1,3,2,3,0,0,0,0,0]
要求：paths长度N,时间复杂度O(N),空间复杂度O(1)
【难度】校
*/
#include <iostream>

void pathsToDistances(int* paths, int len) {
	int cap = 0;
	for (int i = 0; i < len; i ++) {
		if (paths[i] == i) {
			cap = i;
		}
		else if (paths[i] > -1) {
			int curI = paths[i];
			paths[i] = -1;
			int preI = i;
			while (paths[curI] != curI) {
				if (paths[curI] > -1) {
					int nextI = paths[curI];
					paths[curI] = preI;
					preI = curI;
					curI = nextI;
				}
				else {
					break;
				}
			}
			int value = paths[curI] == curI ? 0 : paths[curI];
			while (paths[preI] != -1) {
				int lastPreI = paths[preI];
				paths[preI] = --value;
				//curI = preI;
				preI = lastPreI;
			}
			paths[preI] = --value;
		}
	}
	paths[cap] = 0;
}

void distanceToNums(int* disArr, int len) {
	for (int i = 0; i < len; i ++) {
		int index = disArr[i];
		if (index < 0) {
			disArr[i] = 0;
			while (true) {
				index -= 2 * index;
				if (disArr[index] > -1) {
					disArr[index]++;
					break;
				}
				else {
					int nextIndex = disArr[index];
					disArr[index] = 1;
					index = nextIndex;
				}
			}
		}
	}
	disArr[0] = 1;
}

void pathsToNums(int* paths, int len) {
	if (paths == nullptr || len == 0) {
		return;
	}
	pathsToDistances(paths, len);
	distanceToNums(paths, len);
}

int main() {

	int arr[] = {9,1,4,9,0,4,8,9,0,1};
	pathsToNums(arr, 10);
	for (int i = 0; i < 10; i ++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}