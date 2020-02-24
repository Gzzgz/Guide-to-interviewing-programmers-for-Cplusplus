/*
【名称】环形单链表的约瑟夫问题
【题目】据说著名犹太历史学家Josephus有过以下故事：在罗马人占领桥塔帕特后，
39个犹太人与Josephus及他的朋友躲到一个洞中，39个犹太人决定宁愿死也不要被
敌人抓到，于是决定了一个自杀方式，40个人排成一个圆圈，由第1个人开始报数，
报数到3的人就自杀，然后再由下一个人重新报1，报数到3的人再自杀，这样依次下
去，直到剩下最后一个人时，那个人可以自由选择自己的命运。这就是著名的约瑟夫
问题。现在请用单向环形链表描述该结构并呈现整个自杀过程。
输入：一个环形单向链表的头节点head和报数的值m
返回：最后生存下来的节点，且这个节点自己组成环形单向链表，其他节点都删掉
进阶：如果链表节点数为N，想在时间复杂度为 O(N) 时完成原问题的要求，该怎么实现
【难度】
原问题：士
进阶：校
*/

#include <iostream>

typedef struct Node {

	int value_;
	Node* next_;
}Node, *Linklist;


Linklist creatListByTail(Linklist head, int start, int end) {
	head = (Linklist)malloc(sizeof(Node));
	Node* node = nullptr;
	Node* tail = nullptr;
	head->next_ = nullptr;
	tail = head;
	for (int i = start; i <= end; i++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = i;
		tail->next_ = node;
		tail = node;
	}
	head = head->next_;
	tail->next_ = head;

	return head;
}

void illustrate(Linklist head) {
	Linklist tmp = head;
	while (tmp != nullptr)
	{
		std::cout << tmp->value_ << std::endl;
		tmp = tmp->next_;
	}
}

Linklist josephusKill(Linklist head, int m) {

	if (head == nullptr || head->next_ == head || m < 1) {
		return head;
	}
	Linklist last = head;
	while (last->next_ != head) {
		last = last->next_;
	}
	int count = 0;
	while (head != last) {
		if (++count == m) {
			last->next_ = head->next_;
			count = 0;
		}
		else {
			last = last->next_;
		}
		head = last->next_;
	}
	return head;
}


int getLive(int i, int m) {
	if (i == 1) {
		return 1;
	}
	return (getLive(i - 1, m) + m - 1) % i + 1;
}

Linklist josephusKill2(Linklist head, int m) {

	if (head == nullptr || head->next_ == head || m < 1) {
		return head;
	}
	Linklist cur = head->next_;
	int tmp = 1;
	while (cur != head) {
		tmp++;
		cur = cur->next_;
	}
	tmp = getLive(tmp, m);
	int count = 0;
	while (--tmp != 0) {
		head = head->next_;
	}
	head->next_ = head;
	return head;
}

int main() {
	
	Linklist list;
	list = creatListByTail(list, 1, 5);
	
	list = josephusKill2(list, 3);

	illustrate(list);

	return 0;
}