/*
【名称】打印两个有序链表的公共部分
【题目】给定两个有序链表的头指针head1和head2,打印两个链表的公共部分
【难度】士
*/

#include <iostream>

typedef struct Node {

	int value_;
    Node* next_;
}Node, *Linklist;

//头插法
Linklist creatListByHead(Linklist head, int start, int end) {
	head = (Linklist)malloc(sizeof(Node));
	Node * node = nullptr;
	head->next_ = nullptr;
	node = head->next_;
	for (int i = start; i <= end; i++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = i;
		node->next_ = head->next_;
		head->next_ = node;
	}
	return head;
}

//尾插法
Linklist creatListByTail(Linklist head, int start, int end) {
	head = (Linklist)malloc(sizeof(Node));
	Node* node = nullptr;
	Node* tail = nullptr;
	head->next_ = nullptr;
	tail = head;
	for (int i = start; i <= end; i ++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = i;
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

void printCommonPart(Linklist head1, Linklist head2) {
	std::cout << "Common part: " << std::endl;
	head1 = head1->next_;
	head2 = head2->next_;

	while (head1 != nullptr && head2 != nullptr){
		if (head1->value_ < head2->value_) {
			head1 = head1->next_;
			
		}
		else if (head1->value_ > head2->value_) {
			head2 = head2->next_;
		}
		else {
			std::cout << head2->value_ << std::endl;
			head1 = head1->next_;
			head2 = head2->next_;
		}
	}
}


int main() {

	Linklist head1 = nullptr;
	Linklist head2 = nullptr;

	head1 = creatListByTail(head1, 1, 5);
	head2 = creatListByTail(head2, 5, 8);

	illustrate(head1);
	illustrate(head2);

	printCommonPart(head1, head2);

	return 0;
}