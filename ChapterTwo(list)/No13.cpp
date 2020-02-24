/*
【名称】删除链表的中间节点和a/b处的节点
【题目】给定链表的头节点head,实现删除链表的中间节点的函数。
1.1->2 #删除节点1
2.1->2->3 #删除节点2
3.1->2->3->4 #删除节点2
4.进阶：给定链表头节点head、整数a,b实现删除位于a/b处节点的函数
5.1->2->3->4->5 #假设a/b 为r,
若 r = 0 || r > 1 不删除任何节点
若 r在区间[0, 1/5],删除节点1
若 r在区间[1/5, 2/5],删除节点2
若 r在区间[2/5, 3/5],删除节点3
若 r在区间[3/5, 4/5],删除节点4
若 r在区间[4/5, 1],删除节点5
【难度】士
*/

#include <iostream>


typedef struct Node{

	int value_;
	Node* next_;
}Node, *Linklist;


Linklist createLinklistByHead(Linklist head, int intArray[], int len) {
	head = (Linklist)malloc(sizeof(Node));
	Node* node = nullptr;
	head->next_ = nullptr;
	node = head->next_;
	for (int i = 0; i < len; i ++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = intArray[i];
		node->next_ = head->next_;
		head->next_ = node;
	}
	return head;
}

void illustrate(Linklist head) {
	Linklist tmp = head;
	while (tmp->next_ != nullptr)
	{
		tmp = tmp->next_;
		std::cout << tmp->value_ << std::endl;
	}
}

Linklist removeMidNode(Linklist head) { 

	if (head == nullptr || head->next_ == nullptr) {
		return head;
	}
	if (head->next_->next_->next_ == nullptr) {
		return head->next_;
	}
	Node* pre = head->next_;
	Node* cur = head->next_->next_->next_;
	while (cur->next_ != nullptr && cur->next_->next_ != nullptr) {
		pre = pre->next_;
		cur = cur->next_->next_;
	}
	pre->next_ = pre->next_->next_;
	return head;
}

Linklist removeByRatio(Linklist head, int a, int b) {
	if (a < 1 || a > b) {
		return head;
	}
	int n = -1;
	Linklist cur = head;
	while (cur != nullptr) {
		n++;
		cur = cur->next_;
	}

	n = (int)ceil(((double)(a * n)) / (double)b);

	if (n == 1) {
		head = head->next_;
	}
	if (n > 1) {
		cur = head;
		while (n-- != 1) { // 这里 n -- 与 -- n 不一样
			cur = cur->next_;
		}
		cur->next_ = cur->next_->next_;
	}
	return head;
}




int main() {

	int intArray[] = {7, 6, 5, 4, 3, 2, 1, 0};

	Linklist list = nullptr;
	list = createLinklistByHead(list, intArray, 7);
	illustrate(list);
	
	//list = removeMidNode(list);
	list = removeByRatio(list, 2, 7);
	
	illustrate(list);

	return 0;
}