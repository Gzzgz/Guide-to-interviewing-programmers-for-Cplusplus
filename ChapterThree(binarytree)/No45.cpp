/*
【名称】判断一棵二叉树是否为搜索二叉树和完全二叉树
【题目】给定一个二叉树的头节点head，已知其中没有重复值的节点，
实现两个函数分别判断这棵二叉树是否是搜素二叉树和完全二叉树
【难度】士
*/
#include <iostream>
#include <queue>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

bool isbst(Node* head) {
	if (head == nullptr) {
		return true;
	}
	bool res = true;
	Node* pre = nullptr;
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
		if (pre != nullptr && pre->value > cur1->value) {
			res = false;
		}
		pre = cur1;
		cur1 = cur1->right;
	}
	return res;
}

bool iscbt(Node* head) {
	if (head == nullptr) {
		return true;
	}
	std::queue<Node*> queue;
	bool leaf = false;
	Node* left = nullptr;
	Node* right = nullptr;
	queue.push(head);
	while (!queue.empty()) {
		head = queue.front();
		queue.pop();
		left = head->left;
		right = head->right;
		if (leaf && (left != nullptr || right != nullptr)
			|| (left == nullptr && right != nullptr)) {
			return false;
		}
		if (left != nullptr) {
			queue.push(left);
		}
		if (right != nullptr) {
			queue.push(right);
		}else{
			leaf = true;
		}
	}
	return true;
}

int main() {

	Node* head = new Node(4);
	head->left = new Node(2);
	head->right = new Node(5);
	head->left->left = new Node(1);
	head->left->right = new Node(3);

	std::cout << isbst(head) << std::endl;
	
	std::cout << iscbt(head) << std::endl;

	return 0;
}