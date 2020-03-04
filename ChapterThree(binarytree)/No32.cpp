/*
�����ơ���ӡ�������ı߽�ڵ�
����Ŀ������һ�ö�������ͷ�ڵ�head�������������ֱ�׼�ֱ�ʵ�ֶ�����
�߽�ڵ����ʱ���ӡ��
��׼һ��
1.ͷ�ڵ�Ϊ�߽�ڵ㣻
2.Ҷ�ڵ�Ϊ�߽�ڵ㣻
3.����ڵ��������ڵĲ���ʿ��������ҵģ���ôҲ�Ǳ߽�ڵ㡣
��׼����
1.ͷ�ڵ�Ϊ�߽�ڵ㣻
2.Ҷ�ڵ�Ϊ�߽�ڵ㣻
3.����߽�������ȥ��·��Ϊ�߽�ڵ㣻
4.���ұ߽�������ȥ��·��Ϊ�߽�ڵ㡣
Ҫ��
1.����ڵ���ΪN�����ֱ�׼ʵ�ֵ�ʱ�临�Ӷ�Ҫ��ΪO(N), ����ռ�
���Ӷ�Ҫ����O(h)��hΪ�������ĸ߶�
2.���ֱ�׼��Ҫ����ʱ��˳���Ҳ��ظ���ӡ���еı߽�ڵ㡣
���Ѷȡ�ξ
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value), left(nullptr), right(nullptr){}
};

int getHeight(Node* head, int len) {
	if (head == nullptr) {
		return len;
	}
	int left = getHeight(head->left, len + 1);
	int right = getHeight(head->right, len + 1);
	return left >= right ? left : right;
}

void setEdgeMap(Node* head, int len, Node*** edgemap) {
	if (head == nullptr) {
		return;
	}
	edgemap[len][0] = edgemap[len][0] == nullptr ? head : edgemap[len][0];
	edgemap[len][1] = head;
	setEdgeMap(head->left, len + 1, edgemap);
	setEdgeMap(head->right, len + 1, edgemap);
}

void printLeafNotInMap(Node* head, int len, Node*** m) {
	if (head == nullptr) {
		return;
	}
	if (head->left == nullptr && head->right == nullptr &&
		head != m[len][0] && head != m[len][1]) {
		std::cout << head->value << " ";
	}
	printLeafNotInMap(head->left, len + 1, m);
	printLeafNotInMap(head->right, len + 1, m);
}

void printEdge1(Node* head) {
	if (head == nullptr) {
		return;
	}
	int height = getHeight(head, 0);
	Node*** edgemap = new Node**[height];
	for (int i = 0; i < height; i ++) {
		edgemap[i] = new Node*[2];
		for (int j = 0; j < 2; j ++) {
			edgemap[i][j] = nullptr;
		}
	}
	setEdgeMap(head, 0, edgemap);
	for (int i = 0; i < height; i ++) {
		std::cout << edgemap[i][0]->value << " ";
	}
	printLeafNotInMap(head, 0, edgemap);
	for (int i = height - 1; i >= 0; i --) {
		if (edgemap[i][0] != edgemap[i][1]) {
			std::cout << edgemap[i][1]->value << " ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < height; i ++) {
		delete[] edgemap[i];
	}
	delete[] edgemap;
}


void printLeftEdge(Node* head, bool print) {
	if (head == nullptr) {
		return;
	}
	if (print || (head->left == nullptr && head->right == nullptr)) {
		std::cout << head->value << " ";
	}
	printLeftEdge(head->left, print);
	printLeftEdge(head->right, print && (head->left == nullptr) ? true : false);
}

void printRightEdge(Node* head, bool print) {
	if (head == nullptr) {
		return;
	}
	printRightEdge(head->left, print && (head->right == nullptr) ? true : false);
	printRightEdge(head->right, print);
	if (print || (head->left == nullptr && head->right == nullptr)) {
		std::cout << head->value << " ";
	}
}

void printEdge2(Node* head) {
	if (head == nullptr) {
		return;
	}
	std::cout << head->value << " ";
	if (head->left != nullptr && head->left != nullptr) {
		printLeftEdge(head->left, true);
		printRightEdge(head->right, true);
	}
	else {
		printEdge2(head->left != nullptr ? head->left : head->right);
	}
	std::cout << std::endl;
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->right = new Node(4);
	head->right->left = new Node(5);
	head->right->right = new Node(6);
	head->left->right->left = new Node(7);
	head->left->right->right = new Node(8);
	head->right->left->left = new Node(9);
	head->right->left->right = new Node(10);
	head->left->right->right->right = new Node(11);
	head->right->left->left->left = new Node(12);
	head->left->right->right->right->left = new Node(13);
	head->left->right->right->right->right = new Node(14);
	head->right->left->left->left->left = new Node(15);
	head->right->left->left->left->right = new Node(16);

	printEdge1(head);

	printEdge2(head);

	return 0;
}