/*
【名称】二叉树的按层打印与ZigZag 打印
【题目】给定一棵二叉树的头节点head，分别实现按层打印和ZigZag打印二叉树的函数
【难度】尉
*/
#include <iostream>
#include <queue>
#include <deque>

struct  Node{
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

void printByLevel(Node* head) {
	if (head == nullptr) {
		return;
	}
	std::queue<Node*>queue;
	int level = 1;
	Node* last = head;
	Node* nLast = nullptr;
	queue.push(head);
	std::cout << "level " << level++ << " : ";
	while (!queue.empty()) {
		head = queue.front();
		queue.pop();
		std::cout << head->value << " ";
		if (head->left != nullptr) {
			queue.push(head->left);
			nLast = head->left;
		}
		if (head->right != nullptr) {
			queue.push(head->right);
			nLast = head->right;
		}
		if (head == last && !queue.empty()) {
			std::cout << "\nlevel " << level++ << " : ";
			last = nLast;
		}
	}
	std::cout << std::endl;
}

void pringLevelAndOrientation(int level, bool lr) {
	std::cout << "level " << level << " from ";
	std::string str = lr ? "left to right: " : "right to left: ";
	std::cout << str.c_str();
}

void printByZigZag(Node* head) {
	if (head == nullptr) {
		return;
	}
	std::deque<Node*> dq;
	int level = 1;
	bool lr = true;
	Node* last = head;
	Node* nLast = nullptr;
	dq.push_front(head);
	pringLevelAndOrientation(level++, lr);
	while (!dq.empty()) {
		if (lr) {
			head = dq.front();
			dq.pop_front();
			if (head->left != nullptr) {
				nLast = nLast == nullptr ? head->left : nLast;
				dq.push_back(head->left);
			}
			if (head->right != nullptr) {
				nLast = nLast == nullptr ? head->right : nLast;
				dq.push_back(head->right);
			}
		}
		else {
			head = dq.back();
			dq.pop_back();
			if (head->right != nullptr) {
				nLast = nLast == nullptr ? head->right : nLast;
				dq.push_front(head->right);
			}
			if (head->left != nullptr) {
				nLast = nLast == nullptr ? head->left : nLast;
				dq.push_front(head->left);
			}
		}
		std::cout << head->value << " ";
		if (head == last && !dq.empty()) {
			lr = !lr;
			last = nLast;
			nLast = nullptr;
		    std::cout << std::endl;
			pringLevelAndOrientation(level++, lr);
		}
	}
	std::cout << std::endl;
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->right->right = new Node(5);

	printByLevel(head);

	printByZigZag(head);

	return 0;
}