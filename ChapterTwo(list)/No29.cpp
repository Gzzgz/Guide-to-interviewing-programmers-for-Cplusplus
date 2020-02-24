/*
【名称】合并两个有序的单链表
【题目】给定俩个有序单链表的头节点head1,head2，请合并两个有序链表，合并后的
链表依然有序，并返回合并后链表的头节点。
例如:0->2->3->7->null, 2->3->5->7->9->null
合并后的链表为0->1->2->3->3->5->7->7->9->null
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
	while (tem != nullptr) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

Linklist merge(Linklist head1, Linklist head2) {
	
	head1 = head1->next_;
	head2 = head2->next_;

	if (head1 == nullptr || head2 == nullptr) {
		return head1 != nullptr ? head1 : head2;
	}
	Node* head = head1->value_ < head2->value_ ? head1 : head2;
	Node* cur1 = head == head1 ? head1 : head2;
	Node* cur2 = head == head1 ? head2 : head1;
	Node* pre = nullptr;
	Node* next = nullptr;
	while (cur1 != nullptr && cur2 != nullptr) {
		if (cur1->value_ <= cur2->value_) {
			pre = cur1;
			cur1 = cur1->next_;
		}
		else {
			next = cur2->next_;
			pre->next_ = cur2;
			cur2->next_ = cur1;
			pre = cur2;
			cur2 = next;
		}
	}
	pre->next_ = cur1 == nullptr ? cur2 : cur1;
	return head;
}

int main() {

	int arr1[] = {0,2,3,7};
	int arr2[] = {1,3,5,7,9};
	Linklist list1, list2, addlist;
	list1 = creatListByTail(list1, arr1, 4);
	list2 = creatListByTail(list2, arr2, 5);

	addlist = merge(list1, list2);

	illustrate(addlist);

	return 0;
}