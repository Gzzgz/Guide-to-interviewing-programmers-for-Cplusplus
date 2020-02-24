/*
【名称】一种怪异的节点删除方式
【题目】链表节点值类型为int，给定一个链表中的节点node，但不给定整个链表的头节点。
如何在链表中删除node,请实现这个函数，并分析这么做会出现哪些问题
要求：时间复杂度为O(1)
【难度】士
*/
#include <iostream>

typedef struct Node {

	int value_;
	Node* next_;
}Node, *Linklist;

Linklist creatListByTail(Linklist head, int* arr, int len) {
	head = (Linklist)malloc(sizeof(Node));
	Node* node = nullptr;
	Node* tail = nullptr;
	head->next_ = nullptr;
	tail = head;
	for (int i = 0; i < len; i++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = arr[i];
		tail->next_ = node;
		tail = node;
	}
	tail->next_ = nullptr;

	return head;
}

void illustrate(Linklist head) {
	Linklist tem = head;
	while (tem->next_ != NULL) {
		tem = tem->next_;
		std::cout << tem->value_ << std::endl;
	}
}

void removeNodeWired(Linklist node) {
	if (node == nullptr) {
		return;
	}
	Node* next = node->next_;
	if (next == nullptr) {
		return;
	}
	node->value_ = next->value_;
	node->next_ = next->next_;
}

int main() {

	int arr[] = {1,2,3,4};

	Linklist list = nullptr;
	list = creatListByTail(list, arr, 4);

	removeNodeWired(list->next_->next_->next_);

	illustrate(list);

	return 0;
}