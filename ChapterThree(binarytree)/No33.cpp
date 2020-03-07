/*
�����ơ���ν�Ϊֱ�۵ش�ӡ������
����Ŀ�������������ó�������ֱ��������������ṹ�����ǲ���ֱ�ۣ�
�����Ƕ����������ظ�ֵ��ʱ�򣬽�ͨ�����ֱ����Ľ������������������
����ʵ�ṹ�������ϼ��ѣ���ʱ����������ܡ�����һ�ö�������ͷ�ڵ�
head,��֪�������ڵ�ֵ������Ϊ32λ���ͣ���ʵ��һ����ӡ�������ĺ�����
����ֱ�۵�չʾ������״��Ҳ���ڻ�����ʵ�Ľṹ��
���Ѷȡ�ξ
*/
#include <iostream>
#include <string>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

std::string getSpace(int num) {
	std::string space = " ";
	std::string buf = "";
	for (int i = 0; i < num; i ++) {
		buf.append(space);
	}
	return buf;
}

void printInOrder(Node* head, int height, std::string to, int len) {
	if (head == nullptr) {
		return;
	}
	printInOrder(head->right, height + 1, "V", len);
	std::string val = to + std::to_string(head->value) + to;
	int lenM = val.length();
	int lenL = (len - lenM) / 2;
	int lenR = len - lenM - lenL;
	val = getSpace(lenL) + val + getSpace(lenR);
	std::cout << (getSpace(height * len) + val) << std::endl;
	printInOrder(head->left, height + 1, "^", len);
}

void printTree(Node* head) {
	printInOrder(head, 0, "H", 17);
	std::cout << std::endl;
}

void createBT(Node **head, int arr[], int len, int index = 0)
{
	if (index > len - 1 || -1 == arr[index])
		return;
	(*head) = new Node(arr[index]);
	createBT(&((*head)->left), arr, len, 2 * index + 1);
	createBT(&((*head)->right), arr, len, 2 * index + 2);
}

int main() {

	int arr[] = { 1,2,3,4,-1,5,6,-1,7 };
	Node *root = NULL;
	createBT(&root, arr, 9);
	printTree(root);

	return 0;
}