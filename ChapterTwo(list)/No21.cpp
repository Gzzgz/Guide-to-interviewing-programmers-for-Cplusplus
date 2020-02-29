/*
【名称】两个单链表相交得一系列问题
【题目】在本题目中，单链表可能由环，也可能无环，给定两个单链表的头节点head1,
head2,这两个链表可能相交，也可能不相交。请实现一个函数，如果两个链表相交，请
返回相交的第一个节点，如果不相交，返回null即可。
要求：如果链表1的长度为N,链表2的长度为M，时间复杂度请达到O(N+M), 额外空间复杂度
请达到O(1).
【难度】将
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
	head = head->next_;

	return head;
}

void illustrate(Linklist head) {
	Linklist tem = head;
	while (tem != NULL) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

Node* getLoopNode(Node* head) {
	if (head == nullptr || head->next_ == nullptr
		|| head->next_->next_ == nullptr) {
		return nullptr;
	}
	Node* n1 = head->next_;
	Node* n2 = head->next_->next_;
	while (n1 != n2) {
		if (n2->next_ == nullptr || n2->next_->next_ == nullptr) {
			return nullptr;
		}
		n2 = n2->next_->next_;
		n1 = n2->next_;
	}
	n2 = head;
	while (n1 != n2) {
		n1 = n1->next_;
		n2 = n2->next_;
	}
	return n1;
}

Node* noLoop(Node* head1, Node* head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return nullptr;
	}
	Node* cur1 = head1;
	Node* cur2 = head2;
	int n = 0;
	while (cur1->next_ != nullptr) {
		n++;
		cur1 = cur1->next_;
	}
	while (cur2->next_ != nullptr) {
		n--;
		cur2 = cur2->next_;
	}
	if (cur1 != cur2) {
		return nullptr;
	}
	cur1 = n > 0 ? head1 : head2;
	cur2 = cur1 == head1 ? head2 : head1;
	n = std::abs(n);
	while (n != 0) {
		n--;
		cur1 = cur1->next_;
	}
	while (cur1 != cur2) {
		cur1 = cur1->next_;
		cur2 = cur2->next_;
	}
	return cur1;
}

Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2) {
	Node* cur1 = nullptr;
	Node* cur2 = nullptr;
	if (loop1 == loop2) {
		cur1 = head1;
		cur2 = head2;
		int n = 0;
		while (cur1 != loop1) {
			n++;
			cur1 = cur1->next_;
		}
		while (cur2 != loop2) {
			n--;
			cur2 = cur2->next_;
		}
		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;
		n = std::abs(n);
		while (n != 0) {
			n--;
			cur1 = cur1->next_;
		}
		while (cur1 != cur2) {
			cur1 = cur1->next_;
			cur2 = cur2->next_;
		}
		return cur1;
	}
	else {
		cur1 = loop1->next_;
		while (cur1 != loop1) {
			if (cur1 == loop2) {
				return loop1;
			}
			cur1 = cur1->next_;
		}
		return nullptr;
	}
}

Node* getIntersectNode(Node* head1, Node* head2) {
	if (head1 == nullptr || head2 == nullptr) {
		return nullptr;
	}
	Node* loop1 = getLoopNode(head1);
	Node* loop2 = getLoopNode(head2);
	if (loop1 == nullptr && loop2 == nullptr) {
		return noLoop(head1, head2);
	}
	if (loop1 != nullptr && loop2 != nullptr) {
		return bothLoop(head1, loop1, head2, loop2);
	}
	return nullptr;
}

int main() {

	int arr1[] = {1,2,3,4,5,6};
	int arr2[] = {6,5,4,3,2,1};
	Linklist list1, list2, list;
	
	list1 = creatListByTail(list1, arr1, 6);
	list2 = creatListByTail(list2, arr2, 6);

	list2->next_->next_->next_ = list1->next_->next_;

	list = getIntersectNode(list1, list2);

	illustrate(list);

	return 0;
}