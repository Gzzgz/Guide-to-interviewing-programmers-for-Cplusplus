/*
�����ơ����������ÿK���ڵ�֮������
����Ŀ������һ���������ͷ�ڵ�head��ʵ��һ������������ĺ�����ʹ��ÿK���ڵ�
֮�����������󲻹�K���ڵ�һ�飬�򲻵�����󼸸��ڵ㡣
���磺���� 1->2->3->4->5->6->7->8->null, K=3
������Ϊ��3->2->1->6->5->4->7->8->null,����7,8����������Ϊ����һ��
���Ѷȡ�ξ
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

Linklist resign1(std::stack<Node*>& stack, Node* left, Node* right) {
	Node* cur = stack.top();
	stack.pop();
	if (left != nullptr) {
		left->next_ = cur;
	}
	Node* next = nullptr;
	while (!stack.empty()) {
		next = stack.top();
		stack.pop();
		cur->next_ = next;
		cur = next;
	}
	cur->next_ = right;
	
	return cur;
}

Linklist reverseKNodes1(Linklist head, int k) {
	if (k < 2) {
		return head;
	}
	std::stack<Node*> stack;
	Node* newhead = head;
	Node* cur = head;
	Node* pre = nullptr;
	Node* next = nullptr;
	while (cur != nullptr) {
		next = cur->next_;
		stack.push(cur);
		if (stack.size() == k) {
			pre = resign1(stack, pre, next);
			newhead = newhead == head ? cur : newhead;
		}
		cur = next;
	}
	return newhead;
}

void resign2(Node* left, Node* start, Node* end, Node* right) {
	Node* pre = start;
	Node* cur = start->next_;
	Node* next = nullptr;
	while (cur != right) {
		next = cur->next_;
		cur->next_ = pre;
		pre = cur;
		cur = next;
	}
	if (left != nullptr) {
		left->next_ = end;
	}
	start->next_ = right;
}

Linklist reverseKNodes2(Linklist head, int k) {
	if (k < 2) {
		return head;
	}
	Node* cur = head;
	Node* start = nullptr;
	Node* pre = nullptr;
	Node* next = nullptr;
	int count = 1;
	while (cur != nullptr) {
		next = cur->next_;
		if (count == k) {
			start = pre == nullptr ? head : pre->next_;
			head = pre == nullptr ? cur : head;
			resign2(pre, start, cur, next);
			pre = start;
			count = 0;
		}
		count++;
		cur = next;
	}
	return head;
}

int main() {

	int arr[] = {1,2,3,4,5,6,7,8};
	Linklist list;
	list = creatListByTail(list, arr, 8);

	list = reverseKNodes2(list, 3);

	illustrate(list);

	return 0;
}
