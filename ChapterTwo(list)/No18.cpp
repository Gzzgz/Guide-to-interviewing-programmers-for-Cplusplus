/*
�����ơ�����������ĳֵ���ֳ����С���м���ȣ��ұߴ����ʽ
����Ŀ������һ�����������ͷ�ڵ�head���ڵ��ֵ���������ͣ��ٸ���һ������pivot.
ʵ��һ����������ĺ��������������Ϊ�󲿷ֶ���С��pivot�Ľڵ㣬�м䲿�ֶ���ֵ
����pivot�Ľڵ㣬�Ҳ��ֶ���ֵ����pivot�Ľڵ㡣�������Ҫ���⣬�Ե�����Ľڵ�˳��
û�и���Ҫ��
���磺9->0->4->5->1,pivot = 3
���������������1->0->4->9->5,Ҳ������0->1->9->5->4,��֮�������󲿷ֶ���С��3�Ľڵ㣬
�м䲿�ֶ��ǵ���3�Ľڵ㣨�����������Ϊ�գ����Ҳ��ֶ��Ǵ���3�Ľڵ㼴�ɣ���ĳ�����ڲ�
�Ľڵ�˳����Ҫ��
����:
1.�����С����������ֵ��ڲ�Ҳ��˳��Ҫ��Ҫ��ÿ������Ľڵ�����ҵ�˳����ԭ�����нڵ�
���Ⱥ����һ��
����9->0->4->5->1,pivot = 3���������������0->1->9->4->5
2.���������ΪN,ʱ�临�Ӷ���ﵽO(N).����ռ临�Ӷ���ﵽO(1)
���Ѷȡ�ξ
*/

#include <iostream>

typedef struct Node {

	int value_;
	Node* next_;
}Node, *Linklist;

Linklist creatListByTail(Linklist head, int*arr, int len) {
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

void swap(Node* nodeArr, int a, int b) {
	Node tmp = nodeArr[a];
	nodeArr[a] = nodeArr[b];
	nodeArr[b] = tmp;
}

void arrPartition(Node* nodeArr, int len, int pivot) {
	int small = -1;
	int big = len;
	int index = 0;
	while (index != big) {
		if (nodeArr[index].value_ < pivot) {
			swap(nodeArr, ++small, index++);
		}
		else if (nodeArr[index].value_ == pivot) {
			index++;
		}
		else {
			swap(nodeArr, --big, index);
		}
	}
}

Linklist listPartition1(Node* head, int len, int pivot) {
	if (head == nullptr) {
		return head;
	}
	Node* cur = head;
	int i = 0;
	while (cur != nullptr) {
		i++;
		cur = cur->next_;
	}
	Node* nodeArr = new Node[i];
	i = 0;
	cur = head;
	for (i = 0; i != len; i ++) {
		nodeArr[i].value_ = cur->value_;
		cur = cur->next_;
	}
	arrPartition(nodeArr, len, pivot);

	Linklist list = head;
	for (i = 0; i != len; i ++) {
		list->value_ = nodeArr[i].value_;
		list = list->next_;
	}
	list = head;
	delete[] nodeArr;

	return list;
}

Linklist listPartition2(Linklist head, int len, int pivot) {
	Node* sh = nullptr;
	Node* st = nullptr;
	Node* eh = nullptr;
	Node* et = nullptr;
	Node* bh = nullptr;
	Node* bt = nullptr;
	Node* next = nullptr;
	while (head != nullptr) {
		next = head->next_;
		head->next_ = nullptr;
		if (head->value_ < pivot) {
			if (sh == nullptr) {
				sh = head;
				st = head;
			}
			else {
				st->next_ = head;
				st = head;
			}
		}
		else if (head->value_ == pivot) {
			if (eh == nullptr) {
				eh = head;
				et = head;
			}
			else {
				et->next_ = head;
				et = head;
			}
		}
		else {
			if (bh == nullptr) {
				bh = head;
				bt = head;
			}
			else {
				bt->next_ = head;
				bt = head;
			}
		}
		head = next;
	}
	if (st != nullptr) {
		st->next_ = eh;
		et = et == nullptr ? st : et;
	}
	if (et != nullptr) {
		et->next_ = bh;
	}
	return sh != nullptr ? sh : eh != nullptr ? eh : bh;
}

int main() {

	int arr[] = {9, 0, 4, 5, 1};
	Linklist list = nullptr;
	list = creatListByTail(list, arr, 5);

	list = listPartition2(list, 5, 3);

	illustrate(list);

	return 0;
}

