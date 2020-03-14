/*
�����ơ����RandomPool�ṹ
����Ŀ�����һ�ֽṹ���ڸýṹ����������������
1.insert(key):��ĳ��key���뵽�ýṹ���������ظ����룻
2.delete(key):��ԭ���ڽṹ�е�ĳ��key�Ƴ���
3.getRandom():�ȸ���������ؽṹ�е��κ�һ��key��
Ҫ��ʱ�临�Ӷ�O(1)
���Ѷȡ�ξ
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