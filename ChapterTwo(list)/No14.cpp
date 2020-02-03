/*
【名称】反转单向和双向链表
【题目】分别实现反转单向链表和反转双向链表的函数
【要求】如果链表长度为N，时间复杂度要求为O(N)，额外空间复杂度要求为O(1)
【难度】士
*/

#include <iostream>


typedef struct Node {

	int value_;
	Node* next_;
}Node, *Linklist;

typedef struct DoubleNode {

	int value_;
	DoubleNode* last_;
	DoubleNode* next_;
}DoubleNode, *DoubleLinklist;

void illustrate(Linklist head) {
	Linklist tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->value_ << std::endl;
		tmp = tmp->next_;
	}
}

void illustrate(DoubleLinklist head) {
	DoubleLinklist tmp = head;
	while (tmp != nullptr && tmp->value_ != -1) {
		std::cout << tmp->value_ << std::endl;
		tmp = tmp->next_;
	}
}

DoubleLinklist createDoubleLinklistByTail(DoubleLinklist head, int intArray[], int len) {
	head = (DoubleLinklist)malloc(sizeof(DoubleNode));
	DoubleNode* tail = nullptr;
	DoubleNode* node = nullptr;
	head->next_ = nullptr;
	head->last_ = nullptr;
	head->value_ = -1;
	tail = head;
	for (int i = 0; i < len; i ++) {
		node = (DoubleLinklist)malloc(sizeof(DoubleNode));
		node->value_ = intArray[i];
		tail->next_ = node;
		node->last_ = tail;
		tail = node;
	}
	tail->next_ = nullptr;

	return head;
}

Linklist createLinklistByTail(Linklist head, int intArray[], int len) {
	head = (Linklist)malloc(sizeof(Node));
	Node* tail = nullptr;
	Node* node = nullptr;
	head->next_ = nullptr;
	tail = head;
	for (int i = 0; i < len; i ++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = intArray[i];
		tail->next_ = node;
		tail = node;
	}
	tail->next_ = nullptr;
	return head;
}

DoubleLinklist createDoubleLinklistByHead(DoubleLinklist head, int intArray[], int len) {
	head = (DoubleLinklist)malloc(sizeof(DoubleNode));
	DoubleNode* node = (DoubleLinklist)malloc(sizeof(DoubleNode));
	node->next_ = nullptr;
	head->next_ = node;
	node->last_ = head;
	node->value_ = -1;

	for (int i = 0; i < len; i ++) {
		node = (DoubleLinklist)malloc(sizeof(DoubleNode));
		node->value_ = intArray[i];
		
		node->next_ = head->next_;
		node->last_ = head;
		head->next_->last_ = node; 
		head->next_ = node;
	}

	return head;
}

Linklist createLinklistByHead(Linklist head, int intArray[], int len) {
	head = (Linklist)malloc(sizeof(Node));
	Node* node = nullptr;
	head->next_ = nullptr;
	node = head->next_;
	head->next_ = node;
	for (int i = 0; i < len; i++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = intArray[i];
		node->next_ = head->next_;
		head->next_ = node;
	}
	return head;
}

Linklist reverseList(Linklist head) {
	Node* pre = nullptr;
	Node* next = nullptr;
	Linklist tmp = head->next_;
	while (tmp != nullptr) {
		next = tmp->next_;
		tmp->next_ = pre;
		pre = tmp;
		tmp = next;
	}
	return pre;
}

DoubleLinklist reverseList(DoubleLinklist head) {
	DoubleLinklist pre = nullptr;
	DoubleLinklist next = nullptr;
	while (head != nullptr) {
		next = head->next_;
		head->next_ = pre;
		head->last_ = next;
		pre = head;
		head = next;
	}
	return pre;
}

int main() {

	int intArray[] = {1, 2, 3, 4, 5, 6, 7};
	
	Linklist list = nullptr;
	//list = createLinklistByHead(list, intArray, 7);
	//list = createLinklistByTail(list, intArray, 7);
	//list = reverseList(list);
	//illustrate(list);

	DoubleLinklist dlist = nullptr;
	dlist = createDoubleLinklistByTail(dlist, intArray, 7);
	//dlist = createDoubleLinklistByHead(dlist, intArray, 7);
	dlist = reverseList(dlist);
	illustrate(dlist);


	return 0;
}