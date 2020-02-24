/*
�����ơ��������ѡ������
����Ŀ������һ�����������ͷ�ڵ�head��ʵ�ֵ������ѡ������
Ҫ�󣺶���ռ临�Ӷ�ΪO(1)
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
	head = head->next_;

	return head;
}

void illustrate(Linklist head) {
	Linklist tem = head;
	while (tem != nullptr) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

Linklist getSmallestPreNode(Linklist head) {
	Node* smallpre = nullptr;
	Node* small = head;
	Node* pre = head;
	Node* cur = head->next_;
	while (cur != nullptr) {
		if (cur->value_ < small->value_) {
			smallpre = pre;
			small = cur;
		}
		pre = cur;
		cur = cur->next_;
	}
	return smallpre;
}

Linklist selectionSort(Linklist head) {
	Node* tail = nullptr;
	Node* cur = head;
	Node* smallpre = nullptr;
	Node* small = nullptr;
	while (cur != nullptr) {
		small = cur;
		smallpre = getSmallestPreNode(cur);
		if (smallpre != nullptr) {
			small = smallpre->next_;
			smallpre->next_ = small->next_;
		}
		cur = cur == small ? cur->next_ : cur;
		if (tail == nullptr) {
			head = small;
		}
		else {
			tail->next_ = small;
		}
		tail = small;
	}
	return head;
}

int main() {

	int arr[] = {5,6,8,7,4,3,2,1};
	Linklist list = nullptr;
	list = creatListByTail(list, arr, 8);
	list = selectionSort(list);

	illustrate(list);

	return 0;
}