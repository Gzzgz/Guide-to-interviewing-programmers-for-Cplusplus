/*
�����ơ����������ҵ����ִ�������N/K����
����Ŀ������һ����������arr����ӡ���г��ִ�������һ����������û��������������ӡ��ʾ��Ϣ��
�����ס�����һ����������arr���ٸ���һ������K����ӡ���г��ִ�������N/K���������û��������������ӡ��ʾ��Ϣ��
ԭ����Ҫ��ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�ΪO(1)����������Ҫ��ʱ�临�Ӷ�ΪO(N*K)������ռ临�Ӷ�ΪO(K)��
���Ѷȡ�У
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