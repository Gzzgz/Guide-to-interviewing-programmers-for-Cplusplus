/*
【名称】数组中两个字符串的最小距离
【题目】给定一个字符串数组strs，再给定两个字符串str1,str2，返回strs中
str1与str2的最小距离，如果str1或str2为null,或不再strs中， 返回-1。
例如：strs=['1', '3', '3', '3', '2', '3', '1'],str1="1",str2="2",返回2
【进阶题目】如果查询发生的次数有很多，如何把每次查询的时间复杂度降为O(1)
【难度】尉
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int minDistance(std::vector<std::string> strs, std::string str1, 
	std::string str2) {
	if (str1 == "" || str2 == "") {
		return -1;
	}
	if (str1 == str2) {
		return 0;
	}
	int last1 = -1;
	int last2 = -1;
	int min_value = INT_MAX;
	for (int i = 0; i != strs.size(); i ++) {
		if (strs[i] == str1) {
			min_value = std::min(min_value, last2 == -1 ? min_value : i - last2);
			last1 = i;
		}
		if (strs[i] == str2) {
			min_value = std::min(min_value, last1 == -1 ? min_value : i - last1);
			last2 = i;
		}
	}
	return min_value == INT_MAX ? -1 : min_value;
}


class Record {
public:
	Record() {};
	~Record() {};
	Record(std::vector<std::string> strArr) {
		std::map<std::string, int> indexMap;
		for (int i = 0; i != strArr.size(); i ++) {
			std::string curStr = strArr[i];
			update(indexMap, curStr, i);
			indexMap.insert(std::pair<std::string, int>(curStr, i));
		}
	};

public:
	int minDistance(std::string str1, std::string str2) {
		if (str1 == "" || str2 == "") {
			return -1;
		}
		if (str1 == str2) {
			return 0;
		}
		if (record_.find(str1) != record_.end() 
			&& (record_[str1].find(str2)) != record_[str1].end()) {
			return record_[str1][str2];
		}
		return -1;
	}

private:
	std::map<std::string, std::map<std::string, int>> record_;

private:
	void update(std::map<std::string, int>& indexMap, std::string str, int i) {
		
		if (record_.find(str) == record_.end()) {
			record_.insert(std::pair<std::string, std::map<std::string, int>>
				(str, std::map<std::string, int>()));
		}
		std::map<std::string, int>& strMap = record_[str];
		std::map<std::string, int>::iterator iter;
		iter = indexMap.begin();
		while (iter != indexMap.end()) {
			std::string key = iter->first;
			int index = iter->second;

			if (key != str) {
				std::map<std::string, int>& lastMap = record_[key];
				int curMin = i - index;
				if (strMap.find(key) != strMap.end()) {
					int preMin = strMap[key];
					if (curMin < preMin) {
						strMap.insert(std::pair<std::string, int>(key, curMin));
						//lastMap.insert(std::pair<std::string, int>(str, curMin));
					}
				}
				else {
					strMap.insert(std::pair<std::string, int>(key, curMin));
					//lastMap.insert(std::pair<std::string, int>(str, curMin));
				}
			}
			iter++;
		}
	}

};


int main() {

	std::vector<std::string> strs = {"1", "3", "3", "3", "2", "1"};
	std::string str1 = "1";
	std::string str2 = "2";

	std::cout << minDistance(strs, str1, str2) << std::endl;

	Record record(strs);
	std::cout << record.minDistance(str1, str2) << std::endl;

	return 0;
}