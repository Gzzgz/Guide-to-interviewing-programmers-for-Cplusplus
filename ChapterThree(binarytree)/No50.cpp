/*
【名称】二叉树节点间的最大距离问题
【题目】从二叉树的节点A出发，可以向上或向下走，但沿途的节点只能经过一次，
当到达节点B时，路径上的节点数叫作A到B的距离。给定一棵二叉树的头节点head,
求整棵树上节点间的最大距离。
要求：如果二叉树的节点树为N,时间复杂度要求为O(N)
【难度】尉
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

int posOrder(Node* head, int& record) {
	if (head == nullptr) {
		record = 0;
		return 0;
	}
	int lmax = posOrder(head->left, record);
	int maxfromleft = record;
	int rmax = posOrder(head->right, record);
	int maxfromright = record;
	int curmax = maxfromleft + maxfromright + 1;
	record = maxfromleft > maxfromright ? maxfromleft + 1 : maxfromright + 1;
	int tmp = lmax > rmax ? lmax : rmax;
	return tmp > curmax ? tmp : curmax;
}


int maxDistance(Node* head) {
	int record = 1;
	return posOrder(head, record);
}

int main() {
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);

	std::cout << maxDistance(head) << std::endl;

	return 0;
}