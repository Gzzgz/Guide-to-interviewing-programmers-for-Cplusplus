/*
【名称】判断t1树是否包含t2树全部的拓扑结构
【题目】给定彼此独立的两棵树头节点分别为t1,t2，判断树t1是否包含t2树全部的拓扑结构
【难度】士
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value), left(nullptr), right(nullptr){}
};

bool check(Node* h, Node* t2) {
	if (t2 == nullptr) {
		return true;
	}
	if (h == nullptr || h->value != t2->value) {
		return false;
	}
	return check(h->left, t2->left) && check(h->right, t2->right);
}

bool contains(Node* t1, Node* t2) {
	return check(t1, t2) || contains(t1->left, t2) || contains(t2->right, t2);
}

int main() {

	Node* t1 = new Node(1);
	t1->left = new Node(2);
	t1->right = new Node(3);
	t1->left->left = new Node(4);
	t1->left->right = new Node(5);
	t1->right->left = new Node(6);
	t1->right->right = new Node(7);
	t1->left->left->left = new Node(8);
	t1->left->left->right = new Node(9);
	t1->left->right->left = new Node(10);

	Node* t2 = new Node(2);
	t2->left = new Node(4);
	t2->left->left = new Node(8);
	t2->right = new Node(5);

	Node* t3 = new Node(4);
	t3->left = new Node(8);
	t3->right = new Node(9);

	std::cout <<contains(t1, t3) << std::endl;

	return 0;
}