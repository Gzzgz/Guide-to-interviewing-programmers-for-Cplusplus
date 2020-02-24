/*
�����ơ��������Ұ����ķ�ʽ������ϵ�����
����Ŀ������һ���������ͷ���ڵ�head,������ΪN�����NΪż����
��ôǰN/2���ڵ��������������N/2���ڵ������Ұ��������NΪ������
��ôǰN/2���ڵ��������������N/2+1���ڵ������Ұ��������������
�������μ�ΪL1->L2->...���Ұ������������μ�ΪR1->R2->...����
�����������ΪL1->R1->L2->R2->...����ʽ��
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
	while (tem != nullptr) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

void mergeLR(Linklist left, Linklist right) {
	Node* next = nullptr;
	while (left->next_ != nullptr) {
		next = right->next_;
		right->next_ = left->next_;
		left->next_ = right;
		left = right->next_;
		right = next;
	}
	left->next_ = right;
}

Linklist relocate(Linklist head) {
	
	head = head->next_;

	if (head == nullptr || head->next_ == nullptr) {
		return head;
	}
	Node* mid = head;
	Node* right = head->next_;
	while (right->next_ != nullptr && right->next_->next_ != nullptr) {
		mid = mid->next_;
		right = right->next_->next_;
	}
	right = mid->next_;
	mid->next_ = nullptr;
	mergeLR(head, right);

	return head;
}

int main() {

	int arr[] = {1,2,3,4,5,6};
	Linklist list = nullptr;
	list = creatListByTail(list, arr, 6);

	list = relocate(list);

	illustrate(list);

	return 0;
}
