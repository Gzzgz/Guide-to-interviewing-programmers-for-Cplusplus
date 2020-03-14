/*
【名称】设计RandomPool结构
【题目】设计一种结构，在该结构中有如下三个功能
1.insert(key):将某个key加入到该结构，做到不重复加入；
2.delete(key):将原本在结构中的某个key移除；
3.getRandom():等概率随机返回结构中的任何一个key。
要求：时间复杂度O(1)
【难度】尉
*/
#include <iostream>
#include <map>
#include <ctime>
#include <random>
#include <string>


template <typename K>
class Pool{
public:

	Pool() {
		size = 0;
	}

	void insert(K key) {
		if (key_index_map.find(key) == key_index_map.end()) {
			key_index_map.insert(std::pair<K, int>(key, size));
			index_key_map.insert(std::pair<int, K>(size++, key));
		}
	}

	void deleteE(K key) {
		if (key_index_map.find(key) != key_index_map.end()) {
			int deleteIndex = key_index_map[key];
			int lastIndex = --size;
			K lastKey = index_key_map[lastIndex];
			key_index_map[lastKey] = deleteIndex;
			index_key_map[deleteIndex] = lastKey;
			key_index_map.erase(key);
			index_key_map.erase(lastIndex);
		}
	}

	K getRandom() {
		if (size == 0) {
			return NULL;
		}
		int randomIndex = std::rand() % size;
		return index_key_map[randomIndex];
	}

private:
	std::map<K, int> key_index_map;
	std::map<int, K> index_key_map;
	int size;

};


int main() {

	srand(time(NULL));

	Pool<std::string> pool;
	pool.insert("A");
	pool.insert("B");
	pool.insert("C");

	pool.deleteE("B");
    std::string res = pool.getRandom();

	std::cout<<res<<std::endl;
	return 0;
}