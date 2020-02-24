/*
�����ơ�ɾ��������м�ڵ��a/b���Ľڵ�
����Ŀ�����������ͷ�ڵ�head,ʵ��ɾ��������м�ڵ�ĺ�����
1.1->2 #ɾ���ڵ�1
2.1->2->3 #ɾ���ڵ�2
3.1->2->3->4 #ɾ���ڵ�2
4.���ף���������ͷ�ڵ�head������a,bʵ��ɾ��λ��a/b���ڵ�ĺ���
5.1->2->3->4->5 #����a/b Ϊr,
�� r = 0 || r > 1 ��ɾ���κνڵ�
�� r������[0, 1/5],ɾ���ڵ�1
�� r������[1/5, 2/5],ɾ���ڵ�2
�� r������[2/5, 3/5],ɾ���ڵ�3
�� r������[3/5, 4/5],ɾ���ڵ�4
�� r������[4/5, 1],ɾ���ڵ�5
���Ѷȡ�ʿ
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
		while (n-- != 1) { // ���� n -- �� -- n ��һ��
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