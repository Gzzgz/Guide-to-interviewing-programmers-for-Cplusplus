/*
�����ơ�ɾ������������ֵ�ظ����ֵĽڵ�
����Ŀ������һ�����������ͷ�ڵ�head,ɾ������ֵ�ظ����ֵĽڵ㡣
���磺1->2->3->3->4->4->2->1->1->null,ɾ��ֵ�ظ��Ľڵ�֮��Ϊ1->2->3->4->null
�밴����Ҫ��ʵ�����ַ���
����1�����������ΪN,ʱ�临�Ӷ�Ϊ O(N)
����2������ռ临�Ӷ�ΪO(1)
���Ѷȡ�ʿ
*/
#include <iostream>
#include <set>

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

void removeRep1(Linklist head) {
	 
	if (head == nullptr) {
		return;
	}
	std::set<int> set;
	Node* pre = head;
	Node* cur = head->next_;
	set.insert(head->value_);
	while (cur != nullptr) {
		if (set.find(cur->value_) != set.end()) {
			pre->next_ = cur->next_;
		}
		else {
			set.insert(cur->value_);
			pre = cur;
		}
		cur = cur->next_;
	}
}

void removeRep2(Linklist head) {
	Node* cur = head;
	Node* pre = nullptr;
	Node* next = nullptr;
	while (cur != nullptr) {
		pre = cur;
		next = cur->next_;
		while (next != nullptr) {
			if (cur->value_ == next->value_) {
				pre->next_ = next->next_;
			}
			else {
				pre = next;
			}
			next = next->next_;
		}
		cur = cur->next_;
	}
}


int main() {

	int arr[] = {1,2,3,4, 4,2,1,1};
	Linklist list = nullptr;
	list = creatListByTail(list, arr, 8);

	removeRep2(list);
	illustrate(list);

	return 0;
}