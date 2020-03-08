/*
�����ơ��ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ�
����Ŀ��������һ���µĶ������ڵ��������£�
class Node{
public:
    int value;
	Node left;
	Node right;
	Node parent;
};
�ýṹ����ͨ�������ڵ�ṹ����һ��ָ�򸸽ڵ��parentָ�롣����
��һ��Node���͵Ľڵ���ɵĶ�����������ÿ���ڵ��parentָ�붼��ȷ
��ָ���Լ��ĸ��ڵ㣬ͷ�ڵ��parentָ��null��ֻ��һ���ڶ�������
��ĳ���ڵ�node,��ʵ�ַ���node�ĺ�̽ڵ�ĺ������ڶ��������������
�������У�node����һ���ڵ����node�ĺ�̽ڵ㡣
���Ѷȡ�ξ
*/
#include <iostream>

struct Node{
	int value;
	Node* left;
	Node* right;
	Node* parent;
	Node(int value):value(value),left(nullptr),right(nullptr),parent(nullptr) {}
};

Node* getLeftMost(Node* node) {
	if (node == nullptr) {
		return node;
	}
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

Node* getNextNode(Node* node) {
	if (node == nullptr) {
		return node;
	}
	if (node->right != nullptr) {
		return getLeftMost(node->right);
	}
	else {
		Node * parent = node->parent;
		while (parent != nullptr && parent->left != node) {
			node = parent;
			parent = node->parent;
		}
		return parent;
	}
}

int main() {

	Node* head = new Node(6);
	head->left = new Node(3);
	head->left->parent = head;
	head->right = new Node(9);
	head->right->parent = head;
	head->right->left = new Node(8);
	head->right->left->parent = head->right;
	head->right->right = new Node(10);
	head->right->right->parent = head->right;
	head->right->left->left = new Node(7);
	head->right->left->left->parent = head->right->left;
	head->left->left = new Node(1);
	head->left->left->parent = head->left;
	head->left->right = new Node(4);
	head->left->right->parent = head->left;
	head->left->right->right = new Node(5);
	head->left->right->right->parent = head->left->right;
	head->left->left->right = new Node(2);
	head->left->left->right->parent = head->left->left;

	head = getNextNode(head->right);
	std::cout << head->value << std::endl;

	return 0;
}