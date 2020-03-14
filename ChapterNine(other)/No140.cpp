/*
【名称】设计有setAll功能的哈希表
【题目】哈希表常见的三个操作put,get,containsKey,而且这三个操作的时间复杂度
为O(1)。现在想加一个setAll功能，就是把所有记录的value都设成统一的值。请设计
并实现这种有setAll功能的哈希表，并且put，get,containKey和setAll四个操作的时间
复杂度都是O(1).
【难度】士
*/
#include <iostream>
#include <map>


template <typename V>
class MyValue {
public:
	MyValue() { time = 0; }
	MyValue(V value, long time):value(value),time(time) {}
	V getValue() { return value; }
	long getTime() { return time; }
	void setValue(V value, long time) { this->value = value; this->time = time; }
private:
	V value;
	long time;
};

template <typename K, typename V>
class MyHashMap {
public:
	MyHashMap() {
		time = 0;
	}
public:
	bool containsKey(K key) {
		return baseMap.find(key) != baseMap.end();
	}
	void put(K key, V value) {
		baseMap.insert(std::pair<K, MyValue<V> >(key, MyValue<V>(value, time++)));
	}
	void setAll(V value) {
		setall.setValue(value, time++);
	}
	V get(K key) {
		if (containsKey(key)) {
			if (baseMap[key].getTime() > setall.getTime()) {

				return baseMap[key].getValue();
			}
			else {
				return setall.getValue();
			}
		}
		else {
			return NULL;
		}
	}
private:
	std::map<K, MyValue<V> > baseMap;
	long time;
	MyValue<V> setall;
};


int main() {

	MyHashMap<double, int> map;
	map.put(1, 1);
	map.put(2, 2);
	map.put(3, 3);

	map.setAll(2);

	map.put(4, 4);

	std::cout << map.get(1) << std::endl;
	std::cout << map.get(2) << std::endl;
	std::cout << map.get(3) << std::endl;
	std::cout << map.get(4) << std::endl;

	return 0;
}