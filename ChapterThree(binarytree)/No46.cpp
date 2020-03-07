/*
�����ơ�ͨ��������������ƽ������������
����Ŀ������һ����������sortArr����֪����û���ظ�ֵ�����������
��������һ��ƽ�����������������Ҹ�������������������Ľ����sortArrһ��
���Ѷȡ�ʿ
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

Node* generate(int* arr, int start, int end) {
	if (start > end) {
		return nullptr;
	}
	int mid = (start + end) / 2;
	Node* head = new Node(arr[mid]);
	head->left = generate(arr, start, mid - 1);
	head->right = generate(arr, mid + 1, end);
	return head;
}

Node* generateTree(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return nullptr;
	}
	return generate(arr, 0, len - 1);
}

void showTree(Node* head) {

	if (head == nullptr) {
		return;
	}
	showTree(head->left);
	std::cout << head->value << std::endl;
	showTree(head->right);
}

int main() {
	int arr[] = {0,1,2,3,4,5,6,7};
	Node* head = generateTree(arr, 8);

	showTree(head);

	return 0;
}