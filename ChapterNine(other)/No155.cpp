/*
【名称】设计一个没有扩容负担的堆结构
【题目】堆结构一般时使用固定长度的数组结构来实现。这样的实现存在扩容的负担，
比如不断向堆中增加元素，使得固定数组快耗尽时，就不得不申请一个更大的固定数组，
然后把原来数组中的对象复制到新的数组里完成堆的扩容，所以，如果扩容时堆中的
元素个数为N,那么扩容行为的时间复杂度O(N),请设计一种没有扩容负担的堆结构，即在
任何时刻有关堆的操作时间复杂度都不超过O(logN).
要求：1.没有扩容负担；2.可以生成小根堆，也可以生成大根堆；
3.包含getHead方法，返回当前堆顶的值；
4.包含getSize方法，返回当前堆的大小；
5.包含add(x)方法，返回堆中新加元素x，操作后依然是小根堆/大根堆；
6.包含popHead方法，即删除并返回堆顶的值，操作后依然是小根堆/大根堆；
7.堆节点数为N,各个方法时间复杂度为：
getHead:O(1)
getSize:O(1)
add:O(logN)
popHead:O(logN)
【难度】将
*/
#include <iostream>
#include <map>

template <typename K>
struct Node {
	K value;
	Node<K>* left;
	Node<K>* right;
	Node<K>* parent;
	Node(K data) {
		value = data;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

template <typename K>
class Comparator {
public:
	virtual K compare(K k1, K k2) { return k1 > k2 ? 1 : -1; };
};

template <typename K>
class MaxHeapComparator:public Comparator<K> {
public:
	K compare(K k1, K k2) {
		return k2 > k1 ? 1 : -1;
	}
};

template <typename K>
class MinHeapComparator :public Comparator<K> {
public:
	K compare(K k1, K k2) {
		return k2 < k1 ? 1 : -1;
	}
};


template <typename K>
class Heap {
public:
	Heap() {}
	Heap(Comparator<K>* compare) {
		head = nullptr;
		last = nullptr;
		size = 0;
		comp = compare;
	}

	K getHead() {
		return head == nullptr ? NULL : head->value;
	}

	long getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0 ? true : false;
	}

	void add(K value) {
		Node<K>* newNode = new Node<K>(value);
		if (size == 0) {
			head = newNode;
			last = newNode;
			size++;
			return;
		}
		Node<K>* node = last;
		Node<K>* parent = node->parent;

		while (parent != nullptr && node != parent->left) {
			node = parent;
			parent = node->parent;
		}
		Node<K>* nodeToAdd = nullptr;
		if (parent == nullptr) {
			nodeToAdd = mostLeft(head);
			nodeToAdd->left = newNode;
			newNode->parent = nodeToAdd;
		}
		else if (parent->right == nullptr) {
			parent->right = newNode;
			newNode->parent = parent;
		}
		else {
			nodeToAdd = mostLeft(parent->right);
			nodeToAdd->left = newNode;
			newNode->parent = nodeToAdd;
		}
		last = newNode;
		heapInsertModify();
		size++;
	}

	K popHead() {
		if (size == 0) {
			return NULL;
		}
		Node<K>* res = head;
		if (size == 1) {
			head = nullptr;
			last = nullptr;
			size--;
			return res->value;
		}
		Node<K>* oldLast = popLastAndSetPreviousLast();

		if (size == 1) {
			head = oldLast;
			last = oldLast;
			return res->value;
		}

		Node<K>* headLeft = res->left;
		Node<K>* headRight = res->right;
		oldLast->left = headLeft;
		if (headLeft != nullptr) {
			headLeft->parent = oldLast;
		}
		oldLast->right = headRight;
		if (headRight != nullptr) {
			headRight->parent = oldLast;
		}
		res->left = nullptr;
		res->right = nullptr;
		head = oldLast;
		heapify(oldLast);
		return res->value;
	}

	Node<K>* mostLeft(Node<K>* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

	Node<K>* mostRight(Node<K>* node) {
		while (node->right != nullptr) {
			node = node->right;
		}
		return node;
	}

	void heapInsertModify() {
		Node<K>* node = last;
		Node<K>* parent = node->parent;
		if (parent != nullptr && comp->compare(node->value, parent->value) < 0) {
			last = parent;
		}
		while (parent != nullptr && comp->compare(node->value, parent->value) < 0) {
			swapClosedTwoNodes(node, parent);
			parent = node->parent;
		}
		if (head->parent != nullptr) {
			head = head->parent;
		}
	}

	void heapify(Node<K>* node) {
		Node<K>* left = node->left;
		Node<K>* right = node->right;
		Node<K>* most = node;
		while (left != nullptr) {
			if (left != nullptr && comp->compare(left->value, most->value) < 0) {
				most = left;
			}
			if (right != nullptr && comp->compare(right->value, most->value) < 0) {
				most = right;
			}
			if (most != node) {
				swapClosedTwoNodes(most, node);
			}
			else {
				break;
			}
			left = node->left;
			right = node->right;
			most = node;
		}
		if (node->parent == last) {
			last = node;
		}
		while (node->parent != nullptr) {
			node = node->parent;
		}
		head = node;
	}

	void swapClosedTwoNodes(Node<K>* node, Node<K>* parent) {
		if (node == nullptr || parent == nullptr) {
			return;
		}
		Node<K>* parentParent = parent->parent;
		Node<K>* parentLeft = parent->left;
		Node<K>* parentRight = parent->right;
		Node<K>* nodeLeft = node->left;
		Node<K>* nodeRight = node->right;
		node->parent = parentParent;
		if (parentParent != nullptr) {
			if (parent == parentParent->left) {
				parentParent->left = node;
			}
			else {
				parentParent->right = node;
			}
		}
		parent->parent = node;
		if (nodeLeft != nullptr) {
			nodeLeft->parent = parent;
		}
		if (nodeRight != nullptr) {
			nodeRight->parent = parent;
		}
		if (node == parent->left) {
			node->left = parent;
			node->right = parentRight;
			if (parentRight != nullptr) {
				parentRight->parent = node;
			}
		}
		else {
			node->left = parentLeft;
			node->right = parent;
			if (parentLeft != nullptr) {
				parentLeft->parent = node;
			}
		}
		parent->left = nodeLeft;
		parent->right = nodeRight;
	}

	Node<K>* popLastAndSetPreviousLast() {
		Node<K>* node = last;
		Node<K>* parent = node->parent;
		while (parent != nullptr && node != parent->right) {
			node = parent;
			parent = node->parent;
		}
		if (parent == nullptr) {
			node = last;
			parent = node->parent;
			node->parent = nullptr;
			if (node == parent->left) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
			last = mostRight(head);
		}
		else {
			Node<K>* newLast = mostRight(parent->left);
			node = last;
			parent = node->parent;
			node->parent = nullptr;
			if (node == parent->left) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
			last = newLast;
		}
		size--;
		return node;
	}

private:
	Node<K>* head;
	Node<K>* last;
	long size;
	Comparator<K>* comp;
};