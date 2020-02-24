/*
�����ơ�������Ļ��ε������в����½ڵ�
����Ŀ��һ�����ε������ͷ�ڵ�head��ʼ������ͬʱ�����Ľڵ�ָ��ͷ�ڵ㡣��������һ�����ε������ͷ�ڵ�head��һ������num,
�����ɽڵ�ֵΪnum���½ڵ㣬�����뵽������������У���֤�������������Ȼ����
���Ѷȡ�ʿ
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