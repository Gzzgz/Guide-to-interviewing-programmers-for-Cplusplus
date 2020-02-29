/*
【名称】将单向链表按某值划分成左边小，中间相等，右边大的形式
【题目】给定一个单向链表的头节点head，节点的值类型是整型，再给定一个整数pivot.
实现一个调整链表的函数，将链表调整为左部分都是小于pivot的节点，中间部分都是值
等于pivot的节点，右部分都是值大于pivot的节点。除了这个要求外，对调整后的节点顺序
没有更多要求。
例如：9->0->4->5->1,pivot = 3
调整后链表可以是1->0->4->9->5,也可以是0->1->9->5->4,总之，满足左部分都是小于3的节点，
中间部分都是等于3的节点（本例这个部分为空），右部分都是大于3的节点即可，对某部分内部
的节点顺序不做要求。
进阶:
1.在左、中、右三个部分的内部也做顺序要求，要求每部分里的节点从左到右的顺序与原链表中节点
的先后次序一致
例如9->0->4->5->1,pivot = 3，调整后的链表是0->1->9->4->5
2.如果链表长度为N,时间复杂度请达到O(N).额外空间复杂度请达到O(1)
【难度】尉
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

