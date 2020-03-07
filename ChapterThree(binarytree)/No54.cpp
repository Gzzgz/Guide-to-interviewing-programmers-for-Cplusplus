/*
【名称】统计完全二叉树的节点数
【题目】给定一棵完全二叉树的头节点head，返回这棵树的节点个数
要求：如果完全二叉树的节点数为N，请实现时间复杂度低于O(N)的解法
【难度】尉
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

int mostLeftLevel(Node* node, int level) {
	while (node != nullptr) {
		level++;
		node = node->left;
	}
	return level - 1;
}

int bs(Node* node, int c, int h) {
	if (c == h) {
		return 1;
	}
	if (mostLeftLevel(node->right, c + 1) == h) {
		return (1 << (h - 1)) + bs(node->right, c + 1, h);
	}
	else {
		return (1 << (h - 1 - c)) + bs(node->left, c + 1, h);
	}
}

int nodeNum(Node* head) {
	if (head == nullptr) {
		return 0;
	}
	return bs(head, 1, mostLeftLevel(head, 1));
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);

	std::cout << nodeNum(head) << std::endl;

	return 0;
}