/*
�����ơ���ƿ��Ա���Ļ���ṹ
����Ŀ�����һ�ֻ���ṹ���ýṹ�ڹ���ʱȷ����С�������СΪK,�����������ܣ�
1.set(key,value)������¼(key, value)����ýṹ��
2.get(key):����key��Ӧ��valueֵ��
Ҫ��1.set��get������ʱ�临�Ӷ�O(1);
2.ĳ��key��set��get����һ����������Ϊ���key�ļ�¼�������ʹ�õģ�
3.������Ĵ�С����Kʱ���Ƴ������ʹ�õļ�¼����set��get���Զ�ġ�
���Ѷȡ�ξ
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