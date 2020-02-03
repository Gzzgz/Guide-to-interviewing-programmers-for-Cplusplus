/*
�����ơ���ת���ֵ�������
����Ŀ������һ�����������ͷ�ڵ�head,�Լ���������from��to,�ڵ��������ϰѵ�from���ڵ㵽��to���ڵ���һ���ֽ��з�ת
��Ҫ��
1.���������ΪN,ʱ�临�Ӷ�Ҫ��ΪO(N), ����ռ临�Ӷ�Ҫ��ΪO(1)
2. ���������1<=from<=to<=N,���õ���
���Ѷȡ�ʿ
*/

#include <iostream>

typedef struct Node {
	int value_;
	Node* next_;
}Node, *Linklist;

void illustrate(Linklist head) {
	Linklist tmp = head->next_;
	while (tmp != nullptr) {
		std::cout << tmp->value_ << std::endl;
		tmp = tmp->next_;
	}
}

Linklist createLinklistByTail(Linklist head, int intArray[], int len) {
	head = (Linklist)malloc(sizeof(Node));
	Node* tail = nullptr;
	Node* node = nullptr;
	head->next_ = nullptr;
	tail = head;
	for (int i = 0; i < len; i++) {
		node = (Linklist)malloc(sizeof(Node));
		node->value_ = intArray[i];
		tail->next_ = node;
		tail = node;
	}
	tail->next_ = nullptr;
	return head;
}

Linklist reversePart(Linklist head, int from, int to) {

	int len = -1;
	Node* node1 = head;
	Node* fPre = nullptr;
	Node* tPos = nullptr;
	while (node1 != nullptr) {
		len++;
		fPre = (len == from - 1) ? node1 : fPre;
		tPos = (len == to + 1) ? node1 : tPos;
		node1 = node1->next_;
	}
	if (from > to || from < 1 || to > len) {
		return head;
	}
	node1 = (fPre == nullptr) ? head : fPre->next_;
	Node* node2 = node1->next_;
	node1->next_ = tPos;
	Node* next = nullptr;
	while (node2 != tPos) {
		next = node2->next_;
		node2->next_ = node1;
		node1 = node2;
		node2 = next;
	}
	if (fPre != nullptr) {
		fPre->next_ = node1;
		return head;
	}
	return node1;
}

int main() {

	int intArry[] = {1, 2, 3, 4, 5, 6, 7};
	Linklist list = nullptr;
	list = createLinklistByTail(list, intArry, 7);

	list = reversePart(list, 2, 4);
	illustrate(list);

	return 0;
}