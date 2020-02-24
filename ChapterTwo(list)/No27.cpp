/*
�����ơ�һ�ֹ���Ľڵ�ɾ����ʽ
����Ŀ������ڵ�ֵ����Ϊint������һ�������еĽڵ�node�������������������ͷ�ڵ㡣
�����������ɾ��node,��ʵ�������������������ô���������Щ����
Ҫ��ʱ�临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
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