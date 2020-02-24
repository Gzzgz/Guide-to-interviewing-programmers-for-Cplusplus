/*
�����ơ��ڵ�������ɾ��ָ��ֵ�Ľڵ�
����Ŀ������һ�������ͷ�ڵ�head��һ������num,��ʵ�ֺ�����ֵΪnum�Ľڵ�ȫ��ɾ��
���磺����Ϊ1->2->3->4->null, num=3,ɾ�����������Ϊ1->2->4->null
���Ѷȡ� ʿ
*/
#include <iostream>
#include <stack>

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
	while (tem!= NULL) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

Linklist removeValue(Linklist head, int num) {
	std::stack<Node*> stack;
	head = head->next_;
	while (head != nullptr) {
		if (head->value_ != num) {
			stack.push(head);
		}
		head = head->next_;
	}
	while (!stack.empty()) {
		stack.top()->next_ = head;
		head = stack.top();
		stack.pop();
	}
	return head;
}

Linklist removeValue2(Linklist head, int num) {
	head = head->next_;
	while (head != nullptr) {
		if (head->value_ != num) {
			break;
		}
		head = head->next_;
	}
	Node* pre = head;
	Node* cur = head;
	while (cur != nullptr) {
		if (cur->value_ == num) {
			pre->next_ = cur->next_;
		}
		else {
			pre = cur;
		}
		cur = cur->next_;
	}
	return head;
}

int main() {

	int arr[] = {1,2,3,4};
	Linklist list = nullptr;

	list = creatListByTail(list, arr, 4);

	list = removeValue2(list, 3);

	illustrate(list);

	return 0;
}
