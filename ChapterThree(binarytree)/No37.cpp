/*
�����ơ��ҵ��������е����������������
����Ŀ������һ�ö�������ͷ�ڵ�head����֪�������ҽڵ��ֵ����һ����
�ҵ����нڵ����������������������������������ͷ�ڵ㡣
Ҫ������ڵ���ΪN��Ҫ��ʱ�临�Ӷ�ΪO(N)����ռ临�Ӷ�ΪO(h),
hΪ�������ĸ߶�
���Ѷȡ�ξ
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

Node* posOrder(Node* head, int* record) {
	if (head == nullptr) {
		record[0] = 0;
		record[1] = INT_MAX;
		record[2] = INT_MIN;
		return nullptr;
	}
	int value = head->value;
	Node* left = head->left;
	Node* right = head->right;
	Node* lbst = posOrder(left, record);
	int lsize = record[0];
	int lmin = record[1];
	int lmax = record[2];
	Node* rbst = posOrder(right, record);
	int rsize = record[0];
	int rmin = record[1];
	int rmax = record[2];
	record[1] = lmin < value ? lmin : value;
	record[2] = rmax > value ? rmax : value;
	if (left == lbst && right == rbst && lmax < value && value <rmin) {
		record[0] = lsize + rsize + 1;
		return head;
	}
	record[0] = lsize > rsize ? lsize : rsize;
	return lsize > rsize ? lbst : rbst;
}

Node* biggestSubBST(Node* head) {
	int* record = new int[3];
	memset(record, 0, sizeof(int) * 3);
	Node* res = posOrder(head, record);
	delete[] record;
	return res;
}

void showTree(Node* head) {
	if (head == nullptr) {
		return;
	}
	std::cout << head->value << std::endl;
	showTree(head->left);
	showTree(head->right);
}

int main() {

	Node* head = new Node(6);
	head->left = new Node(1);
	head->right = new Node(12);
	head->left->left = new Node(0);
	head->left->right = new Node(3);
	head->right->left = new Node(10);
	head->right->right = new Node(13);
	head->right->left->left = new Node(4);
	head->right->left->right = new Node(14);
	head->right->left->left->left = new Node(2);
	head->right->left->left->right = new Node(5);
	head->right->left->right->left = new Node(11);
	head->right->left->right->right = new Node(15);
	head->right->right->left = new Node(20);
	head->right->right->right = new Node(16);

	head = biggestSubBST(head);

	showTree(head);

	return 0;
}