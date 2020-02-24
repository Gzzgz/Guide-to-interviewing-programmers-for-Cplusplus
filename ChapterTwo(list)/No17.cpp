/*
【名称】判断一个链表是否为回文结构
【题目】给定一个链表的头节点 head,请判断该链表是否是回文结构
进阶：如果链表长度为N, 时间复杂度达到O(N)，额外空间复杂度达到O(1)
【难度】
普通解法 士
进阶解法 尉
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
	while (tem->next_ != NULL) {
		tem = tem->next_;
		std::cout << tem->value_ << std::endl;
	}
}


bool isPalindrome1(Linklist head) {
	std::stack<Node*> stack;
	head = head->next_;
	Node* cur = head;
	while (cur != nullptr) {
		stack.push(cur);
		cur = cur->next_;
	}
	while (head != nullptr) {
		if (head->value_ != stack.top()->value_) {
			return false;
		}
		stack.pop();
		head = head->next_;
	}
	return true;
}

bool isPalindrome2(Linklist head) {
	
	head = head->next_;

	if (head == nullptr || head->next_ == nullptr) {
		return true;
	}
	Node* right = head->next_;
	Node* cur = head;
	while (cur->next_ != nullptr && cur->next_->next_ != nullptr) {
		right = right->next_;
		cur = cur->next_->next_;
	}
	std::stack<Node*> stack;
	while (right != nullptr) {
		stack.push(right);
		right = right->next_;
	}
	while (!stack.empty()) {
		if (head->value_ != stack.top()->value_) {
			return false;
		}
		stack.pop();
		head = head->next_;
	}

	return true;
}

bool isPalindrome3(Linklist head) {
	head = head->next_;
	if (head == nullptr || head->next_ == nullptr) {
		return true;
	}
	Node* n1 = head;
	Node* n2 = head;
	while (n2->next_ != nullptr && n2->next_->next_ != nullptr) {
		n1 = n1->next_;
		n2 = n2->next_->next_;
	}
	n2 = n1->next_;
	n1->next_ = nullptr;
	Node* n3 = nullptr;
	while (n2 != nullptr) {
		n3 = n2->next_;
		n2->next_ = n1;
		n1 = n2;
		n2 = n3;
	}
	n3 = n1;
	n2 = head;
	bool res = true;
	while (n1 != nullptr && n2 != nullptr) {
		if (n1->value_ != n2->value_) {
			res = false;
			break;
		}
		n1 = n1->next_;
		n2 = n2->next_;
	}
	n1 = n3->next_;
	n3->next_ = nullptr;
	while (n1 != nullptr) {
		n2 = n1->next_;
		n1->next_ = n3;
		n3 = n1;
		n1 = n2;
	}
	return res;
}

int main() {

	int arr[] = {1,2,2,1};
	Linklist list;
	list = creatListByTail(list, arr, 4);

	std::cout << isPalindrome3(list) << std::endl;

	return 0;
}
