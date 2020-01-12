/*
【名称】在单链表和双链表中删除倒数第K个节点
【题目】分别实现两个函数，一个可以删除单链表中倒数第K个节点，另一个可以删除双链表中倒数第K个节点
【要求】如果链表长度为N,时间复杂度达到O(N),额外空间复杂度达到O(1)
【难度】士
*/


#include <iostream>

typedef struct Node {

	int value_;
	Node* next_;
}Node, *Linklist;

Linklist createLinklistByTail(Linklist head, int intArray[], int len) {
	head = (Linklist)malloc(sizeof(Node));
	Node* node = nullptr;
	Node* tail = nullptr;
	head->next_ = nullptr;
	tail = head;
	for (int i = 0; i < len; i++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = intArray[i];
		node->next_ = nullptr;
		tail->next_ = node;
		tail = node;
	}
	tail->next_ = nullptr;
	return head;
}

void illustrate(Linklist head) {
	Linklist tem = head;
	while (tem->next_ != nullptr) {
		tem = tem->next_;
		std::cout << tem->value_ << std::endl;
	}
}

Linklist removeLastKthNode(Linklist head, int lastKth) {
	if (head == nullptr || lastKth < 1) {
		return head;
	}
	Linklist cur = head;
	while (cur != nullptr) {
		lastKth--;
		cur = cur->next_;
	}
	if (lastKth == 0) {
		head = head->next_;
	}
	if (lastKth < 0) {
		cur = head;
		while (++lastKth != 0) {
			cur = cur->next_;
		}
		cur->next_ = cur->next_->next_;
	}
	return head;
}


typedef struct DoubleNode {

	int value_;
	DoubleNode* last_;
	DoubleNode* next_;
}DoubleNode, *DoubleLinklist;

DoubleLinklist createLinklistByTail(DoubleLinklist head, int intArray[], int len) {
	head = (DoubleLinklist)malloc(sizeof(DoubleNode));
	DoubleNode* node = nullptr;
	DoubleNode* tail = nullptr;
	head->next_ = nullptr;
	head->last_ = nullptr;
	tail = head;
	for (int i = 0; i < len; i ++) {
		node = (DoubleLinklist)malloc(sizeof(DoubleNode));
		node->value_ = intArray[i];
		node->next_ = nullptr;
		node->last_ = tail;
		tail->next_ = node;
		tail = node;
	}
	tail->next_ = nullptr;
	return head;
}

void illustrate(DoubleLinklist head) {
	DoubleLinklist tem = head;
	while (tem->next_ != nullptr) {
		tem = tem->next_;
		std::cout << tem->value_ << std::endl;
	}
}

DoubleLinklist removeLastKthNode(DoubleLinklist head, int lastKth) {
	if (head == nullptr || lastKth < 1) {
		return head;
	}
	DoubleLinklist cur = head;
	while (cur != nullptr) {
		lastKth--;
		cur = cur->next_;
	}
	if (lastKth == 0) {
		head = head->next_;
		head->last_ = nullptr;
	}
	if (lastKth < 0) {
		cur = head;
		while (++ lastKth != 0) {
			cur = cur->next_;
		}
		DoubleLinklist newnode = cur->next_->next_;
		cur->next_ = newnode;
		if (newnode != nullptr) {
			newnode->last_ = cur;
		}
	}
	return head;
}

int main() {

	int intArry[7] = {1, 2, 3, 4, 5, 6, 7};

	Linklist linklist = nullptr;
	linklist = createLinklistByTail(linklist, intArry, 7);
	illustrate(linklist);
	linklist = removeLastKthNode(linklist, 2);
	illustrate(linklist);

	DoubleLinklist doublelinklist = nullptr;
	doublelinklist = createLinklistByTail(doublelinklist, intArry, 7);
	illustrate(doublelinklist);
	doublelinklist = removeLastKthNode(doublelinklist, 7);
	illustrate(doublelinklist);

	return 0;
}