/*
【名称】在数组中找到出现次数大于N/K的数
【题目】给定一个整型数组arr，打印其中出现次数大于一半的数，如果没有这样的数，打印提示信息。
【进阶】给定一个整型数组arr，再给定一个整数K，打印所有出现次数大于N/K的数，如果没有这样的数，打印提示信息。
原问题要求时间复杂度为O(N)，额外空间复杂度为O(1)。进阶问题要求时间复杂度为O(N*K)，额外空间复杂度为O(K)。
【难度】校
*/
#include <iostream>
#include <map>
#include <vector>

void printHalfMajor(int* arr, int len) {

	int cand = 0;
	int times = 0;
	for (int i = 0; i != len; i ++) {
		if (times == 0) {
			cand = arr[i];
			times = 1;
		}
		else if (arr[i] == cand) {
			times++;
		}
		else {
			times--;
		}
	}
	times = 0;
	for (int i = 0; i != len; i ++) {
		if (arr[i] == cand) {
			times++;
		}
	}
	if (times > len / 2) {
		std::cout << cand << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
}


std::map<int, int> getReals(int* arr, int len, std::map<int, int>& cands) {

	std::map<int, int> reals;
	for (int i = 0; i != len; i ++) {
		int curNum = arr[i];
		if (cands.find(curNum) != cands.end()) {
			if (reals.find(curNum) != reals.end()) {
				reals[curNum]++;
			}
			else {
				reals.insert(std::pair<int, int>(curNum, 1));
			}
		}
	}
	return reals;
}

void allCandsMinusOne(std::map<int, int>& map) {
	
	std::vector<int> removeList;
	std::map<int, int>::iterator iter;
	for (iter = map.begin(); iter != map.end(); iter++) {
		int key = iter->first;
		int value = iter->second;
		if (value == 1) {
			removeList.push_back(key);
		}
		else {
			map[key]--;
		}
		
	}
	for (int i = 0; i < removeList.size(); i ++) {
		map.erase(removeList[i]);
	}
}

void printKMajor(int* arr, int len, int k) {
	if (k < 2) {
		return;
	}
	std::map<int, int> cands;
	for (int i = 0; i < len; i ++) {
		if (cands.find(arr[i]) != cands.end()) {
			cands[arr[i]]++;
		}
		else {
			if (cands.size() == k - 1) {
				allCandsMinusOne(cands);
			}
			else {
				cands[arr[i]] = 1;
			}
		}
	}
	std::map<int, int> reals = getReals(arr, len, cands);
	std::map<int, int>::iterator iter;
	bool flag = false;
	for (iter = reals.begin(); iter != reals.end(); iter ++) {
		int key = iter->first;
		if (reals[key] > len / k) {
			flag = true;
			std::cout << key << " ";
		}
	}
	std::cout << (flag ? "" : "NO") << std::endl;
}

int main() {

	int arr[] = {1,2,3,4,5, 3,3,5,5,5};
	
	printHalfMajor(arr, 10);

	printKMajor(arr, 10, 3);

	return 0;
}