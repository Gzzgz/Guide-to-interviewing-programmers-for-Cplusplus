/*
�����ơ����ε������Լɪ������
����Ŀ����˵������̫��ʷѧ��Josephus�й����¹��£���������ռ���������غ�
39����̫����Josephus���������Ѷ㵽һ�����У�39����̫�˾�����Ը��Ҳ��Ҫ��
����ץ�������Ǿ�����һ����ɱ��ʽ��40�����ų�һ��ԲȦ���ɵ�1���˿�ʼ������
������3���˾���ɱ��Ȼ��������һ�������±�1��������3��������ɱ������������
ȥ��ֱ��ʣ�����һ����ʱ���Ǹ��˿�������ѡ���Լ������ˡ������������Լɪ��
���⡣�������õ��������������ýṹ������������ɱ���̡�
���룺һ�����ε��������ͷ�ڵ�head�ͱ�����ֵm
���أ�������������Ľڵ㣬������ڵ��Լ���ɻ��ε������������ڵ㶼ɾ��
���ף��������ڵ���ΪN������ʱ�临�Ӷ�Ϊ O(N) ʱ���ԭ�����Ҫ�󣬸���ôʵ��
���Ѷȡ�
ԭ���⣺ʿ
���ף�У
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