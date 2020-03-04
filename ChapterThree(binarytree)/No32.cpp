/*
【名称】打印二叉树的边界节点
【题目】给定一棵二叉树的头节点head，按照如下两种标准分别实现二叉树
边界节点的逆时针打印。
标准一：
1.头节点为边界节点；
2.叶节点为边界节点；
3.如果节点在其所在的层中士最左或最右的，那么也是边界节点。
标准二：
1.头节点为边界节点；
2.叶节点为边界节点；
3.树左边界延伸下去的路径为边界节点；
4.树右边界延伸下去的路径为边界节点。
要求：
1.如果节点数为N，两种标准实现的时间复杂度要求都为O(N), 额外空间
复杂度要求都是O(h)，h为二叉树的高度
2.两种标准都要求逆时针顺序且不重复打印所有的边界节点。
【难度】尉
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