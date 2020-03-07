/*
�����ơ����ݺ��������ؽ�����������
����Ŀ������һ����������arr����֪����û���ظ�ֵ���ж�arr�Ƿ����
�ǽڵ�ֵ����Ϊ���͵�������������������Ľ��
���ף������������arr��û���ظ�ֵ������֪��һ�������������ĺ���
���������ͨ������arr�ع�������
���Ѷȡ�ʿ
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};
bool isPost(int* arr, int start, int end) {
	if (start == end) {
		return true;
	}
	int less = -1;
	int more = end;
	for (int i = start; i < end; i ++) {
		if (arr[end] > arr[i]) {
			less = i;
		}
		else {
			more = more == end ? i : more;
		}
	}
	if (less == -1 || more == end) {
		return isPost(arr, start, end - 1);
	}
	if (less != more - 1) {
		return false;
	}
	return isPost(arr, start, less) && isPost(arr, more, end - 1);
}

bool isPostArray(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return false;
	}
	return isPost(arr, 0, len - 1);
}

Node* posToBST(int* arr, int start, int end) {
	if (start > end) {
		return nullptr;
	}
	Node* head = new Node(arr[end]);
	int less = -1;
	int more = end;
	for (int i = start; i < end; i ++) {
		if (arr[end] > arr[i]) {
			less = i;
		}
		else {
			more = more == end ? i : more;
		}
	}
	head->left = posToBST(arr, start, less);
	head->right = posToBST(arr, more, end - 1);
	return head;
}

Node* posArrayToBST(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return nullptr;
	}
	return posToBST(arr, 0, len - 1);
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

	int arr[] = {0,2,1,4,3,6,9,8,7,5};
	std::cout << isPostArray(arr, 10) << std::endl;

	Node* head = posArrayToBST(arr, 10);
	showTree(head);

	return 0;
}