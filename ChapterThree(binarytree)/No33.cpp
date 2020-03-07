/*
【名称】如何较为直观地打印二叉树
【题目】二叉树可以用常规地三种遍历结果来描述其结构，但是不够直观，
尤其是二叉树中有重复值的时候，仅通过三种遍历的结果来构造而构造二叉树
的真实结构更是难上加难，有时则根本不可能。给定一棵二叉树的头节点
head,已知二叉树节点值的类型为32位整型，请实现一个打印二叉树的函数，
可以直观地展示树的形状，也便于画出真实的结构。
【难度】尉
*/
#include <iostream>
#include <string>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

std::string getSpace(int num) {
	std::string space = " ";
	std::string buf = "";
	for (int i = 0; i < num; i ++) {
		buf.append(space);
	}
	return buf;
}

void printInOrder(Node* head, int height, std::string to, int len) {
	if (head == nullptr) {
		return;
	}
	printInOrder(head->right, height + 1, "V", len);
	std::string val = to + std::to_string(head->value) + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = getSpace(lenL) + val + getSpace(lenR);
	std::cout << (getSpace(height * len) + val) << std::endl;
	printInOrder(head->left, height + 1, "^", len);
}

void printTree(Node* head) {
	printInOrder(head, 0, "H", 17);
	std::cout << std::endl;
}

void createBT(Node **head, int arr[], int len, int index = 0)
{
	if (index > len - 1 || -1 == arr[index])
		return;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left), arr, len, 2 * index + 1);
	createBT(&((*head)->right), arr, len, 2 * index + 2);
}

int main() {

	int arr[] = { 1,2,3,4,-1,5,6,-1,7 };
	Node *root = NULL;
	createBT(&root, arr, 9);
	printTree(root);

	return 0;
}