/*
【名称】遍历二叉树得神级方法
【题目】给定一棵二叉树的头节点head，完成二叉树的先序，中序，后序遍历。
如果二叉树的节点数为N，要求时间复杂度为O(N)，额外空间复杂度为O(1)
【难度】将
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

void morrisIn(Node* head) {
	if (head == nullptr) {
		return;
	}
	Node* cur1 = head;
	Node* cur2 = nullptr;
	while (cur1 != nullptr) {
		cur2 = cur1->left;
		if (cur2 != nullptr) {
			while (cur2->right != nullptr && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			if (cur2->right == nullptr) {
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = nullptr;
			}
		}
		std::cout << cur1->value << " ";
		cur1 = cur1->right;
	}
	std::cout << std::endl;
}

void morrisPre(Node* head) {
	if (head == nullptr) {
		return;
	}
	Node* cur1 = head;
	Node* cur2 = nullptr;
	while (cur1 != nullptr) {
		cur2 = cur1->left;
		if (cur2 != nullptr) {
			while (cur2->right != nullptr && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			if (cur2->right == nullptr) {
				cur2->right = cur1;
				std::cout << cur1->value << " ";
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = nullptr;
			}
		}
		else {
			std::cout << cur1->value << " ";
		}
		cur1 = cur1->right;
	}
	std::cout << std::endl;
}

Node* reverseEdge(Node* from) {
	Node* pre = nullptr;
	Node* next = nullptr;
	while (from != nullptr) {
		next = from->right;
		from->right = pre;
		pre = from;
		from = next;
	}
	return pre;
}

void printEdge(Node* head) {
	Node* tail = reverseEdge(head);
	Node* cur = tail;
	while (cur != nullptr) {
		std::cout << cur->value << " ";
		cur = cur->right;
	}
	reverseEdge(tail);
}

void morrisPos(Node* head) {
	if (head == nullptr) {
		return;
	}
	Node* cur1 = head;
	Node* cur2 = nullptr;
	while (cur1 != nullptr) {
		cur2 = cur1->left;
		if (cur2 != nullptr) {
			while (cur2->right != nullptr && cur2->right != cur1) {
				cur2 = cur2->right;
			}
			if (cur2->right == nullptr) {
				cur2->right = cur1;
				cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = nullptr;
				printEdge(cur1->left);
			}
		}
		cur1 = cur1->right;
	}
	printEdge(head);
	std::cout << std::endl;
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->right->right = new Node(5);

	//morrisIn(head);
	//morrisPre(head);
	morrisPos(head);

	return 0;
}