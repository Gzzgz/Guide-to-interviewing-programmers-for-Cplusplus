/*
【名称】向有序的环形单链表中插入新节点
【题目】一个环形单链表从头节点head开始不降序，同时由最后的节点指回头节点。给定这样一个环形单链表的头节点head和一个整数num,
请生成节点值为num的新节点，并插入到这个环形链表中，保证调整后的链表依然有序。
【难度】士
*/
#include <iostream>

typedef struct Node {

	int value_;
	Node* next_;
}Node, *Linklist;

void illustrate(Linklist head) {
	Linklist tem = head;
	while (tem != nullptr) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

Linklist insertNum(Linklist head, int num) {
	Node* node = (Linklist)malloc(sizeof(Node));
	node->value_ = num;
	if (head == nullptr) {
		node->next_ = node;
		return node;
	}
	Node* pre = head;
	Node* cur = head->next_;
	while (cur != head) {
		if (pre->value_ <= num && cur->value_ >= num) {
			break;
		}
		pre = cur;
		cur = cur->next_;
	}
	pre->next_ = node;
	node->next_ = cur;
	return head->value_ < num ? head : node;
}

int main() {

	int arr[] = {1,2,3,4,5,5};
	Linklist list = nullptr;
	for (int i = 0; i < 6; i ++) {
		list = insertNum(list, arr[i]);
	}
	illustrate(list);

	return 0;
}