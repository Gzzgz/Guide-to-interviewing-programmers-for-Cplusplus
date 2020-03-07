/*
�����ơ��������ڵ�������������
����Ŀ���Ӷ������Ľڵ�A�������������ϻ������ߣ�����;�Ľڵ�ֻ�ܾ���һ�Σ�
������ڵ�Bʱ��·���ϵĽڵ�������A��B�ľ��롣����һ�ö�������ͷ�ڵ�head,
���������Ͻڵ��������롣
Ҫ������������Ľڵ���ΪN,ʱ�临�Ӷ�Ҫ��ΪO(N)
���Ѷȡ�ξ
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