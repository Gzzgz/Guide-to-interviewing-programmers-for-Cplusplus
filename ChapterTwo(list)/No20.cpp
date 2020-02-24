/*
【名称】两个单链表生成相加链表
【题目】假设链表中每一个节点的值都在0-9之间，那么链表整体就可以代表一个整数
例如：9->3->7,可以代表整数937.给定两个这种链表的头节点head1,head2，请生成代
表两个整数相加值得结果链表。
例如:链表1为9->3->7,链表2为6->3,最后生成新的结果链表为1->0->0->0
【难度】士
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

	while (tem != NULL) {
		std::cout << tem->value_ << std::endl;
		tem = tem->next_;
	}
}

Linklist addLists1(Linklist head1, Linklist head2) {
	
	std::stack<int> s1, s2;
	head1 = head1->next_;
	head2 = head2->next_;
	while (head1 != nullptr) {
		s1.push(head1->value_);
		head1 = head1->next_;
	}
	while (head2 != nullptr) {
		s2.push(head2->value_);
		head2 = head2->next_;
	}
	int ca = 0;
	int n1 = 0;
	int n2 = 0;
	int n = 0;
	Node* node = nullptr;
	Node* pre = nullptr;
	while (!s1.empty() || !s2.empty()) {
		n1 = s1.empty() ? 0 : s1.top();
		n2 = s2.empty() ? 0 : s2.top();
		if (!s1.empty())s1.pop();
		if (!s2.empty())s2.pop();
		n = n1 + n2 + ca;
		pre = node;
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = n % 10;
		node->next_ = pre;
		ca = n / 10;
	}
	if (ca == 1) {
		pre = node;
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = 1;
		node->next_ = pre;
	}
	return node;
}

Linklist reverseList(Linklist head) {
	Node* pre = nullptr;
	Node* next = nullptr;
	while (head != nullptr) {
		next = head->next_;
		head->next_ = pre;
		pre = head;
		head = next;
	}
	return pre;
}

Linklist addLists2(Linklist head1, Linklist head2) {
	head1 = head1->next_;
	head2 = head2->next_;
	head1 = reverseList(head1);
	head2 = reverseList(head2);

	int ca = 0;
	int n1 = 0;
	int n2 = 0;
	int n = 0;
	Node* c1 = head1;
	Node* c2 = head2;
	Node* node = nullptr;
	Node* pre = nullptr;
	while (c1 != nullptr || c2 != nullptr) {
		n1 = c1 != nullptr ? c1->value_ : 0;
		n2 = c2 != nullptr ? c2->value_ : 0;
		n = n1 + n2 + ca;
		pre = node;
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = n % 10;
		node->next_ = pre;
		ca = n / 10;
		c1 = c1 != nullptr ? c1->next_ : nullptr;
		c2 = c2 != nullptr ? c2->next_ : nullptr;
	}
	if (ca == 1) {
		pre = node;
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = 1;
		node->next_ = pre;
	}
	head1 = reverseList(head1);
	head2 = reverseList(head2);

	return node;
}

int main() {

	int arr1[] = { 9,3,7 }, arr2[] = {6,3};
	Linklist list1, list2, addlist;
	list1 = creatListByTail(list1, arr1, 3);
	list2 = creatListByTail(list2, arr2, 2);

	addlist = addLists2(list1, list2);

	illustrate(addlist);


	return 0;
}