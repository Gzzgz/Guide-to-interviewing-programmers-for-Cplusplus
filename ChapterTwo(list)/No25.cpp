/*
【名称】将搜索二叉树转换成双向链表
【题目】对二叉树的节点来说，有本身的值域，有指向左孩子和右孩子的两个指针；对
双向链表的节点来说，有本身的值域，有指向上一个节点和下一个节点的指针。在结构
上，两种结构有相似性，现在有一棵搜素二叉树，请将其转为一个有序的双向链表。
【难度】尉
*/
#include <iostream>
#include <queue>


struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value) :value(value),left(nullptr), right(nullptr){}
};

void inOrderToQueue(Node* head, std::queue<Node*>& queue) {
	if (head == nullptr) {
		return;
	}
	inOrderToQueue(head->left, queue);
	queue.push(head);
	inOrderToQueue(head->right, queue);
}

Node* convert1(Node* head) {
	std::queue<Node*> queue;
	inOrderToQueue(head, queue);
	if (queue.empty()) {
		return head;
	}

	head = queue.front();
	queue.pop();
	Node* pre = head;
	pre->left = nullptr;
	Node* cur = nullptr;
	while (!queue.empty()) {
		cur = queue.front();
		queue.pop();
		pre->right = cur;
		cur->left = pre;
		pre = cur;
	}
	pre->right = nullptr;

	return head;
}

void showTree(Node* head) {

	if (head == nullptr) {
		return;
	}
	showTree(head->left);
	std::cout << head->value << std::endl;
	showTree(head->right);
}

void showList(Node* head) {

	if (head == nullptr) {
		return;
	}
	Node* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->value << std::endl;
		tmp = tmp->right;
	}
}

Node* process(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* leftE = process(head->left);
	Node* rightE = process(head->right);
	Node* leftS = leftE != nullptr ? leftE->right : nullptr;
	Node* rightS = rightE != nullptr ? rightE->right : nullptr;
	if (leftE != nullptr && rightE != nullptr) {
		leftE->right = head;
		head->left = leftE;
		head->right = rightS;
		rightS->left = head;
		rightE->right = leftS;
		return rightE;
	}
	else if (leftE != nullptr) {
		leftE->right = head;
		head->left = leftE;
		head->right = leftS;
		return head;
	}
	else if (rightE != nullptr) {
		head->right = rightS;
		rightS->left = head;
		rightE->right = head;
		return rightE;
	}
	else {
		head->right = head;
		return head;
	}
}

Node* convert2(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* last = process(head);
	head = last->right;
	last->right = nullptr;
	return head;
}

int main() {
	
	Node* head = new Node(6);
	head->left = new Node(4);
	head->right = new Node(7);
	head->left->left = new Node(2);
	head->left->right = new Node(5);
	head->left->left->left = new Node(1);
	head->left->left->right = new Node(3);
	head->right->right = new Node(9);
	head->right->right->left = new Node(8);

	head = convert2(head);
	showList(head);

	return 0;
}