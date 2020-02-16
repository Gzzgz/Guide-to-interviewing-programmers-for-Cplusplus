/*
【名称】数组中的最长连续序列
【题目】给定无序数组arr，返回其中最长的连续序列的长度
【难度】尉
*/
#include <iostream>
#include <map>


int merge(std::map<int, int>& map, int less, int more) {
	int left = less - map[less] + 1;
	int right = more + map[more] - 1;
	int len = right - left + 1;
	map[left] = len;
	map[right] = len;
	return len;
}

int longestConsecutive(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int max = 1;
	std::map<int, int> map;
	
	for (int i = 0; i < len; i ++) {
		if (map.count(arr[i]) == 0) {
			map.insert(std::pair<int, int>(arr[i], 1));
		    
			if (map.count(arr[i] - 1) > 0) {
				int m = merge(map, arr[i] - 1, arr[i]);
				max = max > m ? max : m;
			}
			if (map.count(arr[i] + 1) > 0) {
				int m = merge(map, arr[i], arr[i] + 1);
				max = max > m ? max : m;
			}
		}
	}
	return max;
}

int main() {

	int arr[6] = {100, 4, 200, 1, 3, 2};

	std::cout << longestConsecutive(arr, 6) << std::endl;

	return 0;
}