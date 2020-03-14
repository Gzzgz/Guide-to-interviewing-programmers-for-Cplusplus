/*
【名称】设计可以变更的缓存结构
【题目】设计一种缓存结构，该结构在构造时确定大小，假设大小为K,并有两个功能：
1.set(key,value)：将记录(key, value)插入该结构；
2.get(key):返回key对应的value值。
要求：1.set和get方法的时间复杂度O(1);
2.某个key的set或get操作一旦发生，认为这个key的记录成了最经常使用的；
3.当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
【难度】尉
*/
#include <iostream>
#include <map>
#include <deque>


template <typename V>
struct Node {
	V value;
	Node<V>* last;
	Node<V>* next;
	Node(V value):value(value) {}
};

template <typename V>
class NodeDoubleList{
public:
	NodeDoubleList() {
		head = nullptr;
		tail = nullptr;
	}

	void addNode(Node<V>* newNode) {
		if (newNode == nullptr) {
			return;
		}
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->last = tail;
			tail = newNode;
		}
	}

	void moveNodeToTail(Node<V>* node) {
		if (tail == node) {
			return;
		}
		if (head == node) {
			head = node->next;
			head->last = nullptr;
		}
		else {
			node->last->next = node->next;
			node->next->last = node->last;
		}
		node->last = tail;
		node->next = nullptr;
		tail->next = node;
		tail = node;
	}

	Node<V>* removeHead() {
		if (head == nullptr) {
			return nullptr;
		}
		Node<V>* res = head;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = res->next;
			res->next = nullptr;
			head->last = nullptr;
		}
		return res;
	}

public:
	Node<V>* head;
	Node<V>* tail;
};

template <typename K, typename V>
class Cache {
public:
	Cache(int capacity) {
		if (capacity < 1) {
			std::cout << "#" << std::endl;
		}
		this->capacity = capacity;
	}

	V get(K key) {
		if (kn_map.find(key) != kn_map.end()) {
			Node<V>* res = kn_map[key];
			nodelist.moveNodeToTail(res);
			return res->value;
		}
		return NULL;
	}

	void set(K key, V value) {
		if (kn_map.find(key) != kn_map.end()) {
			Node<V>* node = kn_map[key];
			node->value = value;
			nodelist.moveNodeToTail(node);
		}
		else {
			Node<V>* newNode = new Node<V>(value);
			kn_map.insert(std::pair<K, Node<V>* >(key, newNode));
			nk_map.insert(std::pair<Node<V>*, K>(newNode, key));
			nodelist.addNode(newNode);
			if (kn_map.size() == capacity + 1) {
				removeMostUnusedCache();
			}
		}
	}

	void removeMostUnusedCache() {
		Node<V>* removeNode = nodelist.removeHead();
		K removeKey = nk_map[removeNode];
		nk_map.erase(removeNode);
		kn_map.erase(removeKey);
	}

	void printCache() {
		Node<V>* tmp = nodelist.head;
		int i = 0;
		while (i ++ < capacity) {
			std::cout << tmp->value << std::endl;
			tmp = tmp->next;
		}
	}

private:
	std::map<K, Node<V>*> kn_map;
	std::map<Node<V>*, K> nk_map;
	NodeDoubleList<V> nodelist;
	int capacity;
};

int main() {

	Cache<std::string, int> cache(3);

	cache.set("A", 1);
	cache.set("B", 2);
	cache.set("C", 3);
	cache.get("A");
	cache.set("D", 4);

	cache.printCache();

	return 0;
}