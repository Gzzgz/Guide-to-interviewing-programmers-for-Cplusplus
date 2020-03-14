/*
�����ơ����һ��û�����ݸ����Ķѽṹ
����Ŀ���ѽṹһ��ʱʹ�ù̶����ȵ�����ṹ��ʵ�֡�������ʵ�ִ������ݵĸ�����
���粻�����������Ԫ�أ�ʹ�ù̶������ľ�ʱ���Ͳ��ò�����һ������Ĺ̶����飬
Ȼ���ԭ�������еĶ����Ƶ��µ���������ɶѵ����ݣ����ԣ��������ʱ���е�
Ԫ�ظ���ΪN,��ô������Ϊ��ʱ�临�Ӷ�O(N),�����һ��û�����ݸ����Ķѽṹ������
�κ�ʱ���йضѵĲ���ʱ�临�Ӷȶ�������O(logN).
Ҫ��1.û�����ݸ�����2.��������С���ѣ�Ҳ�������ɴ���ѣ�
3.����getHead���������ص�ǰ�Ѷ���ֵ��
4.����getSize���������ص�ǰ�ѵĴ�С��
5.����add(x)���������ض����¼�Ԫ��x����������Ȼ��С����/����ѣ�
6.����popHead��������ɾ�������ضѶ���ֵ����������Ȼ��С����/����ѣ�
7.�ѽڵ���ΪN,��������ʱ�临�Ӷ�Ϊ��
getHead:O(1)
getSize:O(1)
add:O(logN)
popHead:O(logN)
���Ѷȡ���
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